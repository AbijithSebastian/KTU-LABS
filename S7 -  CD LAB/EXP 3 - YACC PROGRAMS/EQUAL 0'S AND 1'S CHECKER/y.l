%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
char str[100];
void yyerror(const char *s);
%}
%%
[01]+ {strcpy(str,yytext); return BINARY;}
[\n] {return NEWLINE;}
. ;
%%

int yywrap(){
	return 1;
}


