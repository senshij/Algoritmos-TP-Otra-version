/************
 * FILE types.h
 ***********/
#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>

typedef enum{
    FALSE,
    TRUE
} bool_t;

typedef enum{
    OK,
    ERROR_PRINT_FORMAT,
    ERROR_INVALID_ARGS,
    ERROR_INVALID_NUMBER_ARGS,
    ERROR_INVALID_DATA,
    ERROR_NULL_POINTER,
    ERROR_SET_DATE
} status_t;

typedef enum{
    DATE_AAAAMMDDHHMMSS_FORMAT,
    DATE_AAAADDDHHMMSS_FORMAT
} date_format_t;

#endif
