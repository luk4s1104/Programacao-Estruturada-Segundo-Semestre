#include<stdio.h>
#include<stdlib.h>

void inc(int x);      //EX01
void troca_invalida(int x, int y);   // EX02
void troca_ref(int *x, int *y);    //EX04
void inc_ref(int *p);      //EX05
int troca_se_maior(int *a, int *b);   //EX06
void normaliza_trio(float *x, float *y, float *z);     //EX07
void zera(int *v, int n);     //EX08
int soma(const int *v, int n);     //EX09
float media_int(const int *v, int n);   //EX09
void escala(float *v, int n, float k);  //EX10
void troca_extremos(int *v, int n); 	//EX11
int filtra_caixa(const float *origem, int n, float *destino, float L, float U);     //EX12
int indice_min(const float *v, int n);		//EX13
int indice_max(const float *v, int n);		//EX13
int remove_primeiro(int *v, int n);			//EX14
void inverte(int *v, int n);                //EX15

int main(){
	
	//EX01
	int a = 10, b = 7;
	float num1 = 8, num2 = 5, num3 = 5;
	int v1[5] = {1,2,3,4,5};
	int v2[5] = {1,2,3,4,5};
	int v3[5] = {1,2,3,4,5};
	int v4[5] = {10, 20, 30, 40, 50};
	int v5[5] = {1, 2, 3, 4, 5};
	float d1[5] = {1,-2,3,4.5,0};
	float o[5] = {1,10,5,20,7};
	float dest[5];
	
	inc(a);
	
	printf("[1] - %i", a); // provar que o 'a' nao muda o valor
	
	//EX02
	troca_invalida(a, b);
	
	printf("\n[2] - %i, %i", a, b); // invalida pois falta o ponteiro
	
	//EX03
	printf("\n[3] - Na passagem por valor, a funcao recebe uma copia dos valores das variaveis.\n");
	printf("Portanto, qualquer alteracao feita nos parametros modifica apenas as copias e nao as variaveis originais.");
	
	//EX04
	troca_ref(&a, &b);
	
	printf("\n[4] - %i, %i", a, b);
	
	//EX05
	inc_ref(&a);
	
	printf("\n[5] - %i", a);
	
	//EX06
	printf("\n[6] - b = %i, a = %i", b, a);
	troca_se_maior(&b, &a);
	printf("\nTroca: - b = %i, a = %i", b, a);
	
	//EX07
	normaliza_trio(&num1, &num2, &num3);
	printf("\n[7] - Apos normalizar: num1 = %.2f, num2 = %.2f, num3 = %.2f", num1, num2, num3);
	
	//EX08
	zera(v1, 5);
	printf("\n[8] - Zerando um vetor:");
	int *p = &v1[0];

	for(int i = 0; i < 5; i++){
		printf("%d ", *p);
		p++;
	}
	
	//EX09
	printf("\n[9] - Soma total: %i, Media: %.2f", soma(v2, 5), media_int(v2, 5));
	
	//EX10
	escala(d1, 5, 3);
	printf("\n[10] - Triplica vetor: ");
	float *l = &d1[0];
	
	for(int i = 0; i < 5; i++){
		printf("%.2f ", *l);
		l++;
	}
	
	//EX11
	printf("\n[11] - Vetor incial:");
	int *j = &v3[0];
	
	for(int i = 0; i < 5; i++){
		printf("%i ", *j);
		j++;
	}
	troca_extremos(v3, 5);
	printf("\nTroca extremos:");
	
	j = &v3[0];
	for(int i = 0; i < 5; i++){
		printf("%i ", *j);
		j++;
	}
	
	//EX12
	int k = filtra_caixa(o, 5, dest, 5, 15);
	printf("\n[12] - Ha %i numeros de 5 a 15", k);
	
	//EX13
	int min = indice_min(o, 5);
	int max = indice_max(o, 5);
	printf("\n[13] - Menor valor no indice: %i, Maior valor no indice: %i\n", min, max);
	
	//EX14
	int apagado = remove_primeiro(v4, 5);
	printf("[14] - Valor removido: %i", apagado);
	printf("\nVetor apos remocao: ");
	
	int *p_v4 = &v4[0];
	for(int i = 0; i < 4; i++){ 
		printf("%i ", *p_v4);
		p_v4++;
	}
	
	//EX15
	printf("\n[15] - Vetor original: ");
	int *p_v5 = &v5[0];
	
	for(int i = 0; i < 5; i++) {
		printf("%i ", *p_v5);
		p_v5++;
	}
	inverte(v5, 5);
	
	printf("\nVetor invertido:");
	p_v5 = &v5[0];
	for(int i = 0; i < 5; i++) {
        printf("%i ", *p_v5); 
        p_v5++;
    }
    
	return 0;
}

void inc(int x){ //EX01
	x++;
}
void troca_invalida(int x, int y){ // EX02
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void troca_ref(int *x, int *y){  //EX04
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void inc_ref(int *p){ //EX05
	if(!p) return;
	(*p)++;
}
int troca_se_maior(int *a, int *b){  //EX06
	if(!a || !b) return 0;
	if(*a > *b){
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
		
		return 1;
	}
	return 0;
}
void normaliza_trio(float *x, float *y, float *z){  //EX07
	if(!x || !y || !z) return;
	
	float m = (*x + *y + *z) / 3;
	*x = *x - m;
	*y = *y - m;
	*z = *z - m;
}
void zera(int *v, int n){       //EX08
	for(int i = 0; i < n; i++){
		*(v + i) = 0;
	}
}
int soma(const int *v, int n){     //EX09
	int total = 0;
	
	for(int i = 0; i < n; i++){
		total  += *(v + i);
	}
	return total;
}
float media_int(const int *v, int n){       //EX09
	if(n <= 0) return 0;
	
	return (float)soma(v, n) / n;
}
void escala(float *v, int n, float k){  //EX10
	if(v == NULL) return;

	for(int i = 0; i < n; i++){
		*(v + i) = *(v + i) * k;
	}
}
void troca_extremos(int *v, int n){ 	//EX11
	if(v == NULL) return;
	
	int temp = *v;
	*v = *(v+(n - 1));
	*(v+(n - 1)) = temp;
}
int filtra_caixa(const float *origem, int n, float *destino, float L, float U){    //EX12
	if(origem == NULL || destino == NULL) return 0;
	int copiados = 0;
	
	for(int i = 0; i < n; i++){
		float valor_atual = *(origem + i);
	
		if(valor_atual >= L && valor_atual <= U){
			*(destino + copiados) = valor_atual;
			copiados++;
		}
	}
	return copiados;
}
int indice_min(const float *v, int n){		//EX13
	if(v == NULL || n <= 0) return -1;
	
	int ind_min = 0;
	for(int i = 1; i < n; i++){
		if(*(v + i) < *(v + ind_min)){
			ind_min = i;
		}
	}
	return ind_min;
}
int indice_max(const float *v, int n){		//EX13
	if(v == NULL || n <= 0) return -1;
	
	int ind_max = 0;
	for(int i = 1; i < n; i++){
		if(*(v + i) > *(v + ind_max)){
			ind_max = i;
		}
	}
	return ind_max;
}
int remove_primeiro(int *v, int n){         //EX14
	if(v == NULL || n <= 0) return -1;
	
	int removido = *v;
	for(int i = 0; i < n - 1; i++){
		*(v + i) = *(v + i + 1);
	}
	return removido;
}
void inverte(int *v, int n) {				//EX15
	if (v == NULL || n < 0) return;

	for (int i = 0; i < n / 2; i++) {

		int temp = *(v + i);

		*(v + i) = *(v + (n - 1 - i));

		*(v + (n - 1 - i)) = temp;
	}
}

