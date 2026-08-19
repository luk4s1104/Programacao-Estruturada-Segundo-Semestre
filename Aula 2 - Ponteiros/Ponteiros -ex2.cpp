	#include<stdio.h>
	#include<stdlib.h>
	
	int main(){
		
		char str[100];
		char aux[100];
		char *p;
		char *q;
		
		printf("Digite uma string:");
		fgets(str, 100, stdin);
		
		p = str; // o ponteiro esta na primeira posicao da string
		
		while(*p != '\0'){   // o ponteiro le a string ate o caractere nulo
			p++; 
		}
		
		q = aux;   // o ponteiro esta na primeira posicao da string
		
		p--; 
		
		while(p >= str){  // p esta lendo a string de tras pra frente 
			*q = *p;    // copia pro q
			q++;
			p--;
		}
		
		
		printf("String invertida: %s", aux);
		
		printf("\n");
		
		return 0;
	}