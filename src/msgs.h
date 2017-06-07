/*****************
FILE msgs.h
****************/
#include <stdio.h>
#define MSG_ERROR_INVALID_DATA "El dato leído es inválido."
#define MSG_EOF "Fin de archivo."
#define MSG_ERROR_INVALID_ARGS "Los argumentos ingresados son inválidos."
#define MSG_ERROR_INVALID_NUMBER_ARGS "El número de argumentos ingresados es incorrecto."
#define MSG_ERROR_NULL_POINTER "Error del sistema."
#define MSG_ERROR_DATE "Error del sistema."
#define MSG_ERROR_PRINT_FORMAT "Error formato."

void print_error_message(status_t st);
