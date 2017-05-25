#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "date.h"

/****************************************************
Guarda en una estructura la fecha y hora de la maquina.
Lo asigna a un puntero a estructura pasado por puntero.
**********************************************/
status_t my_local_time(struct tm ** time_struct){
    time_t temp;
    if (time(&temp) == -1){	/* Se compara con -1 porque así está definido en el estándar ANSI C '89 */
        return ERROR;
    }   
    (*time_struct) = localtime(&temp);
    return OK;
}


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
