// Тестовые хранимые процедуры

#include <time.h>
#include <string.h>
#include "postgres.h"
#include "fmgr.h"
#include "pgtime.h"
#include "utils/date.h"
#include "utils/datetime.h"
#include "executor/spi.h"       /* this is what you need to work with SPI */
#include "commands/trigger.h"   /* ... and triggers */

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(get_group_name);

char* get_request_result(int group_id, const char* request) {
  int ret = SPI_connect();
  if (ret < 0)
        elog(ERROR, "get_request_result: SPI_connect returned %d", ret);

  char buf[1024];
  sprintf(buf, request, group_id);

  ret = SPI_exec(buf, 10);

  if (ret < 0)
    elog(ERROR, "get_request_result: SPI_exec returned %d", ret);
  else
    elog(INFO, "get_request_result: SPI_exec succeeded");

  char *result = SPI_getvalue(SPI_tuptable->vals[0],
                                  SPI_tuptable->tupdesc,
                                  1);
  SPI_finish();  

  elog (INFO, "get_request_result: %s", result);
  return result;
}

char* get_request_semester(const char* date, const char* request) {
  int ret = SPI_connect();
  if (ret < 0)
        elog(ERROR, "get_request_semester: SPI_connect returned %d", ret);

  char buf[1024];
  sprintf(buf, request, date);

  ret = SPI_exec(buf, 10);

  if (ret < 0)
    elog(ERROR, "get_request_semester: SPI_exec returned %d", ret);
  else
    elog(INFO, "get_request_semester: SPI_exec succeeded");

  char *result = SPI_getvalue(SPI_tuptable->vals[0],
                                  SPI_tuptable->tupdesc,
                                  1);
  SPI_finish();  

  elog (INFO, "get_request_semester: %s", result);
  return result;
}

Datum get_group_name(PG_FUNCTION_ARGS) {
  
  int group_id = PG_GETARG_INT32(0);

  char buffer[20];
  char* faculty_name = get_request_result(group_id, "SELECT get_faculty_by_group_id(%d)");
  strcpy(buffer, faculty_name);
  char* date = get_request_result(group_id, "SELECT get_group_entering_date_by_id(%d)");
  char* semester = get_request_semester(date, "SELECT get_semester(date '%s')");
  strcat(buffer, semester);
  strcat(buffer, "-");
  char* department = get_request_result(group_id, "SELECT get_department_by_group_id(%d)");
  strcat(buffer, department);
  char* group_number = get_request_result(group_id, "SELECT get_group_number_by_id(%d)");
  strcat(buffer, group_number);
  
  int result_length = (int) strlen(buffer);
  char* string_result = (char*) malloc(result_length + 1);
  strcpy(string_result, buffer);
 
  text *result = 0;
  if (0 == string_result) {
    elog(ERROR, "get_group_name: SPI_getvalue returned null");
    result = (text *)palloc(VARHDRSZ);
    SET_VARSIZE(result, VARHDRSZ);
  } else {
    int len = strlen(string_result);
    result = (text *)palloc(VARHDRSZ + len);
    SET_VARSIZE(result, VARHDRSZ + len);
    memcpy(VARDATA(result), string_result, len);
    free(string_result);
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
  if (semester >= 10) 
    PG_RETURN_INT32(10); //считаем максимальное число семестров - 10. 

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
