#include <stdio.h>
#include <time.h>
#include "types.h"
#include "config.h"
#include "errors.h"
#include "date.h"
#include "gps.h"
#include "process.h"

/************************************************************************************
Funcion principal del programa guarda la fecha del dia en una estructura
y procesa los datos cargados por el flujo de entrada.
Si encuentra una linea que contenga el encabezado de geolocalización, le extrae la hora 
y lo guarda en una estructura junto la fecha del dia. 
*************************************************************************************/


status_t process_gps_data(void){
    extern config_t config;
    status_t st;
    struct tm *time_struct;
    struct tm gps_time;

    if ((st = my_local_time(&time_struct)) != OK){
        print_error_message(st);
        return ERROR;
    }
    while((st = parse_line(&gps_time)) != END_OF_FILE){
        if(st == ERROR_READ_LINE)
            print_error_message(st);
        if(st == FOUND){
            merge_time(gps_time, time_struct);
            print_time(*time_struct, config.format);
        }
    }
    return OK;
}
