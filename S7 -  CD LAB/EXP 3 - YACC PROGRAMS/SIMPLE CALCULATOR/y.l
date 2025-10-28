%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(const char *s);
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}
[+\-*/%()] {return yytext[0];}
[\n] {return NEWLINE;}
. 	{}
%%

int yywrap(){
	return 1;
}


