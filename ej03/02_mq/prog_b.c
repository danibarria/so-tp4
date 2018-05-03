#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include "utils.h"

#define MAX_SIZE 51

int main(){
    mqd_t mq;
    struct mq_attr atributos;
    char buffer[MAX_SIZE+1];
    //atributos
    atributos.mq_flags=0;
    atributos.mq_maxmsg=10;
    atributos.mq_msgsize=MAX_SIZE;
    atributos.mq_curmsgs=0;

    mq= mq_open("/mqecho", O_CREAT | O_RDONLY, 0700, &atributos);//solo lee
    ssize_t leido;
    leido = mq_receive(mq,buffer,MAX_SIZE,0);
    escribe_caracteres(buffer);
    // mq_close(mq);
}