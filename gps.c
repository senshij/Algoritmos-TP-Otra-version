#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "config.h"
#include "errors.h"
#include "date.h"
#include "gps.h"


#define FIELD_SPAN_TIME 6
#define FIELD_POS_TIME 7
#define MAX_LINE 100
#define ID_MSG "$GPGGA"
#define FIELD_SPAN_ID_MSG 6
 
/******************Prototipos**************************/
status_t                     _parse_line(struct tm *);
status_t      _parse_field_time(char [], struct tm *);
/******************************************************/

status_t process_gps_data(void){
    extern config_t config;
    status_t st;
    time_t machine_time;
    struct tm *time_struct;
    struct tm gps_time;
    if (time(&machine_time) == -1){	/* Se compara con -1 porque así está definido en el estándar ANSI C '89 */
        print_error_message(ERROR_MACHINE_TIME);
        return EXIT_FAILURE;
    }   
    time_struct = localtime(&machine_time);
    while((st = _parse_line(&gps_time)) != END_OF_FILE){
        if(st == ERROR_READ_LINE)
            print_error_message(st);
        if(st == FOUND){
            merge_time(gps_time, time_struct);
            print_time(*time_struct, config.format);
        }
    }
    return OK;
}


status_t _parse_line(struct tm *time_struct){
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

status_t _parse_field_time(char field[], struct tm *time_struct){     
    int aux;
    int value;

    value = atoi (field);
    aux = (value /10000);
    if(aux > 23)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_hour = aux;
    aux = (value%10000)/100;
    if(aux > 59)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_min = aux;
    aux = (value%100);
    if(aux > 59)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_sec = aux;

    return OK;
}   
