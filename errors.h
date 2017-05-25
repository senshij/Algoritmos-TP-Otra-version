#include <stdio.h>
#define MSG_ERROR_INVALID_DATA "El dato leído es inválido."
#define MSG_ERROR_EOF "Fin de archivo."
#define MSG_ERROR_INVALID_ARGS "Los argumentos ingresados son inválidos."
#define MSG_ERROR_INVALID_NUMBER_ARGS "El número de argumentos ingresados es incorrecto."
#define MSG_ERROR_NULL_POINTER "Error del sistema."

void print_error_message(status_t st);
