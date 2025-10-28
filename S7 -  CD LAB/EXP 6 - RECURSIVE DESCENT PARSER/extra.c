//EXP 6 - Extra Question S->cAd  A->ab|a
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int curr_idx=0,saved_idx=0;
char input[50];

bool S();
bool A();

bool match(char expected){
    if(input[curr_idx]==expected){
        curr_idx+=1;
        return true;
    }
    return false;
}

void backtrack(){
    curr_idx=saved_idx;
}

bool S(){
    if(match('c')){
        if(A()){
            if(match('d')) return true;
            return false;
        }
        return false;
    }
    return false;
}

bool A(){
    saved_idx=curr_idx;
    if(match('a')){
        if(match('b')) return true;
        //no need false here
    }
    backtrack();
    if(match('a')) return true;
    return false;
}


void main(){
    printf("Enter input:");
    scanf("%s",input);
    if(S() && strlen(input)==curr_idx){
        printf("valid expression\n");
    }
    else{
        printf("Invalid Expression\n");
    }
}