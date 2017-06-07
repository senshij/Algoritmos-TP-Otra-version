/**********
FILE date.h
***********/
#include <stdio.h>

status_t set_actual_date(struct tm *);
status_t print_time(struct tm, date_format_t, FILE *);
