/*************
FILE process.c
*************/
#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "errors.h"
#include "date.h"
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

    while((st = parse_gps_line(&time_struct, &config)) != END_OF_FILE){
        if (st == ERROR_NULL_POINTER)
            return st;
        if(st == ERROR_READ_LINE || st == ERROR_INVALID_DATA)
            print_error_message(st);
        if(st == FOUND){
           if((st = add_date(&time_struct)) != OK){
               return st;
           }
           print_time(time_struct, config.format);
        }
        
    }
    return OK;
}
