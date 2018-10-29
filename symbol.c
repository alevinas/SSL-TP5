#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct tablaSimbolos {
	char *buffer[200];
	int indice;
}diccionario  =  {.indice = 0};

void agregar(char *variable ){
  diccionario.buffer[diccionario.indice]=variable;
  diccionario.indice++;
}

bool existe(char *variable){

  for(int i=0; i<diccionario.indice; i++){

    if(strcmp(diccionario.buffer[i], variable) == 0 )
      return true ;
  }
  return false;
}
