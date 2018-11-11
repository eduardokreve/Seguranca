/*Para compilar: gcc rsa.c -o r -lm && ./r   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50
 
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

long long int chavePriv(int tot, int e) {
	return ((2 * tot+1) / e);
}

void cifrar(long long int cifra[], char text[], long long n, long long e) { 
	int i, j, tam = strlen(text);
	long long int elevado = 0;
	char alf[26] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	//PEGA A ENTRADA E TRANSFORMA SEGUINDO A ORDEM DOS NUMEROS DO ALF.ABETO
	for (i = 0; i < tam; i++) {
		for(j = 0; j < 26; j++) {
			if(text[i] == alf[j]) {
				cifra[i] = j;
			}
		}
	}

	/*Faz a criptografia para cada valor do vetor*/
	for (i = 0; i < tam; i++) {
		elevado = (pow(cifra[i], e));
		cifra[i] = elevado % n;
	}
}

int verificaPrimo(int p){
	int i;
	double j;
	
	//Calcula a raiz quadrada para p
	j = sqrt(p);

	for(i = 2; i <= j; i++){
		//Retorna 0 caso não seja um número primo
		if(p%i == 0)
			return 0;
	}

	//Retorna 1 quando é um número primo
	return 1;
}

int escolheE(int tot, int p, int q, int n) {
	int e = 0, i;

	for(i = 2; i < tot; i++){

		if(tot%i != 0 && verificaPrimo(i) && i != p && i != q){
			e = i;
			break;
		}
	}
	return e;
}

void imprime(long long int cifra[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("%lld ", cifra[i]);
	}
	printf("\n");
}

void descifrar(long long int cifra[], long long int priv, long long int n, int tam) {
	int i;
	long long int elevado = 0;

	for (i = 0; i < tam; i++) {
		elevado = (pow(cifra[i], priv));
		cifra[i] = elevado % n;
	}
}	

void converteChar(long long int cifra[], char text[]) {
	int i, tam = strlen(text);
	char alf[26] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	for (i = 0; i < tam; i++) {
		text[i] = alf[cifra[i]];
	}
	printf("\nTexto legivel: %s\n", text);
}


int main() {
	long long int n = 0, p = 0, q = 0, totiente, priv, tamText, e;
	long long int cifra[MAX];
	char text[MAX];

	printf("Entre somente com letras maiusculas\nDigite a frase a ser cifrada: ");
	scanf("%[^\n]s", text);

	tamText = strlen(text);

	printf("p: ");
	scanf("%lld", &p);
	p = primo(p);

	printf("q: ");
	scanf("%lld", &q);
	q = primo(q);

	/*Calcula os valores necessarios para cifrar*/

	n = p * q; //uma das chaves publicas
	totiente = (p - 1)*(q - 1); //calcula o totiente
	e = escolheE(totiente, p, q, n);
	priv = chavePriv(totiente, e); //define a chave privada

	printf("chaves publicas: %lld e %lld\n", n, e);
	printf("Chave privada: %lld\n\n", priv);

	//cifra o texto
	cifrar(cifra, text, n, e);
	printf("Texto Cifrado:");
	imprime(cifra, tamText);

	//descifra o texto
	printf("Texto Descifrado:");
	descifrar(cifra, priv, n, tamText);
	
	imprime(cifra, tamText);
	converteChar(cifra, text);
	
	return 0;
}
