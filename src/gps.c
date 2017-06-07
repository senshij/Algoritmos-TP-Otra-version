/**********
FILE gps.c
**********/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "config.h"
#include "msgs.h"
#include "errors.h"
#include "dates.h"
#include "gps.h"

/******************Prototipos**************************/
status_t parse_field_time(long unsigned, struct tm *);
/******************************************************/

/**************************************************
Función para el proceso de los datos cargados.
Lee una linea del flujo de entrada,
si esta empieza con el encabezado de protocolo
que contiene los datos de geolocalización devuelve FOUND,
extrae la hora y lo guarda en la estructura que recibe.
Si no devuelve NOT_FOUND.
******************************************************/
status_t parse_gps_line(struct tm *time_struct, bool_t * found, bool_t * eof){
    status_t st;
    char * token;
    char ** remainder;
    char gps_line[MAX_GPS_LINE];
    long unsigned field_time_value;
    
    if(time_struct == NULL || eof == NULL || found == NULL)
        return ERROR_NULL_POINTER;
    if(fgets(gps_line, MAX_GPS_LINE - 2 ,stdin) == NULL){
        (*eof) = TRUE;
        return OK;
    }
    token = strtok(gps_line, DELIMITER);
    if (token ==NULL){
       (*found) = FALSE;  
       return OK;
    }
    if(strncmp(token, ID_MSG, FIELD_SPAN_ID_MSG)){
        (*found) = FALSE; 
          return OK;
    }
    token = strtok(NULL, DELIMITER);
    field_time_value = strtoul(token, remainder, 10);
    if(!(**remainder))
        return ERROR_INVALID_DATA;
    if((st = parse_field_time(field_time_value, time_struct)) != OK)
            return ERROR_INVALID_DATA;
    (*found) = TRUE;
    return OK;
}
/*****************************************************
Recibe una cadena de caracteres que contiene dígitos,
verifica que corresponda al formato de horas hhmmss,
y si es asi lo guarda en la estructura que recibe.
****************************************************/
status_t parse_field_time(long unsigned value, struct tm *time_struct){     
    long unsigned aux;
    
    aux = (value /10000);
    if(aux > 23)
        return ERROR_INVALID_DATA;
    time_struct ->tm_hour = aux;
    aux = (value%10000)/100;
    if(aux > 59)
        return ERROR_INVALID_DATA;
    time_struct->tm_min = aux;
    aux = (value%100);
    if(aux > 59)
        return ERROR_INVALID_DATA;
    time_struct->tm_sec = aux;
    return OK;
}   
/********************************************/
/********************************************/

   
   
   
  
   




