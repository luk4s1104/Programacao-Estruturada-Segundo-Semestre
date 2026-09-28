#include<stdio.h>
#include<string.h>

#define MAX 50
#define TAM 2

typedef struct{
	char nome[MAX];
	int idade;
	float nota;
}Aluno;

typedef struct {
	char rua[MAX];
	int numero;
}Endereco;

typedef struct {
	char nome[MAX];
	Endereco end;
}Pessoa;

void imprime_aluno_ptr(Aluno *a); // Ex 1
// imprimir os dados do aluno usando o operador ->

void le_aluno_ptr(Aluno *a); // Ex 2
// ler nome, idade e nota diretamente na struct apontada 

void le_turma_ptr(Aluno *v, int n); // Ex 3
// ler n alunos usando aritmetica de ponteiros

void imprime_turma_ptr(Aluno *v, int n); // Ex 3
// imprimir os alunos usando ponteiros

float media_turma_ptr(Aluno *v, int n); // Ex 4
// calcular media das notas usando ponteiros

int conta_aprovados_ptr(Aluno *v, int n); // Ex 5
// contar alunos com nota => 6 usando ponteiros 

Aluno* busca_aluno_ptr(Aluno *v, int n, char nome[]); // Ex 6
// retornar ponteiro para o aluno encontrado ou NULL

void imprime_pessoa_ptr(Pessoa *p); // Ex 7
// imprimir nome e endereco usando ponteiros

void le_pessoa_ptr(Pessoa *p);  // Ex 7
// ler os dados da pessoa usando ponteiros

int main(){
	
	Aluno turma[TAM];
	Pessoa pessoas[TAM];
	int i;
	
	printf("\n--- LEITURA DA TURMA ---\n");    // ex 2
	for(i = 0; i < TAM; i++) {
    	printf("\n--- Aluno %d ---\n", i + 1);
		le_aluno_ptr(turma + i);
	}
	
	printf("\n\n=== LISTA DE ALUNOS CADASTRADOS ===\n");  // ex 1
    for(i = 0; i < TAM; i++) {
    	imprime_aluno_ptr(turma + i);
    	printf("\n");
    }
    
    printf("\n--- LEITURA DA TURMA ---\n");   // ex 3
    le_turma_ptr(turma, TAM);
    
    printf("\n--- DADOS DA TURMA ---\n");    // ex 3
    imprime_turma_ptr(turma, TAM);
    
    printf("\n--- MEDIA DA TURMA ---\n");    //ex 4 
    float m = media_turma_ptr(turma, TAM);
    printf("Media da turma: %.2f", m);
    
    printf("\n\n--- NUMERO DE ALUNOS APROVADOS ---\n");  // ex 5
    int count = conta_aprovados_ptr(turma,TAM);
    printf("Quantidade de alunos aprovados: %i", count);
    
    printf("\n\n--- BUSCA ALUNO POR NOME ---\n");  // ex 6
    char nome_busca[MAX];
    printf("Digite o nome do aluno que deseja procurar: ");
    fgets(nome_busca, MAX, stdin);
    
    Aluno *a = busca_aluno_ptr(turma, TAM, nome_busca);
    
    if(a != NULL){
    	printf("Aluno encontrado:\n");
    	imprime_aluno_ptr(a);
	}
	else{
		printf("Aluno nao encontrado.\n");
	}
    
    printf("\n--- LEITURA DE PESSOAS ---\n");    // ex 7
    for(i = 0; i < TAM; i++){
    	printf("\n--- PESSOA %d ---\n", i + 1);
    	le_pessoa_ptr(pessoas + i);
	}
	
	printf("\n--- LISTA DE PESSOAS CADASTRADAS ---\n");  // ex 7
	for(i = 0; i < TAM; i++){
		imprime_pessoa_ptr(pessoas + i);
		printf("\n\n");
	}
	return 0;
}

void imprime_aluno_ptr(Aluno *a){  // Ex 1
	printf("Nome do aluno: %s", a->nome);
	printf("Idade do aluno: %i", a->idade);
	printf("\nNota do aluno: %.1f", a->nota);
	printf("\n");
}

void le_aluno_ptr(Aluno *a){ // Ex 2
	printf("Digite o nome do aluno: ");
	fgets(a->nome, MAX, stdin);
	fflush(stdin);
	
	printf("Digite a idade do aluno: ");
	scanf("%i",&(a->idade));
	
	printf("Digite a nota do aluno: ");
	scanf("%f", &(a->nota));
	fflush(stdin);

}

void le_turma_ptr(Aluno *v, int n){ // Ex 3
	for(int i = 0; i < n; i++){
		printf("\n--- Digite os dados do aluno %i ---\n", i+1);
		
		printf("Nome: ");
		fgets((v + i)->nome, MAX, stdin);
		printf("Idade: ");
		scanf("%i", &(v + i)->idade);
		fflush(stdin);
		printf("Nota: ");
		scanf("%f", &(v + i)->nota);
		fflush(stdin);
		printf("\n");
	}
}

void imprime_turma_ptr(Aluno *v, int n){ // Ex 3 
	for(int  i =0; i < n; i++){
		printf("\nAluno: %i\n", i + 1);
		printf("Nome: %s", (v + i)->nome);
		printf("Idade: %i\n", (v + i)->idade);
		printf("Nota: %.1f\n", (v + i)->nota);
	}
}

float media_turma_ptr(Aluno *v, int n){  // Ex 4
	float soma = 0, media = 0;
	for(int i = 0; i < n; i++){
		soma += (v + i)->nota;
	}
	media = soma / n;
	return media;
}

int conta_aprovados_ptr(Aluno *v, int n){  // Ex 5
	int count = 0;
	for(int i = 0; i < n; i++){
		if((v + i)->nota >= 6){
			count++;
		}
	}
	return count;
}

Aluno* busca_aluno_ptr(Aluno *v, int n, char nome[]){ // Ex 6
	for(int i = 0; i < n; i++){
		if(strcmp((v + i)->nome, nome) == 0){
			return (v + i); // retorna o endereco do aluno encontrado
		}
	}
	return NULL;
}

void imprime_pessoa_ptr(Pessoa *p){     // Ex 7
	printf("Nome da pessoa: %s", p->nome);
	printf("Rua: %s", p->end.rua);
	printf("Numero: %i", p->end.numero);
}

void le_pessoa_ptr(Pessoa *p){    // Ex 7
	printf("Nome: ");
	fgets(p->nome, MAX, stdin);
	fflush(stdin);
	printf("Rua: ");
	fgets(p->end.rua, MAX, stdin);
	printf("Numero: ");
	scanf("%i", &(p->end.numero));
	fflush(stdin);
	printf("\n");
}