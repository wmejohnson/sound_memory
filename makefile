CC=gcc
OPTIONS=-g

all: memsound.c make_wav.c make_wav.h
	$(CC) $(OPTIONS) memsound.c make_wav.c -o memsound

clean:
	rm memsound make_wav 

