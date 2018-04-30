CC=gcc
all: servidor
servidor: servidor.o comunicaciones.o hardware.o
	$(CC) -o servidor servidor.o comunicaciones.o hardware.o
cliente: cliente.c cliente.h
	$(CC) -c cliente.c
comunicaciones.o: comunicaciones.h comunicaciones.c hardware.c
	$(CC) -c comunicaciones.c
hardware.o: hardware.h hardware.c
	$(CC) -c hardware.c
servidor.o: servidor.c servidor.h interfaz.h
	$(CC) -c servidor.c
clean:
	rm -rf *.o