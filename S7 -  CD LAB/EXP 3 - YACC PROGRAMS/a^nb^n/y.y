%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}
%token A B NEWLINE
%%
input:S NEWLINE {printf("Valid string in the form a^nb^n\n");exit(0);}
	   ;
S: 'A' S 'B'
 | 'A''B'
 ;
%%

void yyerror(const char *s){
	printf("Invalid String\n");
}

void main(){
	printf("Enter string:");
	yyparse();
}


