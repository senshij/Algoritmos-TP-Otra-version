/************
 * FILE gps.h
 ***********/
#ifndef GPS__H
#define GPS__H

#include <stdio.h>
#include "types.h"

#define FIELD_SPAN_TIME 6
#define FIELD_POS_TIME 7
#define ID_MSG "$GPGGA"
#define FIELD_SPAN_ID_MSG 6
#define GPS_DELIMITER ","
#define MAX_GPS_LINE 200

status_t parse_gps_line(struct tm *, bool_t *, bool_t *);

#endif
