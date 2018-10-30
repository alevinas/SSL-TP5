%{
#include <stdio.h>
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"

void mostrarError(char *id, int e);
extern int errlex; 	/* Contador de Errores Léxicos */
char *error_inicio[] = {"Error semantico: identificador ", "Error semantico: identificador "};
char *error_fin[] = {" ya declarado", " NO declarado"};
int errsem = 0;
%}


%define api.value.type{char *}


%defines "parser.h"
%output "parser.c"
%start program /* El no terminal que es AXIOMA de la gramatica del TP2 */
%define parse.error verbose /* Mas detalles cuando el Parser encuentre un error en vez de "Syntax Error" */

%token PROGRAMA FIN VARIABLES CODIGO DEFINIR LEER ESCRIBIR CONSTANTE IDENTIFICADOR
%token ASIGNACION "<-"

%left  '-'  '+'
%left  '*'  '/'
%precedence NEG

%%

program : 		  				PROGRAMA {iniciar();} bloquePrograma FIN {detener(); if (errlex+yynerrs+errsem > 0) YYABORT;else YYACCEPT;};

bloquePrograma : 	  		variables_ code;

variables_ : 		  			VARIABLES
                        | variables_ DEFINIR IDENTIFICADOR'.'{if(!existe($3)){
                                                                declarar($3);
                                                                agregar($3);
                                                                }
                                                              else{mostrarError($3,0);}}
												| variables_ DEFINIR error'.';

code : 			  					CODIGO sentencia
                        | code sentencia;

sentencia : 		  			LEER '(' listaIdentificadores')' '.'
                        | ESCRIBIR '('listaExpresiones')' '.'
                        | identificador "<-" expresion '.'		  {guardar($3,$1);}
												| error'.';

listaIdentificadores : 	identificador                           {leer($1);}
                        | identificador',' listaIdentificadores {leer($1);};

listaExpresiones : 	  	expresion                        {escribir($1);}
                        | expresion',' listaExpresiones  {escribir($1);};

expresion : 		  			valor                     {$$=$1;}
                        | '-'valor %prec NEG			{$$ = invertir($2);}
                        | '('expresion')' 				{$$ = $2;}
                        | expresion '+' expresion {$$ = sumar($1, $3);}
                        | expresion '-' expresion {$$ = restar($1, $3);}
                        | expresion '*' expresion {$$ = multiplicar($1, $3);}
                        | expresion '/' expresion {$$ = dividir($1, $3);}
												| '(' error ')';

valor : 		  					identificador
                        | CONSTANTE;

identificador :         IDENTIFICADOR {if(!existe($1)){mostrarError($1,1); YYERROR;}else $$ = $1;};
%%

/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}
void mostrarError(char *id, int e){
	char *buffer = malloc(strlen(error_inicio[e])+strlen(error_fin[e]) + strlen(id) + 1);
	sprintf(buffer, "%s%s%s", error_inicio[e], id,error_fin[e]);
	yyerror(buffer);
	errsem++;
	free(buffer);
}
