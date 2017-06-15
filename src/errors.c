/*************
FILE errors.c
************/

#include <stdio.h>
#include "types.h"
#include "errors.h"


void print_error_message(status_t st){
    char *errors[] = {
    OK,
    MSG_ERROR_PRINT_FORMAT,
    MSG_ERROR_INVALID_ARGS,
    MSG_ERROR_INVALID_NUMBER_ARGS,
    MSG_ERROR_INVALID_DATA	
    MSG_ERROR_NULL_POINTER,
    MSG_ERROR_SET_DATE
    };

    fprintf(stderr, "%s\n", errors[st]);
}


