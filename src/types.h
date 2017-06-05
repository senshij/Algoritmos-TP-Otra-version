/*************
FILE types.h
*************/
#include <stdio.h>

typedef enum{
    OK,
    FOUND,
    NOT_FOUND,
    END_OF_FILE,
    ERROR_INVALID_ARGS,
    ERROR_INVALID_NUMBER_ARGS,
    ERROR_EOF,
    ERROR_READ_LINE,
    ERROR_INVALID_DATA,
    ERROR_NULL_POINTER,
    ERROR,
    ERROR_DATE
} status_t;

typedef enum{
    DATE_AAAAMMDDHHMMSS_FORMAT,
    DATE_AAAADDDHHMMSS_FORMAT
} format_t;
