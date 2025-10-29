#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char nonterminals[MAX];
char productions[MAX][MAX];

int n;
int ntcnt=0;

void add(char res[],char c){
    if(!strchr(res,c)){
        int len=strlen(res);
        res[len]=c;
        res[len+1]='\0';
    }
}

void findFirst(char res[],char c){
    if(!isupper(c)){
        add(res,c);
        return;
    }
    for(int i=0;i<n;i++){
        if(productions[i][0]==c){ 
            int j=3;
            int eflag=1;
            while(productions[i][j] && eflag){
                char temp[MAX]="";
                findFirst(temp,productions[i][j]);
                for(int k=0;temp[k]!='\0';k++){
                    if(temp[k]!='#') add(res,temp[k]);
                }
                eflag=strchr(temp,'#')!=NULL;
                j++;
            }
            if(eflag) add(res,'#');
        }
    }
}

void findFollow(char res[],char c){
    if(productions[0][0]==c){
        add(res,'$');
    }
    for(int i=0;i<n;i++){
        for(int j=3;productions[i][j]!='\0';j++){
            if(productions[i][j]==c){ 
                int k=j+1;
                int eflag=1;
                while(productions[i][k] && eflag){
                    char temp[MAX]="";
                    findFirst(temp,productions[i][k]);  
                    for(int m=0;temp[m]!='\0';m++){
                        if(temp[m]!='#') add(res,temp[m]);
                    }
                    eflag=strchr(temp,'#')!=NULL;
                    k++;
                }
                
                if(eflag && productions[i][0]!=c){
                    char temp[MAX]="";
                    findFollow(temp,productions[i][0]); 
                    for(int m=0;temp[m]!='\0';m++){
                        add(res,temp[m]);          
                    }
                }
            }
        }
    }
}

void main(){
    printf("Enter no.of productions:");
    scanf("%d",&n);
    getchar();
    printf("Enter the productions:\n");
    for(int i=0;i<n;i++){
        printf("Production %d:",i+1);
        scanf("%s",productions[i]);
        if(!strchr(nonterminals,productions[i][0])){
            nonterminals[ntcnt++]=productions[i][0];
        }
    }
    printf("\nFIRST SET:\n");
    for(int i=0;i<ntcnt;i++){
        char res[MAX]="";
        findFirst(res,nonterminals[i]);
        printf("FIRST(%c)={",nonterminals[i]);
        for(int j=0;res[j]!='\0';j++){
            printf(" %c",res[j]);
        }
        printf("}\n");
    }
    printf("\nFOLLOW SET:\n");
    for(int i=0;i<ntcnt;i++){
        char res[MAX]="";
        findFollow(res,nonterminals[i]);
        printf("FOLLOW(%c)={",nonterminals[i]);
        for(int j=0;res[j]!='\0';j++){
            printf(" %c",res[j]);
        }
        printf("}\n");
    }

}
