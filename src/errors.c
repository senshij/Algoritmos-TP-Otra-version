/*************
FILE errors.c
************/


#include <stdio.h>
#include "types.h"
#include "config.h"
#include "msgs.h"
#include "errors.h"


void print_error_message(status_t st){
    switch(st){
	case ERROR_INVALID_ARGS:
	    fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ARGS);
	    break;
	case ERROR_INVALID_DATA:
	    fprintf(stderr, "%s\n", MSG_ERROR_INVALID_DATA);
	    break;
	case ERROR_NULL_POINTER:
	    fprintf(stderr, "%s\n", MSG_ERROR_NULL_POINTER);
	    break;
        case ERROR_INVALID_NUMBER_ARGS:
            fprintf(stderr, "%s\n", MSG_ERROR_INVALID_NUMBER_ARGS);
	    break;
        case ERROR_DATE:
            fprintf(stderr, "%s\n", MSG_ERROR_DATE);
	    break;
        case ERROR_PRINT_FORMAT:
            fprintf(stderr, "%s\n", MSG_ERROR_PRINT_FORMAT);
	    break;
        
        default:
            ;
    } /* switch */
} 
