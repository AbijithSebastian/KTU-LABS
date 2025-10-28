#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fp1,*fp2;

void clear(char str[50]){
	for(int i=0;i<50;i++){
			str[i]=0;
	}
}

int findSymbolTable(char result[]){
	char lexeme[50],token[20];
	fseek(fp2,0,SEEK_SET);
	do{
		if(feof(fp2)){
			return 0;
		}
		fscanf(fp2,"%s %s",lexeme,token);
		if(strcmp(lexeme,result)==0){
			if(strcmp(token,"identifier")==0){
				printf("%s - identifier\n",result);
			}
			else{
				printf("%s - %s\n",result,token);
			}
			return 1;
		}
	}while(1);
}

void main(){
	char c,result[50];
	int state=0,i=0,k=0;
	fp1=fopen("input.txt","r");
	fp2=fopen("symtab.txt","a+");
	do{
		if(feof(fp1)){
			break;
		}
		c=fgetc(fp1);
		
		switch(state){
			case 0: if(c=='#'){
								result[i++]=c;
								state=1;
							}
							else if(isalpha(c)){
								result[i++]=c;
								state=2;
							}
							else if(isdigit(c)){
								result[i++]=c;
								state=3;
							}
							else if( c=='+' || c=='-' || c=='*' || c=='/'){
								printf("%c - arithmetic operator\n",c);
							}
							else if(strchr("{}():;,",c)){
								printf("%c - separator\n",c);
							}
							else if(c=='<' || c=='>' || c=='!' || c=='='){
								result[i++]=c;
								state=4;
							}
							break;
			case 1:if(c!='\n'){
						 		result[i++]=c;
						 		state=1;
						 }
						 else{
						    result[i]='\0';
						 		printf("%s - preprocessor directive\n",result);
						 		clear(result);
						 		i=0;
						 		state=0;
						 }
						 break;
			case 2:if(isalpha(c) || isalnum(c)){
						 		result[i++]=c;
						 		state=2;
						 }
						 else{
						 		result[i]='\0';
						 		k=findSymbolTable(result);
						 		if(k==0){
						 			printf("%s - identifier\n",result);
						 			fprintf(fp2,"%s identifier\n",result);
						 		}
						 		clear(result);
						 		i=0;
						 		state=0;
						 		ungetc(c,fp1); 
						 }
						 break;
			case 3:if(isdigit(c)){
								result[i++]=c;
								state=3;
						 }
						 else{
						 		result[i]='\0';
						 		printf("%s - number\n",result);
						 		clear(result);
						 		i=0;
						 		state=0;
						 }
						 break;
			case 4:if(c=='='){
						 		result[i++]=c;
						 		result[i]='\0';
						 		printf("%s - relational operator\n",result);
						 		clear(result);
						 		i=0;
						 		state=0;
						 }
						 else{
						 		result[i]='\0';
						 		if(strcmp(result,"=")==0){
						 			printf("%s - assignment operator\n",result);
						 		}
						 		else{
						 			printf("%s - relational operator\n",result);
						 		}
						 		clear(result);
						 		i=0;
						 		state=0;
						 		ungetc(c,fp1);
						 }
		}
	}while(1);
}
