%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
char str[100];
void yyerror(const char *s);
%}
%%
[a-zA-Z]+ {strcpy(str,yytext); return STRING;}
[\n] {return NEWLINE;}
. ;
%%

int yywrap(){
	return 1;
}


