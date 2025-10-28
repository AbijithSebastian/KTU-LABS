%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(const char *s);
%}

%%
[0-9]+ {return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return IDENTIFIER;}
[+\-*/%] {return yytext[0];}
[\n] {return NEWLINE;}
. {yyerror("Invalid"); return 0;}
%%

int yywrap(){
	return 1;
}


