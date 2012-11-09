#include "postgres.h"
#include "fmgr.h"
#include "utils/date.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(get_semester);

Datum
get_semester(PG_FUNCTION_ARGS) {
    DateADT date = PG_GETARG_ABSOLUTE(0);
    errmsg("test %i");
    PG_RETURN_INT32(date);
}

