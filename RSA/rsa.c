/*Para compilar: gcc rsa.c -o r -lm && ./r   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"
#define MAX 50
#define e 5
 

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

void cifrar(int cifra[], char text[], int n) { 
	int i, t = strlen(text);
	long long int elevado = 0;

	//converter a entrada para decimal
	for (i = 0; i < t; i++) cifra[i] = (int)(text[i]);
	
	/*Faz a criptografia para cada valor do vetor*/
	for (i = 0; i < t; i++) {
		elevado = (pow(cifra[i], e));
		cifra[i] = elevado % n;
	}
}

void imprime(int cifra[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("%d ", cifra[i]);
	}
	printf("\n");
}

int main() {
	int n = 0, p = 0, q = 0, totiente, priv;
	int cifra[MAX];
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

	//cifra o texto
	cifrar(cifra, text, n);
	printf("Texto Cifrado:\n");
	imprime(cifra, strlen(text));

	return 0;
}
