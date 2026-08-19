#include <stdio.h>

int main(){

    char nome[100], sobre[100], mae[100], city[100];
    char jedi[100], sobrejedi[100], composto[100];
    char *p, *q;

    printf("Digite seu nome: ");
    fgets(nome, 100, stdin);

    printf("\nDigite seu sobrenome: ");
    fgets(sobre, 100, stdin);

    printf("\nDigite o nome da sua mae: ");
    fgets(mae, 100, stdin);

    printf("\nDigite o nome da sua cidade: ");
    fgets(city, 100, stdin);

    p = nome;              
    q = jedi;                   

    while(*p != '\0' && *p != '\n' && q < jedi + 3){
        *q = *p;            
        p++;
        q++;
    }

    p = sobre;               

    while(*p != '\0' && *p != '\n' && q < jedi + 5){
        *q = *p;            
        p++;
        q++;
    }

    *q = '\0';              
    
    p = mae;                
    q = sobrejedi;            

    while(*p != '\0' && *p != '\n' && q < sobrejedi + 2){
        *q = *p;            
        p++;
        q++;
    }

    p = city;                 

    while(*p != '\0' && *p != '\n' && q < sobrejedi + 5){
        *q = *p;              
        p++;
        q++;
    }

    *q = '\0';                

    p = jedi;                   
    q = composto;                

    while(*p != '\0' && q < composto + 3){
        *q = *p;                 
        p++;
        q++;
    }

    p = sobrejedi + 2;            

    while(*p != '\0' && q < composto + 6){
        *q = *p;                 
        p++;
        q++;
    }

    *q = '\0';                   

    printf("\nNome Jedi: %s", jedi);
    printf("\nSobrenome Jedi: %s", sobrejedi);
    printf("\nNome composto: %s\n", composto);

    return 0;
}