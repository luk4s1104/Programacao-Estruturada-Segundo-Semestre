#include<stdio.h>

int main(){
	
	char str[100];
	char *p, *q, *inicio;
	char busca[100];
	char encontrou = 0;
	
	printf("Digite uma String: ");
	fgets(str, 100, stdin);
	
	printf("\nDigite a string que deseja buscar:");
	fgets(busca, 100, stdin);
	
	q = busca;
	
	while(*q != '\0'){
    if(*q == '\n'){
        *q = '\0';
        break;
    }
    
    q++;
}
	
	p = str;
	
	while(*p != '\0' && *p != '\n'){
		
		inicio = p;
		q = busca;
		
		while(*q != '\0' && *p==*q){
		p++;
		q++;
		}		
		if(*q == '\0' || *q == '\n'){
			encontrou =1;
		}
		p = inicio;
		p++;
	}
	
	if(encontrou == 1){
		printf("\nA String %s foi encontrada\n", busca);
	}	
	else{
		printf("\nString nao encontrada\n");
	}
	
	return 0;
}