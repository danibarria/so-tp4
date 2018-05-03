CC=gcc
all: servidor cliente
cliente: cliente.o comunicaciones.o hardware.o
	$(CC) -o cliente cliente.o comunicaciones.o hardware.o
servidor: servidor.o comunicaciones.o hardware.o
	$(CC) -o servidor servidor.o comunicaciones.o hardware.o 
cliente.o: cliente.c cliente.h interfaz.h comunicaciones.h
	$(CC) -c cliente.c
servidor.o: servidor.c servidor.h interfaz.h comunicaciones.h
	$(CC) -c servidor.c
comunicaciones.o: comunicaciones.h comunicaciones.c hardware.h
	$(CC) -c comunicaciones.c
hardware.o: hardware.h hardware.c
	$(CC) -c hardware.c
clean:
	rm -rf *.o