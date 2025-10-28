%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}
%token NUMBER INVALID NEWLINE;
%%
input:NUMBER NEWLINE{printf("valid number\n");exit(0);}
     |INVALID NEWLINE {yyerror("Invalid number"); exit(0);}
     ;
%%

void yyerror(const char *s){
	printf("Invalid number\n");
}

void main(){
	printf("Enter number:");
	yyparse();
}
