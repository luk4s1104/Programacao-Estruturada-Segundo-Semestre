#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char str[100];
	char *p;
	
	printf("Digite uma string:");
	fgets(str, 100, stdin);
	
	p = str;
	
	while(*p != '\0'){
		p++;
	}
	
	while(p >= str){
		printf("String invertida: %c", *p);
		p--;
	}
	
	printf("\n");
	
	return 0;
}