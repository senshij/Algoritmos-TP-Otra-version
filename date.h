#include <stdio.h>

status_t my_local_time(struct tm**);
status_t merge_time(struct tm, struct tm*);
void print_time(struct tm, format_t);
