#include "types.h"
#include "config.h"
#include "errors.h"
#define MSG_ERROR_INVALID_DATA "El dato leído es inválido."
#define MSG_ERROR_EOF "Fin de archivo."
#define MSG_ERROR_INVALID_ARGS "Los argumentos ingresados son inválidos."
#define MSG_ERROR_INVALID_NUMBER_ARGS "El número de argumentos ingresados es incorrecto."
#define MSG_ERROR_NULL_POINTER "Error del sistema."



void print_error_message(status_t st){
    switch(st){
	case ERROR_INVALID_ARGS:
	    fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ARGS);
	    break;
	case ERROR_EOF:
	    fprintf(stderr, "%s\n", MSG_ERROR_EOF);
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
        default:
            ;
    } /* switch */
} 
