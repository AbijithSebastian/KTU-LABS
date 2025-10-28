//EXP 4&5 - Epsilon closure 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

char states[MAX][3];
int scnt,tcnt;

struct Trans{
    char from[3];
    char sym;
    char to[3];
}t[MAX];

int contains(char s[],char closure[][3],int size){
    for(int i=0;i<size;i++){
        if(strcmp(closure[i],s)==0) return 1;
    }
    return 0;
}

void epsilonClosure(char s[],char closure[][3],int *size){
    if(!contains(s,closure,*size)){
        strcpy(closure[(*size)++],s);
    }
    for(int i=0;i<tcnt;i++){
        if(strcmp(t[i].from,s)==0 && t[i].sym=='e'){ //check
            epsilonClosure(t[i].to,closure,size);
        }
    }
}

void main(){
    printf("Enter no.of states:");
    scanf("%d",&scnt);
    printf("Enter states:\n");
    for(int i=0;i<scnt;i++){
        scanf("%s",states[i]);
    }
    printf("Enter no.of transitions:");
    scanf("%d",&tcnt);
    printf("Enter transitions:\n");
    for(int i=0;i<tcnt;i++){
        scanf("%s %c %s",t[i].from,&t[i].sym,t[i].to);
    }
    
    printf("\nEPSILON CLOSURES:\n");
    for(int i=0;i<scnt;i++){
        char closure[MAX][3];
        int size=0;
        epsilonClosure(states[i],closure,&size);
        printf("E-closure(%s)={ ",states[i]);
        for(int j=0;j<size;j++){
            printf("%s ",closure[j]);
        }
        printf("}\n");
    }
}