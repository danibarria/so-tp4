#include <stdio.h>
/*recibe caracteres hasta que se escribe EOF*/
void recibe_caracteres(char *, int);
/*escribe hasta encontrar EOF*/
void escribe_caracteres(char *);
/*recibe caracteres hasta que se escribe EOF*/
void recibe_caracteres(char *buffer, int max_length){
    int count=0;
    char buff;
    while(((buff = getchar()) !=EOF)){
    	buffer[count] = buff; // lo que recibi por stdin
        buffer[count+1] = EOF;   // pongo fin de linea luego del caracter
        count++;    
    }
}
void escribe_caracteres(char *buffer){
    int count=0;
    while(buffer[count] != EOF){
        printf("%c", buffer[count]);
        count++;
    }
}