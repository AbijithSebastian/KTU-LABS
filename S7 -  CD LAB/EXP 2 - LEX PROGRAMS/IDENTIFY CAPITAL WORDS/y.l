%{
#include <stdio.h>
#include <stdlib.h> 
%}

%%
[A-Z]+[" "|\t|\n] {printf("%s\n",yytext); exit(0);}
. ;
%%

void main(){
	printf("Enter input string:");
	yylex();
}

int yywrap(){
	return 1;
}
