#include<stdio.h>
#include<stdlib.h>

void analisarConsumo(float *vetor, int tamanho, float *maior, float *menor, int *qtdAcimaMedia);

int main(){
	
	int n;
	
	printf("Digite o numero de caminhoes utilizados: ");
	scanf("%i", &n);
	
	float *v = (float *) malloc(n * sizeof(float));
	
	for(int i = 0; i < n; i++){
	printf("\nDigite o consumo do %io caminhao: ", i +1);
	scanf("%f", (v + i));
	}
	float ma, me;
	int acima;
	
	analisarConsumo(v, n, &ma, &me, &acima);
	printf("\n--------Resultados--------");
	printf("\nMaior Consumo: %.2f", ma);
	printf("\nMenor Consumo: %.2f", me);
	printf("\nNumeros de consumos acima da media: %i", acima);
	
	free(v);
	
	return 0;
}

void analisarConsumo(float *vetor, int tamanho, float *maior, float *menor, int *qtdAcimaMedia){
	
	*menor = *vetor;
	for(int i = 0; i < tamanho; i++){
		if(*(vetor + i) < *menor){
			*menor = *(vetor + i);
		}
	}
	
	*maior = *vetor;
	for(int i = 0; i < tamanho; i++){
		if(*(vetor + i) > *maior){
			*maior = *(vetor + i);
		}
	}
	
	float media, soma;
	soma = 0;
	
	for(int i = 0; i < tamanho; i++){
		soma += *(vetor + i);
	}
	media = soma / tamanho; 
	
	*qtdAcimaMedia = 0;
	for(int i = 0; i < tamanho; i ++){
		if(*(vetor + i) > media){
		(*qtdAcimaMedia)++;
		}
	}
}
