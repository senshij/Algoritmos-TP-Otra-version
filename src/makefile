#**************
#FILE makefile
#**************

CC=gcc
CFLAGS=-ansi -pedantic -Wall -o3
all: gpsdateparser

gpsdateparser: main.o config.o dates.o errors.o gps.o gps_process.o
	$(CC) $(CFLAGS) -o gpsdateparser main.o config.o gps.o errors.o dates.o gps_process.o

main.o: main.c main.h config.h types.h dates.h errors.h gps_process.h
	$(CC) $(CFLAGS) -o main.o -c main.c

config.o: config.c config.h types.h
	$(CC) $(CFLAGS) -o config.o -c config.c

gps.o: gps.c gps.h types.h dates.h config.h
	$(CC) $(CFLAGS) -o gps.o -c gps.c

errors.o: errors.c errors.h types.h config.h
	$(CC) $(CFLAGS) -o errors.o -c errors.c

dates.o: dates.c dates.h config.h types.h
	$(CC) $(CFLAGS) -o dates.o -c dates.c

gps_process.o: gps_process.c gps_process.h gps.h types.h dates.h config.h errors.h
	$(CC) $(CFLAGS) -o gps_process.o -c gps_process.c

clean:
	rm -v *.o
