#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "utils.h"

#define ARCHIVO_PIPE "Pipe"
#define MAX_SIZE 51


int main(void){
	int fd;
	char buffer[51];
	int leidos;

	
	//Abrir el pipe para lectura-escritura
	if ( (fd=open(ARCHIVO_PIPE,O_RDWR)) <0) {
		perror("Error open");
		exit(-1);
	}

	//leer del pipe
	leidos=read(fd,buffer,51);

	// printf("\nMensaje recibido: %s\n", buffer);
    escribe_caracteres(buffer);
	close(fd);
	
	return 0;
}