#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tablaSimbolos {
	char *buffer[200];
	int indice;
}diccionario  =  {.indice = 0};

void agregar(char *variable ){
  diccionario.buffer[diccionario.indice]=variable;
  diccionario.indice++;
}

int existe(char *variable){

  for(int i=0; i<diccionario.indice; i++){

    if(strcmp(diccionario.buffer[i], variable) == 0 )
      return 1;
  }
  return 0;
}
