#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int curr_idx=0,saved_idx=0;
char input[50];

bool E();
bool Eprime();
bool T();
bool Tprime();
bool F();

bool match(char expected){
    if(input[curr_idx]==expected){
        curr_idx++;
        return true;
    }
    return false;
}

bool E(){
    if(T()){
        if(Eprime()) return true;
        return false;
    }
    return false;
}

bool Eprime(){
    if(match('+')){
        if(T()){
            if(Eprime()) return true;
            return false;
        }
        return false;
    }
    return true;
}

bool T(){
    if(F()){
        if(Tprime()) return true;
    }
    return false;
}

bool Tprime(){
    if(match('*')){
        if(F()){
            if(Tprime()) return true;
            return false;
        }
        return false;
    }
    return true;
}

bool F(){
    if(match('(')){
        if(E()){
            if(match(')')) return true;
        }
        return true;
    }
    else if(match('i')){
        return true;
    }
    return false;
}

void main(){
    printf("Enter input:");
    scanf("%s",input);
    if(E() && (strlen(input)==curr_idx)){
        printf("Valid Expression\n");
    }
    else{
        printf("Invalid Expression\n");
    }
}