CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: ej1 ej2 ej3

ej1: ej1.c
	$(CC) $(CFLAGS) -o ej1 ej1.c

ej2: ej2.c
	$(CC) $(CFLAGS) -o ej2 ej2.c

ej3: ej3.c
	$(CC) $(CFLAGS) -o ej3 ej3.c

clean:
	rm -f ej1 ej2 ej3
