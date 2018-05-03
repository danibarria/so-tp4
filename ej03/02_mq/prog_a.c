#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include "utils.h"

#define MAX_CHAR 51

int main(){
    mqd_t mq;
    char buff;
    char data[MAX_CHAR];
    int count =0;

    mq = mq_open("/mqecho", O_WRONLY |  O_CREAT );//solo escribe
    recibe_caracteres(data,MAX_CHAR);
    mq_send(mq, data, MAX_CHAR,0); //envia el mensaje
}