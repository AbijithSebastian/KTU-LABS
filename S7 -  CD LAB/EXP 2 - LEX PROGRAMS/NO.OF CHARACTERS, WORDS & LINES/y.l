%{
#include <stdio.h>
int c=0,w=0,l=0;
%}

%%
[a-zA-Z] {c++;}
[" "] {w++;}
[\n] {l++;w++;}
%%

void main(){
	yyin=fopen("data.txt","r");
	yylex();
	printf("characters:%d\n",c);
	printf("words:%d\n",w);
	printf("lines:%d\n",l);
}

int yywrap(){
	return 1;
}
