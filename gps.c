#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "config.h"
#include "errors.h"
#include "date.h"
#include "gps.h"

 
/******************Prototipos**************************/
status_t      _parse_field_time(char [], struct tm *);
/******************************************************/

/***************************************************************************
Función para el proceso de los datos cargados.
Lee una linea del flujo de entrada, si esta empieza con el 
encabezado de protocolo que contiene los datos de geolocalización
devuelve FOUND, extrae la hora y lo guarda en la estructura que recibe.
Sino devuelve NOT_FOUND.
***********************************************************************/

status_t parse_line(struct tm *time_struct){
    status_t st;
    char line[MAX_LINE];
    char field_time[FIELD_SPAN_TIME + 1];
    size_t i;

    if(time_struct == NULL)
        return ERROR_NULL_POINTER;
    if(fgets(line, MAX_LINE - 2 ,stdin) == NULL)
        return END_OF_FILE;
    if(!strncmp(line, ID_MSG, FIELD_SPAN_ID_MSG)){
        for(i = 0; i < FIELD_SPAN_TIME; i++){
            if (!isdigit(line[i + FIELD_POS_TIME]))
                return ERROR_READ_LINE;
            field_time[i] = line[i + FIELD_POS_TIME]; 
        }
        field_time[FIELD_SPAN_TIME + 1] = '\0'; 
        if((st  = _parse_field_time(field_time, time_struct)) != OK)
            return ERROR_INVALID_DATA;
        return FOUND;
    }
    return NOT_FOUND;
}
/***************************************************************************
Recibe una cadena de caracteres que contiene digitos,
verifica que corresponda al formato de horas hhmmss,
y si es asi lo guarda en la estructura que recibe.
*******************************************************************/
status_t _parse_field_time(char field[], struct tm *time_struct){     
    int aux;
    int value;

    value = atoi (field);
    aux = (value /10000);
    if(aux > 23)
        return ERROR;
    (*time_struct).tm_hour = aux;
    aux = (value%10000)/100;
    if(aux > 59)
        return ERROR;
    (*time_struct).tm_min = aux;
    aux = (value%100);
    if(aux > 59)
        return ERROR;
    (*time_struct).tm_sec = aux;

    return OK;
}   
