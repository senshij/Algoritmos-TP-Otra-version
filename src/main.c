/************
 * FILE main.c
 ***********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "types.h"
#include "config.h"
#include "errors.h"
#include "process.h"

/***************Prototipos******************************/
status_t validate_args(int argc, char *argv[], config_t *);
/*******************************************************/


extern config_t config;


int main(int argc, char *argv[]){
    
    status_t st;

    if((st=(validate_args(argc,argv, &config))) != OK){
        print_error_message(st);
        return EXIT_FAILURE;
    } 
    if((st = process_gps_data()) != OK){
        print_error_message(st);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


/*********************************************************
Función para validar argumentos ingresados por línea 
de comandos. Valida el número de argumentos ingresados
y que sean correctos, luego guarda lo ingresado en
una estructura de configuración.
**********************************************************/
status_t validate_args(int argc, char *argv[], config_t *config){
    if(argv == NULL || config == NULL)
	return ERROR_NULL_POINTER;
    if(argc != NUMBER_ARGS)
	return ERROR_INVALID_NUMBER_ARGS;
    if(strncmp(argv[FMT_FLAG_POSITION], FMT_FLAG, FMT_FLAG_SPAN))
	return ERROR_INVALID_ARGS;
    if(!strncmp(argv[FMT_TYPE_POSITION], DATE_FMT_AAAAMMDDHHMMSS, DATE_FMT_AAAAMMDDHHMMSS_SPAN)){
	config->date_format = DATE_AAAAMMDDHHMMSS_FORMAT;
	return OK;
    }
    if(!strncmp(argv[FMT_TYPE_POSITION], DATE_FMT_AAAADDDHHMMSS, DATE_FMT_AAAADDDHHMMSS_SPAN)){
	config->date_format = DATE_AAAADDDHHMMSS_FORMAT;
	return OK;
    }
    return ERROR_INVALID_ARGS;
}
