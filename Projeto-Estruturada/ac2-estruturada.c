#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>

// STRUCT 1: Aninhada (contém dados do curso/disciplina)
typedef struct {   // uso do typedef para nao ter que escrever struct ao declarar uma variavel
    char nome_curso[50];  // nome do curso 
    int carga_horaria;   // horas concluidas pelo aluno 
} Curso;

// STRUCT 2: Principal (possui 5 campos, atendendo ao requisito de 4+)
typedef struct {
    int ra;
    char nome[100];
    int semestre;
    int ativo; // 1 = ativo, 0 = removido (exclusão lógica)
    Curso curso_matriculado; // Struct aninhada: agrupa os dados do curso dentro da struct principal do aluno
} Aluno;

// Protótipos das funções
void carregar_arquivo(Aluno **cadastro, int *total, int *capacidade);
void salvar_e_sair(Aluno *cadastro, int total);
void cadastrar_aluno(Aluno **cadastro, int *total, int *capacidade);
void buscar_aluno(Aluno *cadastro, int total);
void atualizar_aluno(Aluno *cadastro, int total);
void remover_aluno(Aluno *cadastro, int total);
void listar_alunos(Aluno *cadastro, int total);

int main() {
    int capacidade = 2; // Capacidade inicial do vetor dinâmico
    int total = 0;      // Número atual de alunos cadastrados
    int op = 0;    
    
    // um ponteiro cadastro criado seguindo o molde de Aluno, guardando as informacoes da struct em um vetor
	Aluno *cadastro = (Aluno *) malloc(capacidade * sizeof(Aluno)); // Alocação dinâmica inicial (comeca com espaco pra 2 alunos)
    
    // verificacao de seguranca
    if (cadastro == NULL) {  // caso nao consiga alocar o bloco, ele retorna null
        printf("Erro ao alocar memoria!\n");  
        exit(1); // encerra o programa
    }
    
    // Carrega os dados salvos anteriormente do arquivo binário
    carregar_arquivo(&cadastro, &total, &capacidade);  
    
    do {
        printf("\n=== SISTEMA ACADEMICO ===\n");
        printf("1 - Cadastrar\n");
        printf("2 - Buscar\n");
        printf("3 - Atualizar\n");
        printf("4 - Remover\n");
        printf("5 - Listar\n");
        printf("0 - Sair\n");
        printf("\nOpcao: ");
        scanf("%i", &op);
        getchar(); // Limpa o buffer do teclado (tira o \n)
        printf("\n");
        
        switch(op) {
            case 1:
                cadastrar_aluno(&cadastro, &total, &capacidade);  // aqui eu passo com o & pois eu quero alterar os valores do main(enviando o endereco da variavel)
                break;
            case 2:
                buscar_aluno(cadastro, total);  // nao alteram o valor entao sem &(recebem uma copia)
                break;
            case 3:
                atualizar_aluno(cadastro, total);
                break;
            case 4:
                remover_aluno(cadastro, total);
                break;
            case 5:
                listar_alunos(cadastro, total);
                break;
            case 0:
                salvar_e_sair(cadastro, total);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while(op != 0);

    return 0;
}

// Carrega dados do arquivo binário para a memória RAM ao iniciar
void carregar_arquivo(Aluno **cadastro, int *total, int *capacidade) { // Aluno ** permite que o realloc atualize o endereço do vetor direto no main. 
    // Cria o ponteiro 'arq' e abre o arquivo "alunos.bin" em modo "rb" para trazer os dados gravados no binario para a RAM.
	FILE *arq = fopen("alunos.bin", "rb");			 // o ponteiro arq guarda o endereco de onde o arquivo esta salvo, e le o arquivo
	if (arq == NULL) { 			// se o arquivo nao exister 	
        return;			 // pare a execucao dessa funcao e volte onde ela foi chamada
    }
    
    // esse bloco faz toda a leitura do arquivo binario
    Aluno temp; // struct temporaria
    // o fread vai salvar as info do aluno nessa struct temp, tamanho em bytes do que esta lendo, a qtd de elementos por vez, o arquivo que deve ser lido
    while (fread(&temp, sizeof(Aluno), 1, arq) == 1) {  // o laco roda ate o fread nao conseguir ler nada
        if (*total >= *capacidade) {  
            *capacidade *= 2; 
            Aluno *temp_realloc = (Aluno *) realloc(*cadastro, (*capacidade) * sizeof(Aluno));  // realloca dobrando a capacidade do vetor	
            if (temp_realloc == NULL) {  // se a ram estiver cheia 
                printf("Erro ao realocar memoria ao carregar arquivo!\n");
                fclose(arq);    // fecha o arquivo
                exit(1); 
            }
            *cadastro = temp_realloc;    // se deu certo, atualiza o ponteiro original da main
        }
        (*cadastro)[*total] = temp;    // coloca o aluno que leu do disco na posicao atual do vetor cadastro	
        (*total)++;   // vai somando o numero de alunos cadastrados
    }
    
    fclose(arq);   // fecha el arquivo 
}

// Salva os dados no arquivo binário ao fechar o programa
void salvar_e_sair(Aluno *cadastro, int total) { // Aluno * pois ela apenas le o vetor e nao realloca(so le, nao altera o endereco)
    FILE *arq = fopen("alunos.bin", "wb");  		// o ponteiro arq guarda o endereco que o fopen retorna do arquivo, e escreve-ra no arquivo 
    if (arq == NULL) { 		// se tiver erro ao criar/abrir o arquivo
        printf("Erro ao abrir arquivo para escrita!\n");
        free(cadastro);   // libero memoria
        return;    // cancelo a operacao
    }
    
    // Grava o vetor inteiro de structs diretamente no arquivo binário
    fwrite(cadastro, sizeof(Aluno), total, arq);  // o ptr que aponta pro bloco que quero salvar no binario, tamanho em bytes do bloco, quantos serao salvos, o ptr com o endero do binario 
    
    // Utilização de fseek e ftell conforme exigido
    fseek(arq, 0, SEEK_END);  // coloca o cursor no final do arquivo -> o arquivo, quantos bytes mover, a partir de onde 
    long tamanho_bytes = ftell(arq);  // variavel que guarda o valor em bytes salvo no arquivo ate onde o cursor aponta
    
    printf("[Sistema] %ld bytes salvos com sucesso em 'alunos.bin'. Programa encerrado.\n", tamanho_bytes);
    
    fclose(arq);   // fecha o arquivo 
    free(cadastro); // Liberação da memória dinâmica
}

// Função que utiliza ponteiro para ponteiro (Aluno **cadastro) para permitir realocação
void cadastrar_aluno(Aluno **cadastro, int *total, int *capacidade) {
    if (*total >= *capacidade) {
        *capacidade *= 2;
        Aluno *temp = (Aluno *) realloc(*cadastro, (*capacidade) * sizeof(Aluno));
        if (temp == NULL) {
            printf("Erro ao realocar memoria!\n");
            exit(1);
        }
        *cadastro = temp;
    }
    
    Aluno novo;
    novo.ativo = 1; // Aluno ativo por padrão
    
    printf("=== CADASTRAR ALUNO ===\n");
    printf("Nome do aluno: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;
    
    printf("RA do aluno: ");
    scanf("%d", &novo.ra);
    getchar();
    
    do {
        printf("Semestre (1 a 10): ");
        scanf("%d", &novo.semestre);
        getchar();
        if (novo.semestre < 1 || novo.semestre > 10) {
            printf("ERRO: Semestre invalido! Digite entre 1 e 10.\n");
        }
    } while (novo.semestre < 1 || novo.semestre > 10);
    
    printf("Nome do curso: ");
    fgets(novo.curso_matriculado.nome_curso, sizeof(novo.curso_matriculado.nome_curso), stdin);
    novo.curso_matriculado.nome_curso[strcspn(novo.curso_matriculado.nome_curso, "\n")] = 0;
    
    printf("Horas concluidas: ");
    scanf("%d", &novo.curso_matriculado.carga_horaria);
    getchar();
    
    (*cadastro)[*total] = novo;
    (*total)++;
    
    printf("\nAluno cadastrado com sucesso!\n");
}

// Busca aluno por RA (utiliza ponteiro simples)
void buscar_aluno(Aluno *cadastro, int total) {
    int ra_busca;
    printf("=== BUSCAR ALUNO ===\n");
    printf("Digite o RA do aluno: ");
    scanf("%d", &ra_busca);
    getchar();
    
    for (int i = 0; i < total; i++) {
        if ((cadastro + i)->ativo == 1 && (cadastro + i)->ra == ra_busca) {
            printf("\n-----------------------------------------\n");
            printf("ALUNO ENCONTRADO:\n");
            printf("Nome: %s\n", (cadastro + i)->nome);
            printf("RA: %d\n", (cadastro + i)->ra);
            printf("Semestre: %d\n", (cadastro + i)->semestre);
            printf("Curso: %s | Horas concluidas: %dh\n", 
                   (cadastro + i)->curso_matriculado.nome_curso,
                   (cadastro + i)->curso_matriculado.carga_horaria);
            printf("-----------------------------------------\n");
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", ra_busca);
}

// Atualiza dados cadastrais do aluno perguntando campo a campo com (s/n)
void atualizar_aluno(Aluno *cadastro, int total) {
    int ra_busca;
    char resp;
    
    printf("=== ATUALIZAR ALUNO ===\n");
    printf("Digite o RA do aluno que deseja atualizar: ");
    scanf("%d", &ra_busca);
    getchar();
    
    for (int i = 0; i < total; i++) {
        if ((cadastro + i)->ativo == 1 && (cadastro + i)->ra == ra_busca) {
            printf("\nAluno encontrado: %s\n", (cadastro + i)->nome);
            printf("Responda com 's' para sim ou 'n' para nao.\n\n");
            
            // Atualizar Nome
            printf("Deseja atualizar o nome do aluno? (s/n): ");
            scanf(" %c", &resp);
            getchar();
            if (resp == 's' || resp == 'S') {
                printf("Novo nome do aluno: ");
                fgets((cadastro + i)->nome, sizeof((cadastro + i)->nome), stdin);
                (cadastro + i)->nome[strcspn((cadastro + i)->nome, "\n")] = 0;
            }
            
            // Atualizar Semestre
            printf("Deseja atualizar o semestre? (s/n): ");
            scanf(" %c", &resp);
            getchar();
            if (resp == 's' || resp == 'S') {
                do {
                    printf("Novo semestre (1 a 10): ");
                    scanf("%d", &(cadastro + i)->semestre);
                    getchar();
                    if ((cadastro + i)->semestre < 1 || (cadastro + i)->semestre > 10) {
                        printf("ERRO: Semestre invalido! Digite entre 1 e 10.\n");
                    }
                } while ((cadastro + i)->semestre < 1 || (cadastro + i)->semestre > 10);
            }
            
            // Atualizar Nome do Curso
            printf("Deseja atualizar o nome do curso? (s/n): ");
            scanf(" %c", &resp);
            getchar();
            if (resp == 's' || resp == 'S') {
                printf("Novo nome do curso: ");
                fgets((cadastro + i)->curso_matriculado.nome_curso, sizeof((cadastro + i)->curso_matriculado.nome_curso), stdin);
                (cadastro + i)->curso_matriculado.nome_curso[strcspn((cadastro + i)->curso_matriculado.nome_curso, "\n")] = 0;
            }
            
            // Atualizar Carga Horária
            printf("Deseja atualizar a quantidade de horas concluidas? (s/n): ");
            scanf(" %c", &resp);
            getchar();
            if (resp == 's' || resp == 'S') {
                printf("Nova quantidade de horas concluidas: ");
                scanf("%d", &(cadastro + i)->curso_matriculado.carga_horaria);
                getchar();
            }
            
            printf("\nDados atualizados com sucesso!\n");
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", ra_busca);
}

// Exclusão lógica do aluno (muda ativo para 0)
void remover_aluno(Aluno *cadastro, int total) {
    int ra_busca;
    printf("=== REMOVER ALUNO ===\n");
    printf("Digite o RA do aluno que deseja remover: ");
    scanf("%d", &ra_busca);
    getchar();
    
    for (int i = 0; i < total; i++) {
        if ((cadastro + i)->ativo == 1 && (cadastro + i)->ra == ra_busca) {
            (cadastro + i)->ativo = 0;
            printf("Aluno %s removido com sucesso!\n", (cadastro + i)->nome);
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", ra_busca);
}

// Listagem com opção de ver todos ou filtrar por nome de curso
void listar_alunos(Aluno *cadastro, int total) {
    int sub_op;
    printf("=== LISTAR ALUNOS ===\n");
    printf("1 - Listar todos os alunos ativos\n");
    printf("2 - Listar por nome de curso\n");
    printf("Opcao: ");
    scanf("%d", &sub_op);
    getchar();
    
    int encontrou = 0;
    
    if (sub_op == 1) {
        printf("\n--- LISTA DE TODOS OS ALUNOS ATIVOS ---\n");
        for (int i = 0; i < total; i++) {
            if ((cadastro + i)->ativo == 1) {
                printf("RA: %d | Nome: %s | Semestre: %d | Curso: %s | Horas Concluidas: %dh\n",
                       (cadastro + i)->ra,
                       (cadastro + i)->nome,
                       (cadastro + i)->semestre,
                       (cadastro + i)->curso_matriculado.nome_curso,
                       (cadastro + i)->curso_matriculado.carga_horaria);
                encontrou = 1;
            }
        }
    } else if (sub_op == 2) {
        char curso_busca[50];
        printf("Digite o nome do curso para filtrar: ");
        fgets(curso_busca, sizeof(curso_busca), stdin);
        curso_busca[strcspn(curso_busca, "\n")] = 0;
        
        printf("\n--- ALUNOS MATRICULADOS NO CURSO: %s ---\n", curso_busca);
        for (int i = 0; i < total; i++) {
            if ((cadastro + i)->ativo == 1 && strcmp((cadastro + i)->curso_matriculado.nome_curso, curso_busca) == 0) {
                printf("RA: %d | Nome: %s | Semestre: %d | Horas Concluidas: %dh\n",
                       (cadastro + i)->ra,
                       (cadastro + i)->nome,
                       (cadastro + i)->semestre,
                       (cadastro + i)->curso_matriculado.carga_horaria);
                encontrou = 1;
            }
        }
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    if (!encontrou) {
        printf("Nenhum registro encontrado.\n");
    }
    printf("\n");
}