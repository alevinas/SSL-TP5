#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"

int errsem = 0;
int temporales;
const int id_max = 8;

void declarar(char *id){
	printf("Declare %s, Integer\n", id);
}

char* proxTemporal(){
	char nuevoTemporal[id_max];
	temporales++;
	sprintf(nuevoTemporal, "Temp#%d", temporales);
	declarar(nuevoTemporal);
	return strdup(nuevoTemporal);
}

void leer(char *id){
	printf("Read %s, Integer\n", id);
}
void escribir(char *id){
	printf("Write %s, Integer\n", id);
}
char* invertir(char *idEntrada){
  	char *idSalida;
	idSalida = proxTemporal();
	printf("INV %s,,%s\n", idEntrada, idSalida);
	return idSalida;
}
char* multiplicar(char *idEntrada1, char *idEntrada2){
	char *idSalida;
	idSalida = proxTemporal();
	printf("MULT %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}
char* sumar(char *idEntrada1, char *idEntrada2){
	char *idSalida;
	idSalida = proxTemporal();
	printf("ADD %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}
char* restar(char *idEntrada1, char *idEntrada2){
	char *idSalida;
	idSalida = proxTemporal();
	printf("SUBS %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}

char* dividir(char *idEntrada1, char *idEntrada2){
	char *idSalida;
	idSalida = proxTemporal();
	printf("DIV %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}

void guardar(char *idEntrada, char *idSalida){
	printf("STORE %s en %s \n", idEntrada, idSalida);
}

void iniciar(){
	printf("Load rtlib,\n");
}
void detener(){
	printf("Stop,\n");
}
