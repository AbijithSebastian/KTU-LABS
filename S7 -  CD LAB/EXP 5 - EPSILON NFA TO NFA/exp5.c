//EXP 5 - E-NFA to NFA
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
        if(strcmp(t[i].from,s)==0 && t[i].sym=='e'){ 
            epsilonClosure(t[i].to,closure,size);
        }
    }
}

void getClosureMoves(char closure[][3],int size,char sym,char result[][3],int *rsize){
    for(int i=0;i<size;i++){  
        for(int j=0;j<tcnt;j++){  
            if(strcmp(t[j].from,closure[i])==0 && t[j].sym==sym){
                char temp[MAX][3];
                int tsize=0;
                epsilonClosure(t[j].to,temp,&tsize);
                for(int k=0;k<tsize;k++){
                    if(!contains(temp[k],result,*rsize)){
                        strcpy(result[(*rsize)++],temp[k]);
                    }
                }
            }
        }
    }
}

void convert(){ //imp
    char symbols[MAX]="";
    int symcnt=0;
    for(int i=0;i<tcnt;i++){
        if(t[i].sym!='e' && strchr(symbols,t[i].sym)==NULL){  
            symbols[symcnt++]=t[i].sym;
            symbols[symcnt]='\0';
        }
    }
    printf("\nNFA transitions:\n");
    for(int i=0;i<scnt;i++){   
        char closure[MAX][3];
        int size=0;
        epsilonClosure(states[i],closure,&size);
        
        for(int j=0;j<symcnt;j++){  
            char result[MAX][3];
            int rsize=0;
            getClosureMoves(closure,size,symbols[j],result,&rsize);
            printf("%s--%c-->{ ",states[i],symbols[j]);
            for(int k=0;k<rsize;k++){
                printf("%s ",result[k]);
            }
            printf("}\n");
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
    
    convert(); 

}
