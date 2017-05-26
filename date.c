#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "date.h"


/*****************prototipos*****************/
status_t _get_date(struct tm **);
/********************************************/


status_t add_date(struct tm *time_struct){
    struct tm * aux;
    status_t st;

    if ((st = _get_date(&aux)) != OK){
        return ERROR_DATE;
    }
    if(time_struct == NULL)
	return ERROR_NULL_POINTER;
    (*time_struct).tm_year = (*aux).tm_year;
    (*time_struct).tm_mon  = (*aux).tm_mon;
    (*time_struct).tm_mday  = (*aux).tm_mday;
    (*time_struct).tm_yday  = (*aux).tm_yday;
    return OK;
}

/****************************************************
Guarda en una estructura la fecha y hora de la maquina.
Lo asigna a un puntero a estructura pasado por puntero.
**********************************************/
status_t _get_date(struct tm ** aux){
    time_t temp;

    if (time(&temp) == -1){	/* Se compara con -1 porque así está definido en el estándar ANSI C '89 */
        return ERROR;
    }   
    (*aux) = localtime(&temp);
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
