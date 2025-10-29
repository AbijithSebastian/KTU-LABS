#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char input[MAX];
char stack[MAX];
char productions[MAX][MAX];

int n;
int top=-1;
int iptr=0;
int tcnt=6;

char terminals[6]={'+','*','i','(',')','$'};
char precedenceTable[6][6]={
    {'>','<','<','<','>','>'},
    {'>','>','<','<','>','>'},
    {'>','>','e','e','>','>'},
    {'<','<','<','<','=','e'},
    {'>','>','>','e','>','>'},
    {'<','<','<','<','<','A'},
};

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

char topTerminals(){
    for(int i=top;i>=0;i--){
        for(int j=0;j<tcnt;j++){
            if(stack[i]==terminals[j]){
                return stack[i];
            }
        }
    }
    return '$';
}

int getIndex(char c){
    for(int i=0;i<tcnt;i++){
        if(terminals[i]==c){
            return i;
        }
    }
    return -1;
}

char getPrecedence(char stackT,char c){
    int i=getIndex(stackT);
    int j=getIndex(c);
    return precedenceTable[i][j];
}

void printStep(char *inputptr,char action[]){
    printf("STACK:");
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
    printf("\t\tINPUT:%s\t\tACTION:%s\n",inputptr,action);
}

int reduce(){
    for(int i=0;i<n;i++){
        int len=strlen(productions[i]+3);
        if(len<=top+1){
            int flag=1;
            for(int j=0;j<len;j++){
                if(stack[top-len+1+j]!=productions[i][j+3]){ 
                    flag=0;
                    break;
                }
            }
            if(flag){
                for(int j=0;j<len;j++){
                    pop();
                }
                push(productions[i][0]); 
                char action[MAX];
                sprintf(action,"Reduce %s",productions[i]);
                printStep(input+iptr,action);
                return 1;
            }
        }
    }
    return 0;
}

void parse(char input[]){
    push('$');
    char c=input[iptr];
    while(1){
        char stackT=topTerminals();
        char prec=getPrecedence(stackT,c);
        if(prec=='A'){
            printStep(input+iptr,"Accepted");
            return;
        }
        else if(prec=='<' || prec=='='){
            push(c);
            iptr++;
            c=input[iptr];
            printStep(input+iptr,"Shift");
        }
        else if(prec=='>'){
            if(!reduce()){
                printf("Error:Can't reduce\nInvalid expression\n");
                return;
            }
        }
        else{
            printf("Invalid Expression\n");
        }
    }
}

void main(){
    printf("Enter no.of productions:");
    scanf("%d",&n);
    printf("Enter the productions:\n");
    for(int i=0;i<n;i++){
        printf("Production %d:",i+1);
        scanf("%s",productions[i]);
    }
    printf("Enter the input(end with $):");
    scanf("%s",input);
    parse(input);
}

