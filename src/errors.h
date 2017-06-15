/************
 * FILE errors.h
 ************/
#ifndef ERRORS__H
#define ERRORS__H

#include <stdio.h>
#define MSG_ERROR_INVALID_DATA "El dato leído es inválido."
#define MSG_ERROR_INVALID_ARGS "Los argumentos ingresados son inválidos."
#define MSG_ERROR_INVALID_NUMBER_ARGS "El número de argumentos ingresados es incorrecto."
#define MSG_ERROR_NULL_POINTER "Error del sistema."
#define MSG_ERROR_SET_DATE "No se pudo leer fecha local."
#define MSG_ERROR_PRINT_FORMAT "No se pudo realizar el proceso de formato."

void print_error_message(status_t st);

#endif
