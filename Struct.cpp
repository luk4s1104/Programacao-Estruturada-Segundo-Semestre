#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50 

struct aluno {
	char nome[MAX];
	int idade;
	float nota;
};

struct endereco {
	char rua[MAX];
	int numero;
};

struct pessoa {
	char nome[MAX];
	struct endereco end;
};

struct data {
	int dia;
	int mes;
	int ano;
};

void imprime_data(struct data d){
	printf("\nData formatada: ");
	printf("%02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}

void imprime_pessoa(struct pessoa p){
	printf("Nome: %s | Nome da rua: %s | Numero: %i\n", p.nome, p.end.rua, p.end.numero);
}

void le_pessoas(struct pessoa v[], int n){
	for(int i = 0; i < n; i++){
	printf("\n----- Cadastro de Pessoa -----\n\n");
    
	printf("Digite o nome da pessoa: ");
    scanf("%s", v[i].nome);
    
    printf("Digite o nome da rua: ");
    scanf("%s", v[i].end.rua);
    
    printf("DIgite o numero: ");
    scanf("%i", &v[i].end.numero);
    fflush(stdin);
	}
}

void imprime_pessoas(struct pessoa v[], int n){
	printf("\n--------Exibindo a lista de pessoas--------\n");
	for(int i = 0; i < n; i++){
		imprime_pessoa(v[i]);
	}
}

void imprime_aluno(struct aluno a) {
	printf("Nome: %s | Idade: %i | Nota: %.2f\n", a.nome, a.idade, a.nota);
}

void le_turma(struct aluno turma[], int n){
	for(int i = 0; i < n; i++){
		printf("--- Digite os dados do aluno %i ---\n", i + 1);
		
		printf("Digite o nome do aluno: ");
		scanf("%s", turma[i].nome);
		
		printf("Digite a idade do aluno: ");
		scanf("%i", &turma[i].idade);
		
		printf("Digite a nota do aluno: ");
		scanf("%f", &turma[i].nota);
		fflush(stdin);
		
		printf("\n");
	}
}

void imprime_turma(struct aluno turma[], int n){
	printf("\n======== Exibindo a Turma ========\n");
	for(int i = 0; i < n;i++){
		imprime_aluno(turma[i]);
	}
}

float media_turma(struct aluno turma[], int n){
		float soma = 0;
		for(int i = 0; i < n; i++){
			soma = soma + turma[i].nota;
		}
		return soma/n;
}

int busca_aluno_por_nome(struct aluno turma[], int n, char nome[]){
	for(int i = 0; i < n; i++){
		if(strcmp(turma[i].nome, nome) == 0){
			return i;
		}
	}
	return -1;
}

int conta_aprovados(struct aluno turma[], int n){
	int aprovados = 0;
	
	for(int i =0; i < n; i++){
		if(turma[i].nota >= 6){
			aprovados++;
		}
	}
	return aprovados;
}

int main (){
	
	// =============================================================
    // TESTE DOS EXERCICIOS 1, 2, 3, 6, 7 - TURMA DE ALUNOS
    // =============================================================
	
	struct aluno minha_turma[3];
	
	le_turma(minha_turma, 3);
	
	imprime_turma(minha_turma, 3);
	
	float media = media_turma(minha_turma, 3);
    printf("\nMedia das notas da turma: %.2f\n", media);
    
    int total_aprovados = conta_aprovados(minha_turma, 3);
    printf("Total de alunos aprovados (nota >= 6): %i\n\n", total_aprovados);
    
    printf("\n-------- Teste de busca de aluno --------\n");
    
    char nome_busca[MAX];
    printf("Digite o nome do aluno que quer procurar: ");
    scanf("%s", nome_busca);
    
    int posicao = busca_aluno_por_nome(minha_turma, 3, nome_busca);
    
    if(posicao != -1){
    	printf("\nAluno encontrado na posicao %i do vetor!\n", posicao);
	}
	else {
		printf("\nAluno nao encontrado na turma!\n");
	}
    printf("\n=========================================================================================\n");
    
    // =============================================================
    // TESTE DOS EXERCICIOS 4 E 5 - LISTA DE PESSOAS (STRUCT ANINHADA)
    // =============================================================
    
    struct pessoa lista_pessoas[2];

    le_pessoas(lista_pessoas, 2);
	
	imprime_pessoas(lista_pessoas, 2);
	
	/* =============================================================
	Exercicio 8 - Struct para dados agrupados
	============================================================= */
	printf("\n=========================================================================================\n");
    printf("\n----- Teste de Impressao de Data -----\n");
    
    struct data hoje;
    
    printf("Digite o dia: ");
    scanf("%i", &hoje.dia);
    
    printf("Digite o mes: ");
    scanf("%i", &hoje.mes);
    
    printf("Digite o ano: ");
    scanf("%i", &hoje.ano);
    
    imprime_data(hoje);
    
	return 0;
}