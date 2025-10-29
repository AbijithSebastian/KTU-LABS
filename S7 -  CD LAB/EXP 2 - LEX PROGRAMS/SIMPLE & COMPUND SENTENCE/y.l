%{
#include <stdio.h>
#include <stdlib.h>
int flag=0;
%}

%%
(and|or|but|if|because|then|nevertheless) {flag=1;}
. ;
\n {return 0;}
%%

void main(){
	printf("Enter the sentence:");
	yylex();
	if(flag==0){
		printf("Simple sentence\n");
	}
	else{
		printf("Compound sentence\n");
	}
}

int yywrap(){
	return 1;
}

