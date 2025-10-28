%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(const char *s);
%}
%%
[0-9]+(\.[0-9]+)? {return NUMBER;}
[\n] {return NEWLINE;}
. {return INVALID;}
%%

int yywrap(){
	return 1;
}
