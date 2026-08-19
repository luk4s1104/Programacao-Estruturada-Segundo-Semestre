#include<stdio.h>

int main(){
	
	char str[100];
	char *p;
	char letra;
	int encontrou = 0, cont = 0;
	
	printf("Digite uma String: ");
	fgets(str, 100, stdin);
	
	printf("\nDigite o caractere que deseja encontrar:");
	scanf("%c", &letra);
	
	p = str;
	
	while(*p != '\0'){
				
		if(*p == letra){
			encontrou = 1;
			cont++; 
		}
		p++;
	}
	
	if(encontrou == 1){
		printf("\nO caractere %c foi encontrado %i vez(es)", letra, cont);
	}	
	else{
		printf("\nO caractere %c nao foi encontrado", letra);
	}
	
	return 0;
}