CC=gcc
CFLAGS=-ansi -pedantic -Wall -o2
all: gpsdateparser

gpsdateparser: main.o config.o date.o errors.o gps.o
	$(CC) $(CFLAGS) -o gpsdateparser main.o config.o gps.o errors.o date.o

main.o: main.c config.h types.h errors.h date.h gps.h  
	$(CC) $(CFLAGS) -o main.o -c main.c

config.o: config.c config.h types.h
	$(CC) $(CFLAGS) -o config.o -c config.c

gps.o: gps.c gps.h types.h date.h config.h
	$(CC) $(CFLAGS) -o gps.o -c gps.c

errors.o: errors.c errors.h types.h config.h
	$(CC) $(CFLAGS) -o errors.o -c errors.c

date.o: date.c date.h config.h types.h
	$(CC) $(CFLAGS) -o date.o -c date.c
