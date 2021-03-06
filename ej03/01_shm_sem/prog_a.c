#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* Constantes de modo */
#include <fcntl.h>           /* Constantes O_* */
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include "utils.h"
#define MAX_CHAR 51

int main(){
    int shm_fd,count = 0;
	char *data;
    char buff;
    sem_t *semaforo;
    //shared memory
	shm_fd = shm_open("/compartida", O_RDWR | O_CREAT, 0777);
	ftruncate(shm_fd, sizeof(char)*MAX_CHAR);
	data = mmap(NULL, sizeof(char)*MAX_CHAR, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);/*pedi memoria para 50 char y \0*/
    //semaphores
    if((semaforo = sem_open("/mutex", O_CREAT, 0700, 1)) == SEM_FAILED){
        perror("sem_open(semaforo)"); //creacion defensiva del semaforo
    }
    sem_wait(semaforo); 
    recibe_caracteres(data,MAX_CHAR);
    sem_post(semaforo);
    // sem_close(semaforo);
}