%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char str[100];
int yylex();
void yyerror(const char *s);

int isPalindrome(char *s){
	int len=strlen(s);
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]) return 0;
	}
	return 1;
}
%}
%token STRING NEWLINE
%%
input : STRING NEWLINE {if(isPalindrome(str)){printf("Palindrome\n");}else{printf("Not palindrome\n");}exit(0);}
      ;
%%

void yyerror(char const *s){
	printf("Error:%s\n",s);
}

void main(){
	printf("Enter string:");
	yyparse();
}




