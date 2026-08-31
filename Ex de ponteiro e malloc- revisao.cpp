#include<stdio.h>
#include<stdlib.h>

void calcularEstatisticas(int *vetor, int tamanho, int *maior, int *menor, float *media);

int main (){
	
	int n;
	
	printf("Digite o numero de sensores utilizados: ");
	scanf(" %i", &n);
	printf("\n");
	
	int *v1 = (int *) malloc(n * sizeof(int));
	
	if(v1 == NULL){
		printf("Erro ao alocar memoria");
		return 1;
	}
	
	int ma, me;
	float med;	
	
	for (int l = 0; l < n; l++) {
        printf("Digite a temperatura registrada no %i sensor: ", l + 1);
        scanf("%i", &v1[l]);
    }
	
	calcularEstatisticas(v1, n, &ma, &me, &med);
	printf("\n--- Resultados ---");
    printf("\nMaior temperatura: %i", ma);
    printf("\nMenor temperatura: %i", me);
    printf("\nMedia das temperaturas: %.2f\n", med);
	
	free(v1);
	
	return 0;
}

void calcularEstatisticas(int *vetor, int tamanho, int *maior, int *menor, float *media){
	int i, l, s, soma = 0;
	*menor = *vetor;
	for(i = 0; i < tamanho; i++){
		if(*(vetor + i) < *menor){
			*menor = *(vetor + i);        // descobrir o menor valor
		}
	}
	
	*maior = *vetor;
	for(l = 0; l < tamanho; l++){
		if(*(vetor + l) > *maior){
			*maior = *(vetor + l);     // descobrir o maior valor
		}
	}

	for(s = 0; s < tamanho; s++){
		soma += *(vetor + s);
	}
	
	*media = (float)soma / tamanho;
}