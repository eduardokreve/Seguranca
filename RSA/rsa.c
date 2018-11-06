#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"
#define MAX 50
#define e 3
 

void clear() { //https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

int primo(int X) {
	int i, cont = 0;

	for(i = 1; i <= X; i++) if(X % i == 0) cont++;

	if(cont == 2) return X; //é primo

	else if(cont > 2 || cont < 2){
		clear();
		printf("Numero digitado nao eh impar\nDigite novamente: ");
		scanf("%d", &X);
		primo(X);
	}

	return X;
}

int chavePriv(int tot) {

	return ((2 * tot+1) / e);
}

long long int cifrar(char text[], int tot, int n) {
	int i, valor[MAX];
	long long int c;

	//converter a entrada para decimal
	for (i = 0; i < strlen(text); i++) valor[i] = (int)(text[i]);

	//transforma o vetor em um unico inteiro
	for (i = 0; i < strlen(text); i++) {
		printf("%d\n", valor[i]);
		
	}
	
	printf("%lld\n", c);

	return 0;
}

int main() {
	int n = 0, p = 0, q = 0, totiente, priv;
	long long int valorCifr;
	char text[MAX];

	printf("Digite a frase a ser cifrada: ");
	scanf("%[^\n]s", text);

	printf("p: ");
	scanf("%d", &p);
	p = primo(p);

	printf("q: ");
	scanf("%d", &q);
	q = primo(q);

	/*Calcula os valores necessarios para cifrar*/
	n = p * q; //calcula n
	totiente = (p-1)*(q-1); //calcula o totiente
	priv = chavePriv(totiente); //define a chave privada

	printf("chaves publicas: %d e %d\n", n, e);
	printf("Chave privada: %d\n", priv);

	valorCifr = cifrar(text, totiente, n);

	return 0;
}
