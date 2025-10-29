%{
#include <stdio.h>
#include <stdlib.h>
int u=0,l=0,cnt=0,d=0,o=0;
%}

%%
[A-Z] {cnt++;u++;}
[a-z] {cnt++;l++;}
[0-9] {cnt++;d++;}
[\n] {}
. {cnt++;o++;}
%%

void main(){
	yyin=fopen("data.txt","r");
	yylex();
	if(cnt<=8 && u>=1 && l>=1 && d>=1 && o==0){
		printf("Valid password\n");
	}
	else{
		printf("Invalid password\n");
	}
}

int yywrap(){ return 1;}

/* INVALID OUTPUTS -aaaaaaaa,AAaswcSS,233sf332,wdnwq280dj,dcnen#dw */
