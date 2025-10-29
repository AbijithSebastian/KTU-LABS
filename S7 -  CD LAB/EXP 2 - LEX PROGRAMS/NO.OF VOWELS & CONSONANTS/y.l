%{
#include <stdio.h>
int v=0,c=0;
%}

%%
[aeiouAEIOU] {v++;}
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] {c++;}
[\n] {} 
%%

void main(){
	yyin=fopen("data.txt","r");
	yylex();
	printf("vowels:%d\n",v);
	printf("consonants:%d\n",c);
}

int yywrap(){
	return 1;
}
