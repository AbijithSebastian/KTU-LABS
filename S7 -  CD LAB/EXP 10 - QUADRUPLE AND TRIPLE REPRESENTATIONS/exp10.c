#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50
#define MAX 10


char lhs;
char infix[LEN];
char postfix[LEN];
char stack[MAX];
char tacStack[MAX][MAX];

int top=-1;
int tcnt=0;
int qcnt=-1;

struct Quad{
    char op;
    char arg1[MAX];
    char arg2[MAX];
    char res[MAX];
}q[MAX];


int validExpression(char *expr){
    int balance=0;
    int len=strlen(expr);
    if(len==0) return 0;
    for(int i=0;i<len;i++){
        char curr=expr[i];
        char prev=(i>0)?expr[i-1]:'\0';
        if(!isalpha(curr) && curr!='+' && curr!='-' && curr!='*' && curr!='/' && curr!='^' && curr!='(' && curr!=')'){
            return 0;
        }
        if(strchr("+-*/^",curr)){
            if(i==0) return 0;
            if(strchr("+-*/^(",prev)) return 0;
        }
        if(isalnum(curr)){
            if(i>0 && (isalnum(prev) || prev==')')) return 0;
        }
        if(curr=='('){
            balance++;
            if(i>0 && (isalnum(prev) || prev==')')) return 0;
        }
        if(curr==')'){
            balance--;
            if(i>0 && (strchr("+-*/^(",prev))) return 0;
        }
        if(balance<0) return 0;
    }
    if(balance!=0) return 0;
    if(strchr("+-*/^(",expr[len-1])) return 0;
    return 1;
}

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

void infixtopostfix(){
    int k=0;
    top=-1;
    for(int i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isalpha(c)){
            postfix[k++]=c;
        }
        else if(c=='('){
            stack[++top]=c;
        }
        else if(c==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[k++]=stack[top--];
            }
            top--;
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(c)){
                postfix[k++]=stack[top--];
            }
            stack[++top]=c;
        }
    }
    while(top!=-1){
        postfix[k++]=stack[top--];
    }
    postfix[k]='\0';
}

void generateTAC(){
    printf("\nTHREE ADDRESS CODE:\n");
    top=-1;
    for(int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isalpha(c)){
            char temp[2]={c,'\0'};
            strcpy(tacStack[++top],temp);
        }
        else{
            char a[MAX],b[MAX],t[MAX];
            strcpy(b,tacStack[top--]);
            strcpy(a,tacStack[top]);
            sprintf(t,"t%d",++tcnt);
            printf("%s = %s %c %s\n",t,a,c,b);
            strcpy(tacStack[top],t);
            
            q[++qcnt].op=c;
            strcpy(q[qcnt].arg1,a);
            strcpy(q[qcnt].arg2,b);
            strcpy(q[qcnt].res,t);
        }
    }
    printf("%c = %s\n",lhs,tacStack[0]);
    q[++qcnt].op='=';
    strcpy(q[qcnt].arg1,tacStack[0]);
    strcpy(q[qcnt].arg2,"-");
    sprintf(q[qcnt].res,"%c",lhs);
}

void printQuadruples(){
    printf("\nQUADRUPLE REPRESENTATION:\n");
    printf("No\top\targ1\targ2\tres\n");
    for(int i=0;i<=qcnt;i++){
        printf("[%d]\t%c\t%s\t%s\t%s\n",i,q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
    
}

void printTriples(){
    printf("\nTRIPLE REPRESENTATION:\n");
    printf("No\top\targ1\targ2\n");
    for(int i=0;i<=qcnt;i++){
        printf("[%d]\t%c\t",i,q[i].op);
        if(q[i].arg1[0]=='t'){
            printf("[%d]\t",atoi(q[i].arg1+1)-1);
        }
        else{
            printf("%s\t",q[i].arg1);
        }
        if(q[i].arg2[0]=='t'){
            printf("[%d]\n",atoi(q[i].arg2+1)-1);
        }
        else{
            printf("%s\n",q[i].arg2);
        }
    }
    
}

void main(){
    printf("Enter the expression(eg:a=b*c+d):");
    scanf("%s",infix);
    if(strlen(infix)<3 || infix[1]!='='){
        printf("Invalid Expression\n");
        return;
    }
    lhs=infix[0];
    strcpy(infix,infix+2);
    if(!validExpression(infix)){
        printf("Invalid Expression\n");
        return;
    }
    infixtopostfix();
    printf("Postfix Expression:%s\n",postfix);
    generateTAC();
    printQuadruples();
    printTriples();
}