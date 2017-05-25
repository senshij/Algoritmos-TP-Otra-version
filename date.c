#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "date.h"

status_t merge_time(struct tm input_time, struct tm *actual_time){
    if(actual_time == NULL)
	return ERROR_NULL_POINTER;
    (*actual_time).tm_hour = input_time.tm_hour;
    (*actual_time).tm_min  = input_time.tm_min;
    (*actual_time).tm_sec  = input_time.tm_sec;
    return OK;
}


void print_time(struct tm time, format_t format){
    switch(format){
        case GREGORIAN_FORMAT:
            printf("%i%02i%02i%02i%02i%02i\n",\
		   1900+time.tm_year,\
		   1+time.tm_mon,\
		   time.tm_mday,\
		   time.tm_hour,\
		   time.tm_min,\
		   time.tm_sec\
		  );
	    break;
	case JULIAN_FORMAT:
	    printf("%i%03i%02i%02i%02i\n",\
		   1900+time.tm_year,\
		   1+time.tm_yday,\
		   time.tm_hour,\
		   time.tm_min,\
		   time.tm_sec\
		  );
	    break;
    } /* switch */
}
