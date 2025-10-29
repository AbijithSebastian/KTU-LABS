%{
#include <stdio.h>
#include <stdlib.h>
char str[100];
%}

%%
[a-zA-Z]+ { strcpy(str,yytext);
						int len=strlen(str);
						int flag=1;
						for(int i=0;i<len/2;i++){
							if(str[i]!=str[len-1-i]){
								flag=0;
								break;
							}
						}
						if(flag==1){printf("Palindrome\n");}
						else{ printf("Not palindrome\n");}
						exit(0);
					}
. ;
%%

void main(){
	printf("Enter the string:");
	yylex();
}

int yywrap(){ return 1;}

