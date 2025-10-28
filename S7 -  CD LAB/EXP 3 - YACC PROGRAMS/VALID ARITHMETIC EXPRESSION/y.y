%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}
%token NUMBER IDENTIFIER NEWLINE;
%left '+''-'
%left '*''/''%'
%nonassoc UMINUS
%%
input:expr NEWLINE{printf("Valid expression\n"); exit(0);}
		 ;
expr : expr '+' expr
     | expr '-' expr
     | expr '*' expr
     | expr '/' expr
     | expr '%' expr
     | '-' expr %prec UMINUS
     | '(' expr ')'
     | NUMBER
     | IDENTIFIER
     ;
%%

void yyerror(const char *s){
	printf("invalid expression\n");
}

void main(){
	printf("Enter expression:");
	yyparse();
}


