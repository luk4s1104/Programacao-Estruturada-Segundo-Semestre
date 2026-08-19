#include <stdio.h>
#include <ctype.h>

int main(){

char str[100];
char aux[100];
char *p;
char *q;

	printf("Digite uma string: ");
	fgets(str, 100, stdin);

	p = str;

	while(*p != '\0'){
    p++;
	}

	p--;

	if(*p == '\n'){
    p--;
	}

	q = aux;

	while(p >= str){

    	if(*p >= 'A' && *p <= 'Z'){     // Verifica se é maiúscula
        *q = tolower(*p);           // Converte para minúscula
   	 	}
    
    	else if(*p >= 'a' && *p <= 'z'){ // Verifica se é minúscula
        *q = toupper(*p);             // Converte para maiúscula
    	}
    
    	else{
        *q = *p;                      // Mantém espaços e outros caracteres
    	}

    	q++;
   		 p--;
	}

	*q = '\0';

	printf("Resultado: %s\n", aux);

	return 0;


}
