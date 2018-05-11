#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utils.h"

#define ARCHIVO_PIPE "Pipe"
#define MAX_CHAR 51

int main(int argc, char *argv[]){
	int fd;
    char data[MAX_CHAR];

	mkfifo(ARCHIVO_PIPE,0666);

	//Intentar abrir para escritura el pipe con nombre
	if( (fd=open(ARCHIVO_PIPE,O_WRONLY)) <0) {
		perror("\nError en open");
		exit(-1);
	}
    //utils 
    recibe_caracteres(data,MAX_CHAR);    
	//Escribir en el pipe el mensaje
	if( (write(fd,data,strlen(data)+1)) != strlen(data)+1) {
		perror("\nError al escribir en el FIFO");
		exit(-1);
	}

	close(fd);
	return 0;
}