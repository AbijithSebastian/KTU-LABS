%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}
%token IDENTIFIER INVALID NEWLINE
%%
input:IDENTIFIER NEWLINE {printf("Valid identifier\n"); exit(0);}
     |INVALID NEWLINE {printf("Invalid identifier\n"); exit(0);}
     ;
%%

void yyerror(const char *c){
	printf("Invalid\n");
}

void main(){
	printf("Enter identifier:");
	yyparse();
}


