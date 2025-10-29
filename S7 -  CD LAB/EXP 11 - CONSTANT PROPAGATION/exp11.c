#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char var[MAX][MAX];
int val[MAX];
int n;
int constcnt=0;

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
    printf("x = a + b  or x = 5 _ _\n");
    for(int i=0;i<n;i++){
        printf("Statement %d:",i+1);
        scanf("%s = %s %c %s",c[i].lhs,c[i].op1,&c[i].op,c[i].op2);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<constcnt;j++){
            if(strcmp(c[i].op1,var[j])==0){
                sprintf(c[i].op1,"%d",val[j]);
            }
            if(strcmp(c[i].op2,var[j])==0){
                sprintf(c[i].op2,"%d",val[j]);
            }
        }
        if(!isalpha(c[i].op2[0])){    
            int v1=atoi(c[i].op1);
            int v2=(c[i].op2[0]!='_')?atoi(c[i].op2):0; 
            int result=0;
            switch(c[i].op){
                case '+':result=v1+v2; break;
                case '-':result=v1-v2; break;
                case '*':result=v1*v2; break;
                case '/':result=(v2!=0)?v1/v2:0; break;
                case '_':result=v1; break;
                default: continue; break; 
            }
            strcpy(var[constcnt],c[i].lhs);  
            val[constcnt++]=result;
            sprintf(c[i].op1,"%d",result);
            c[i].op='_';
            strcpy(c[i].op2,"_");
        }
    }
    
    printf("\nAfter Constant propagation:\n");
    for(int i=0;i<n;i++){
        printf("%s = %s ",c[i].lhs,c[i].op1);
        if(c[i].op!='_'){
            printf("%c %s",c[i].op,c[i].op2);
        }
        printf("\n");
    }

}
