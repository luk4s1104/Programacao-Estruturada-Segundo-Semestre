#include <stdio.h>

int a = 4, b = 6, r, p, m, l, g;

int soma(int x, int y); 
int par(int n);
int maior(int x, int y);
int potencia(int expoente, int base);
int fatorial(int f);

int main(){
    r = soma(a, b); 
    p = par(r);
    m = maior(a, b);
    l = potencia(a, b);
    g = fatorial(a);
    
    printf("Soma: %i\n", r); 
    printf("Par: %i\n", p);
    printf("Maior: %i\n", m);
    printf("Potencia:%i\n", l);
    printf("Fatorial:%i\n", g);
    return 0;
}

int soma(int x, int y) {
    return x + y;
}

int par(int n){
	if(n % 2 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int maior(int x, int y){
	if(x > y){
		return x;
	}
	else
		return y;
}

int potencia(int expoente, int base){
	int res = 1;
	for(int i = 0; i < expoente; i++){
		res = res * base;
	}
	return res;
}

int fatorial(int f){
	if(f == 1 || f == 0){
		return 1;
	}
	else{
		return f * fatorial(f - 1);
	}
}



