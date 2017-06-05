/*********
FILE gps.h
**********/
#include <stdio.h>
#include "common.h"
#define FIELD_SPAN_TIME 6
#define FIELD_POS_TIME 7
#define ID_MSG "$GPGGA"
#define FIELD_SPAN_ID_MSG 6

status_t parse_gps_line(struct tm *, config_t *);
