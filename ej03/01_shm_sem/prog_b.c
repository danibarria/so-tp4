#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* Constantes de modo */
#include <fcntl.h>           /* Constantes O_* */
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include "utils.h"

#define MAX_CHAR 51
// sem_t mutex;
int main(void){
	int shm_fd, count = 0;
	char *data;
    sem_t *semaforo;
    ///share memory
	shm_fd = shm_open("/compartida", O_RDWR | O_CREAT, 0777);
	ftruncate(shm_fd, sizeof(char)*MAX_CHAR);
	data = mmap(NULL, sizeof(char)*MAX_CHAR, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	///semaphores
    if((semaforo = sem_open("/mutex", O_CREAT, 0700, 1)) == SEM_FAILED){
        perror("sem_open(semaforo)");//crecion defensiva de semaforo
    }
    sem_wait(semaforo); 
    escribe_caracteres(data); //utils.h
    sem_post(semaforo); 
    // sem_close(semaforo);
}
