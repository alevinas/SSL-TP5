//////////////////////////////////////////////////////////////////////////////////////
/*
      TP4 - 2018
      "Compilador"
      Grupo 03

     Ordóñez Julián Mateo
      160.297.4
     Torres Schulten Manuel
      160.688.8
     Viegas Manuel
      150.205.0
     Viñas Alejandro Fabian
      160.613.0
                                                                                    */
//////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "parser.h"
#include "scanner.h"
#include "semantic.h"

extern int errsem;
extern int yynerrs;

int main() {
	switch( yyparse() ){
	case 0:
		puts("Compilacion terminada con exito"); printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semanticos: %d\n",yynerrs,errlex,errsem); return 0;
	case 1:
		puts("Errores de compilación");	printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semanticos: %d\n",yynerrs,errlex,errsem); return 1;
	case 2:
		puts("Memoria insuficiente"); return 2;
	}
	return 0;
}
