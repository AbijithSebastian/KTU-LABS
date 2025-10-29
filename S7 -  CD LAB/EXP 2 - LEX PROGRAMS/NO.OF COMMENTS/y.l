%{
#include <stdio.h>
#include <stdlib.h>
int c=0;
%}

%%
"/*"[a-zA-Z0-9 \t\n]*"*/"  {c++;}
"//"[a-zA-Z0-9 \t]*"//" {c++;}
[\t\n] {}
. ;
%%

void main(){
	yyin=fopen("data.txt","r");
	yylex();
	printf("No.of comments=%d\n",c);
}

int yywrap(){
	return 1;
}
