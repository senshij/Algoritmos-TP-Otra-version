/************
 * FILE dates.h
 ***********/
#ifndef DATES__H
#define DATES__H

#include <stdio.h>
#define DATE_FMT_AAAAMMDDHHMMSS "AAAAMMDDHHmmSS"
#define DATE_FMT_AAAADDDHHMMSS "AAAADDDHHmmSS"
#define DATE_FMT_AAAAMMDDHHMMSS_SPAN 14
#define DATE_FMT_AAAADDDHHMMSS_SPAN 13

status_t set_actual_date(struct tm *);
status_t print_time(struct tm *, date_format_t, FILE *);

#endif
