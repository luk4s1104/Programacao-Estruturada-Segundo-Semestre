#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

typedef struct { // Ex 1
	char nome[MAX]; 
	int idade;
	float nota;
	char status;  // 'A' - ativo | 'I' - inativo
}Aluno;

void aloca_alunos(Aluno **v, int n);   // Ex 2
void le_aluno_ptr(Aluno *a);		// Ex 3
void insere_aluno(Aluno **v, int *n);   // Ex 4
void imprime_alunos(Aluno *v, int n);   // Ex 5
float media_alunos(Aluno *v, int n);    // Ex 6
Aluno * busca_aluno(Aluno *v, int n, char nome[]); // Ex 7
void remove_aluno(Aluno *v, int n, char nome []);

int main(){
	
	Aluno *turma = NULL; 
	int qtd = 0; 
	int op;
	char nome[MAX];
	Aluno *a;
	
	do{
		printf("--- MENU ---\n");
		printf("1 - Inserir Aluno\n");
		printf("2 - Listar Alunos\n");
		printf("3 - Media da turma\n");
		printf("4 - Buscar aluno\n");
		printf("5 - Remover aluno\n");
		printf("0 - Sair\n");
		
		printf("\nOpcao: ");
		scanf("%i", &op);
		printf("\n");
		getchar();
		
		switch(op){
			
			case 1:
				insere_aluno(&turma, &qtd);
			break;
			
			case 2:
				imprime_alunos(turma, qtd);
			break;
				
			case 3:
				if(qtd > 0){
				 printf("Media da turma: %.1f\n\n", media_alunos(turma, qtd));
				}
				 else{
				 	printf("Nao ha alunos com a matricula ativa!\n\n");
				}
			break;
			
			case 4:
				printf("Nome: ");
				fgets(nome, MAX, stdin);
				nome[strcspn(nome, "\n")] = '\0';
				
				a = busca_aluno(turma, qtd, nome);
				if(a != NULL){
					printf("Aluno encontrado: %s (nota: %.1f)\n\n", a->nome, a->nota);
				}
				else{
					printf("Aluno nao encontrado!\n\n");
				}
			break;
			
			case 5:
				printf("Nome do aluno a remover :");
				fgets(nome, MAX, stdin);
				nome[strcspn(nome, "\n")] = '\0';
				printf("\n");
				remove_aluno(turma, qtd, nome);
			break;
		}
		
	}while(op != 0);
	
	free(turma);
	turma = NULL;	
	return 0;
}

void aloca_alunos(Aluno **v, int n){    // Ex 2
	
	Aluno *aux = (Aluno *) realloc(*v, n * sizeof(Aluno));
	
	if(aux == NULL){
		printf("Erro: falha na alocacao de memoria!\n");
		exit(1);
	}
	
	*v = aux;
}

void le_aluno_ptr(Aluno *a){     // Ex 3
	printf("Nome: ");
	fgets(a->nome, MAX, stdin);
	a->nome[strcspn(a->nome, "\n")] = '\0';
	
	printf("Idade: ");
	scanf("%i", &(a->idade));
	
	printf("Nota: ");
	scanf("%f", &(a->nota));
	getchar();
	
	printf("Status: ");
	scanf("%c", &(a->status));;
	a->status = toupper(a->status);
	getchar();
	
	printf("\n");
	
}

void insere_aluno(Aluno **v, int *n){   // Ex 4
	
	aloca_alunos(v, *n + 1);
	
	printf("--- Cadastrar Aluno ---\n");
	le_aluno_ptr(&(*v)[*n]);
	
	(*n)++;
}

void imprime_alunos(Aluno *v, int n){   // Ex 5
	int i = 0;
	int encontrou = 0;
	for(i = 0; i < n; i++){
		if((v + i)->status == 'A'){
			printf("Nome: %s", (v + i)->nome);
			printf("\nIdade: %i\n", (v + i)->idade);
			printf("Nota: %.1f\n\n", (v + i)->nota);
			encontrou = 1;
		}	
	}
	
	if(encontrou == 0){
			printf("Nao ha alunos com a matricula ativa!\n\n");
	}
}
		
float media_alunos(Aluno *v, int n){   // Ex 6 
	float s = 0;
	int i = 0, cont = 0;
	
	for(i = 0; i < n; i++){
		if((v + i)->status == 'A'){
		s += (v + i)->nota;
		cont++;
		}
	}
	return s / cont;
}

Aluno * busca_aluno(Aluno *v, int n, char nome[]){   // Ex 7
	int i; 	
	for(i = 0; i < n; i++){
		if(strcmp(nome, (v + i)->nome) == 0){
			return (v + i);
		}
	}
	return NULL;
}

void remove_aluno(Aluno *v, int n, char nome[]){   // Ex 8
	int i;
	int achou = 0;
	for(i = 0; i < n; i++){
		if((v + i)->status == 'A' && strcmp(nome, (v + i)->nome) == 0){
		(v + i)->status = 'I';	
		achou = 1;
		printf("Aluno removido com sucesso!\n\n");
		}
	}
	if(achou = 0){
		printf("Aluno nao encontrado ou ja inativo!\n\n");
	}
}