%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char str[100];
int yylex();
void yyerror(const char *s);
int validParenthesis(char *s){
	int top=-1;
	char stack[100];
	for(int i=0;s[i]!='\0';i++){
		char curr=s[i];
		if(curr=='(' || curr=='{' || curr=='['){
			stack[++top]=curr;
		}
		else if(curr==')' || curr=='}' || curr==']'){
			if(top==-1) return 0;
			char prev=stack[top--];
			if((curr==')' && prev!='(') || (curr=='}' && prev!='{') || (curr==']' && prev!='[') ) return 0;
		}
	}
	return (top==-1);
}
%}
%token PAREN NEWLINE
%%
input : PAREN NEWLINE {if(validParenthesis(str)){printf("Balanced\n");}else{printf("Not Balanced\n");}exit(0);}
      ;
%%
void yyerror(char const *s){ printf("Error:%s\n",s); }
void main(){
	printf("Enter string:");
	yyparse();
}









