#**************
#FILE makefile
#**************

CC=gcc
CFLAGS=-ansi -pedantic -Wall -o3
all: gpsdateparser

gpsdateparser: main.o config.o dates.o errors.o gps.o process.o
	$(CC) $(CFLAGS) -o gpsdateparser main.o config.o gps.o errors.o dates.o process.o

main.o: main.c main.h config.h types.h errors.h process.h 
	$(CC) $(CFLAGS) -o main.o -c main.c

config.o: config.c config.h types.h
	$(CC) $(CFLAGS) -o config.o -c config.c

gps.o: gps.c gps.h types.h dates.h config.h common.h
	$(CC) $(CFLAGS) -o gps.o -c gps.c

errors.o: errors.c errors.h types.h config.h
	$(CC) $(CFLAGS) -o errors.o -c errors.c

dates.o: dates.c dates.h config.h types.h
	$(CC) $(CFLAGS) -o dates.o -c dates.c

process.o: process.c gps.h types.h dates.h config.h process.h errors.h common.h
	$(CC) $(CFLAGS) -o process.o -c process.c

clean:
	rm *.o
