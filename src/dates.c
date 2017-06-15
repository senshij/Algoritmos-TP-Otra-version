/************
 * FILE dates.c
 ************/
#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "dates.h"

/********Prototipos********/
status_t print_date_aaaammdd(struct tm *, FILE *);
status_t print_date_aaaaddd(struct tm *, FILE *);
/**************************/

/********************************************
 * Función agregar fecha, guarda en la estructura
 * que recibe por puntero la fecha del dia.
 ********************************************/
status_t set_actual_date(struct tm *time_struct){
    struct tm *aux;
    time_t temp;
    status_t st;

    if(time_struct == NULL)
	return ERROR_NULL_POINTER;

    if (time(&temp) == -1) 
        return ERROR_SET_DATE;      
    aux = localtime(&temp);
    time_struct->tm_year = aux->tm_year;
    time_struct->tm_mon  = aux->tm_mon;
    time_struct->tm_mday = aux->tm_mday;
    time_struct->tm_yday = aux->tm_yday;	
    return OK;
}

/*****************************************
Función para imprimir fechas y horas cargadas 
en estructuras de tipo struct tm. 
Recibe una estructura tm por copia
y el formato en el cual imprimirla.
****************************************/
status_t print_time(struct tm * time, date_format_t format, FILE * fo){
    if(time == NULL || fo == NULL)
        return ERROR_NULL_POINTER;
    switch(format){
        case DATE_AAAAMMDDHHMMSS_FORMAT:
	    return print_date_aaaammdd(time, fo);
	    break;
	case DATE_AAAADDDHHMMSS_FORMAT:
	    return print_date_aaaaddd(time, fo);
	    break;

        default:
            return ERROR_PRINT_FORMAT;
    } /* switch */
}

status_t print_date_aaaammdd(struct tm * time, FILE * fo){
    if(time == NULL || fo == NULL)
	    return ERROR_NULL_POINTER;
    fprintf(fo, "%i%02i%02i%02i%02i%02i\n",\
                1900 + time->tm_year,\
		1 + time->tm_mon,\
		time->tm_mday,\
		time->tm_hour,\
		time->tm_min,\
		time->tm_sec\
	   );
    return OK;
}
status_t print_date_aaaaddd(struct tm * time, FILE * fo){
    if(time == NULL || fo == NULL)
	    return ERROR_NULL_POINTER;
    fprintf(fo, "%i%03i%02i%02i%02i\n",\
		1900 + time->tm_year,\
		1+time->tm_yday,\
		time->tm_hour,\
		time->tm_min,\
		time->tm_sec\
	   );
    return OK;
}
