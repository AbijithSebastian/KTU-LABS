%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(const char *s);
%}
%%
a {return 'A';}
b {return 'B';}
\n {return NEWLINE;}
. {yyerror("Invalid"); return 0;}
%%

int yywrap(){
	return 1;
}


