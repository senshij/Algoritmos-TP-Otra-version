/************
 * FILE config.h
 ************/
#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include "types.h"
#define OUTPUT_STREAM stdout

typedef struct{
    date_format_t date_format;
} config_t;

#endif
