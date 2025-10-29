%{
#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9_]*@[a-zA-Z0-9_]+\.[A-Za-z]{2,3}   { printf("Valid email\n"); exit(0); }
.+  { printf("Invalid email\n"); exit(0); }
\n  {}                                               
%%

int main(void) {
    printf("Enter email: ");
    yylex();
    return 0;
}

int yywrap(void) {
    return 1;
}



