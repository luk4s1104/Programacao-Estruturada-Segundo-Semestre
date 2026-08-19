#include<stdio.h>

int main(){
	
	char str[100];
	char *p;
	char *q;
	char temp;
	
	printf("Digite uma string:");
	fgets(str, 100, stdin);
	
	p = str; // o ponteiro esta na primeira posicao da string
	q = str; // o ponteiro esta na primeira posicao
	
	while(*q != '\0'){   // o ponteiro le a string ate o caractere nulo
		q++; 
	}
		
	q--; 
	
	while(p < q){   // enquanto p for menor que q
		temp = *p; // armazena o item do *p no temp
		*p = *q;   // o item do *q e copiado pro item no p
		*q = temp;   // coloca o caractere do temp em *q
		
		p++;
		q--;
	}
	
	
	printf("String invertida: %s", str);
	
	printf("\n");
	
	return 0;
}