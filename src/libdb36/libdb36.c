// Тестовые хранимые процедуры

#include <time.h>

#include "postgres.h"
#include "fmgr.h"
#include "pgtime.h"
#include "utils/date.h"
#include "utils/datetime.h"
#include "executor/spi.h"       /* this is what you need to work with SPI */
#include "commands/trigger.h"   /* ... and triggers */

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(get_group_name);

Datum get_group_name(PG_FUNCTION_ARGS) {
  
  int group_id = PG_GETARG_INT32(0);

  int ret = SPI_connect();
  if (ret < 0)
        elog(ERROR, "get_group_name: SPI_connect returned %d", ret);

  char buf[1024];
  sprintf(buf, "SELECT get_group_name_by_id(%d)", group_id);
  elog (INFO, "get_group_name: %s", buf);

  ret = SPI_exec(buf, 10);

  if (ret < 0)
    elog(ERROR, "get_group_name: SPI_exec returned %d", ret);
  else
    elog(INFO, "get_group_name: SPI_exec succeeded");

  char *group_name = SPI_getvalue(SPI_tuptable->vals[0],
                                  SPI_tuptable->tupdesc,
                                  1);
  SPI_finish();  

  elog (INFO, "get_group_name: %s", group_name);

  text *result = 0;
  if (0 == group_name) {
    elog(ERROR, "get_group_name: SPI_getvalue returned null");
    result = (text *)palloc(VARHDRSZ);
    SET_VARSIZE(result, VARHDRSZ);
  } else {
    int len = strlen(group_name);
    result = (text *)palloc(VARHDRSZ + len);
    SET_VARSIZE(result, VARHDRSZ + len);
    memcpy(VARDATA(result), group_name, len);
  }

  PG_RETURN_TEXT_P(result);
}

PG_FUNCTION_INFO_V1(get_semester);

typedef struct pg_tm pg_tm;
Datum get_semester(PG_FUNCTION_ARGS) {
  pg_tm current_date;
  GetCurrentDateTime(&current_date);

  DateADT entering_date = DatumGetDateADT(PG_GETARG_DATUM(0));

  int entering_year, entering_month, entering_day;
  j2date(entering_date + date2j(2000, 1, 1), &entering_year, &entering_month, &entering_day);

  int semester = (current_date.tm_year - entering_year) * 2;
  if (current_date.tm_mon > 6)
    semester++;
  
  PG_RETURN_INT32(semester);
}

PG_FUNCTION_INFO_V1(trigf);

Datum
trigf(PG_FUNCTION_ARGS)
{
    TriggerData *trigdata = (TriggerData *) fcinfo->context;
    TupleDesc   tupdesc;
    HeapTuple   rettuple;
    char       *when;
    bool        checknull = false;
    bool        isnull;
    int         ret, i;

    /* make sure it's called as a trigger at all */
    if (!CALLED_AS_TRIGGER(fcinfo))
        elog(ERROR, "trigf: not called by trigger manager");

    /* tuple to return to executor */
    if (TRIGGER_FIRED_BY_UPDATE(trigdata->tg_event))
        rettuple = trigdata->tg_newtuple;
    else
        rettuple = trigdata->tg_trigtuple;

    /* check for null values */
    if (!TRIGGER_FIRED_BY_DELETE(trigdata->tg_event)
        && TRIGGER_FIRED_BEFORE(trigdata->tg_event))
        checknull = true;

    if (TRIGGER_FIRED_BEFORE(trigdata->tg_event))
        when = "before";
    else
        when = "after ";

    tupdesc = trigdata->tg_relation->rd_att;

    /* connect to SPI manager */
    if ((ret = SPI_connect()) < 0)
        elog(ERROR, "trigf (fired %s): SPI_connect returned %d", when, ret);

    /* get number of rows in table */
    ret = SPI_exec("SELECT count(*) FROM ttest", 0);

    if (ret < 0)
        elog(ERROR, "trigf (fired %s): SPI_exec returned %d", when, ret);

    /* count(*) returns int8, so be careful to convert */
    i = DatumGetInt64(SPI_getbinval(SPI_tuptable->vals[0],
                                    SPI_tuptable->tupdesc,
                                    1,
                                    &isnull));

    elog (INFO, "trigf (fired %s): there are %d rows in ttest", when, i);

    SPI_finish();

    if (checknull)
    {
        SPI_getbinval(rettuple, tupdesc, 1, &isnull);
        if (isnull)
            rettuple = NULL;
    }

    return PointerGetDatum(rettuple);
}
