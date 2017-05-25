#include <stdio.h>
#define FIELD_SPAN_TIME 6
#define FIELD_POS_TIME 7
#define MAX_LINE 100
#define ID_MSG "$GPGGA"
#define FIELD_SPAN_ID_MSG 6

status_t process_gps_data(void);
