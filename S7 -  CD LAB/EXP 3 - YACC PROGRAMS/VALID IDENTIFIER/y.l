%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(const char *s);
%}

%%
[a-zA-Z][a-zA-Z0-9]+ {return IDENTIFIER;}
[\n] {return NEWLINE;}
. {return INVALID;}
%%

int yywrap(){
	return 1;
}


