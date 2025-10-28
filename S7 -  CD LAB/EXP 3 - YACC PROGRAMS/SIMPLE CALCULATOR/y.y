%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}
%token NUMBER NEWLINE
%left '+''-'
%left '*''/''%'
%nonassoc UMINUS
%%
input:expr	{printf("result:%d\n",$1);exit(0);}
		 ;
expr : expr '+' expr {$$=$1+$3;}
		 | expr '-' expr {$$=$1-$3;}
		 | expr '*' expr {$$=$1*$3;}
		 | expr '/' expr {if($3==0){yyerror("division by zero"); exit(0);}$$=$1/$3;}
		 | expr '%' expr {if($3==0){yyerror("division by zero"); exit(0);}$$=$1%$3;}
		 | '-' expr %prec UMINUS {$$=-$1;}
		 | '(' expr ')' {$$=$2;}
		 | NUMBER {$$=$1;}
		 ;
%%

void yyerror(const char *s){
	printf("Error:%s\n",s);
}

void main(){
	printf("Simple calculator:\nEnter input:");
	yyparse();
}


