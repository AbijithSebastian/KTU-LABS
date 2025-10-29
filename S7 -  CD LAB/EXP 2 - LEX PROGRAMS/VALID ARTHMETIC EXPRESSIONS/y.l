%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i=0,o=0,k,flag=0;  //i-no.of identifiers ,o- no.of operators
char id[10][10],op[10][10];
%}

%%
[0-9]+ {flag++; strcpy(id[i],yytext); i++;}
["+"|"-"|"*"|"/"] {flag--; strcpy(op[o],yytext); o++;}
.|\n  {return 0;}
%%

void main(){
	printf("Enter expression:");  //2+3 flag=1
	yylex();
	if(flag!=1){
		printf("Invalid Expression\n");
	}
	else{
		printf("Valid expression\n");
		printf("Identifiers are:\n");
		for(k=0;k<i;k++){
			printf("%s ",id[k]);
		}
		printf("\nOperators are:\n");
		for(k=0;k<o;k++){
			printf("%s ",op[k]);
		}
		printf("\n");
	}
}

int yywrap(){
	return 1;
}
