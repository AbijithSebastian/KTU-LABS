%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char str[100];
int z=0,o=0;
int yylex();
void yyerror(const char *s);

int isEqual(char *s){
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='0') z++;
		else if(s[i]=='1') o++;
		else return 0;
	}
	return (z==o);
}
%}
%token BINARY NEWLINE
%%
input : BINARY NEWLINE {if(isEqual(str)){printf("Equal no.of 0's & 1's\n");}else{printf("Not Equal\n");}exit(0);}
      ;
%%

void yyerror(char const *s){
	printf("Error:%s\n",s);
}

void main(){
	printf("Enter string:");
	yyparse();
}




