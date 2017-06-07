/************
FILE date.c
************/
#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "dates.h"

/*****************prototipos*****************/
status_t get_date(struct tm **);
/********************************************/

/******************************************
Función agregar fecha, guarda en la estructura 
que recibe por puntero la fecha del dia.
******************************************/
status_t set_actual_date(struct tm *time_struct){
    struct tm * aux;
    status_t st;

    if ((st = get_date(&aux)) != OK){
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

/******************************************
Guarda en una estructura pasada por puntero
la fecha y hora del dia
****************************************/
status_t get_date(struct tm ** aux){
    time_t temp;

    if (time(&temp) == -1) 
        return ERROR_DATE;      
    (*aux) = localtime(&temp);
    return OK;
}

/*****************************************
Función para imprimir fechas y horas cargadas 
en estructuras de tipo struct tm. 
Recibe una estructura tm por copia
y el formato en el cual imprimirla.
****************************************/
status_t print_time(struct tm time, date_format_t format, FILE * fo){
    switch(format){
        case DATE_AAAAMMDDHHMMSS_FORMAT:
            fprintf(fo,"%i%02i%02i%02i%02i%02i\n",\
		   1900+time.tm_year,\
		   1+time.tm_mon,\
		   time.tm_mday,\
		   time.tm_hour,\
		   time.tm_min,\
		   time.tm_sec\
		  );
            return OK;
	    break;
       
	case DATE_AAAADDDHHMMSS_FORMAT:
	    fprintf(fo,"%i%03i%02i%02i%02i\n",\
		   1900+time.tm_year,\
		   1+time.tm_yday,\
		   time.tm_hour,\
		   time.tm_min,\
		   time.tm_sec\
		  );
            return OK;
	    break;

        default:
            return ERROR_PRINT_FORMAT;
    } /* switch */
}
