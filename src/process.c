/*************
FILE process.c
*************/
#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "msgs.h"
#include "errors.h"
#include "dates.h"
#include "gps.h"
#include "process.h"

extern config_t config;
/************************************************************************************
Funcion principal, lee los datos cargados por el flujo de entrada y
si encuentra una linea que contenga el encabezado de geolocalización, le extrae la hora 
lo guarda en una estructura, y luego le agrega la fecha del dia. 
*************************************************************************************/
status_t process_gps_data(void){
    status_t st;
    struct tm time_struct;
    bool_t eof;
    bool_t found_geo_data;
    FILE* fo = OUTPUT_STREAM;
    eof = FALSE;
    while(eof == FALSE){
        st = parse_gps_line(&time_struct, &found_geo_data, &eof);
        if (st == ERROR_NULL_POINTER)
            return ERROR_NULL_POINTER;
        if(st == ERROR_INVALID_DATA)
            print_error_message(st);
        if(found_geo_data == TRUE){
           if((st = set_actual_date(&time_struct)) != OK){
               return st;
           }
           if ((st = print_time(time_struct, config.date_format, fo)) != OK)
               return st;
        }
    }
    return OK;
}
