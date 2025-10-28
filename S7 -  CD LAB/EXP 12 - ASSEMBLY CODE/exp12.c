#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char reg[MAX];
int n;

struct Code{
    char lhs[MAX];
    char op1[MAX];
    char op;
    char op2[MAX];
}c[MAX];

void main(){
    printf("Enter the no.of statements:");
    scanf("%d",&n);
    printf("Enter the statements in 3AC format:\n");
    printf("x= a + b or x = 5 _ _\n");
    for(int i=0;i<n;i++){
        printf("Statement %d:",i+1);
        scanf("%s = %s %c %s",c[i].lhs,c[i].op1,&c[i].op,c[i].op2);
    }
    printf("\nASSEMBLY CODE:\n");
    for(int i=0;i<n;i++){
        sprintf(reg,"R%d",i);
        if(c[i].op=='_'){
            printf("MOV %s, %s\n",reg,c[i].op1);
        }
        else{
            printf("MOV %s, %s\n",reg,c[i].op1);
            switch(c[i].op){
                case '+':printf("ADD %s, %s\n",reg,c[i].op2); break;
                case '-':printf("SUB %s, %s\n",reg,c[i].op2); break;
                case '*':printf("MUL %s, %s\n",reg,c[i].op2); break;
                case '/':printf("DIV %s, %s\n",reg,c[i].op2); break;
                default: printf("invalid\n"); break;
            }
        }
        printf("MOV %s, %s\n",c[i].lhs,reg);
    }
}