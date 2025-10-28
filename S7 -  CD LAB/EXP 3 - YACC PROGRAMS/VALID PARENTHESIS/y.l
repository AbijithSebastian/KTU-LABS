%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
char str[100];
void yyerror(const char *s);
%}
%%
[()\[\]{}]+ {strcpy(str,yytext); return PAREN;}
[\n] {return NEWLINE;}
. ;
%%

int yywrap(){
	return 1;
}


