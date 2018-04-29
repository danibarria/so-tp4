CC=gcc
CFLAGS=-Wall -g
all: servidor cliente.h cliente.c
	$(CC) cliente.c -o cliente
servidor: servidor.o comunicaciones.o hardware.o 
	$(CC) -o servidor servidor.o comunicaciones.o hardware.o
comunicaciones.o: comunicaciones.h comunicaciones.c hardware.c
	$(CC) -c comunicaciones.c -o comunicaciones.o
hardware.o: hardware.h hardware.c
	$(CC) -c hardware.c -o hardware.o
servidor.o: servidor.c servidor.h interfaz.h
	$(CC) -c servidor.c -o servidor.o
clean:
	rm -rf *.o