%{
#include <stdio.h>
%}

%%
"main"|"void"|"int"|"float"|"char" {printf("keyword-%s\n",yytext);}
#[a-zA-Z<>.]+ {printf("preprocessor-%s\n",yytext);}
[0-9]+ {printf("number-%s\n",yytext);}
[a-zA-Z][a-zA-Z0-9_]* {printf("identifier-%s\n",yytext);}
["+"|"-"|"*"|"/"|"%"|"="] {printf("operator-%s\n",yytext);}
["<"|"<="|">"|">="|"!="|"=="] {printf("relational operator-%s\n",yytext);}
["{"|"}"|"("|")"|":"|";"|","] {printf("separator-%s\n",yytext);}
[\n|\t] {}
%%

int main(){
	yyin=fopen("data.txt","r");
	yylex();
}

int yywrap(){
	return 1;
}


