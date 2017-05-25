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
    ERROR_MACHINE_TIME
} status_t;

typedef enum{
    GREGORIAN_FORMAT,
    JULIAN_FORMAT
} format_t;
