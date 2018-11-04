#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"

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

	for(i = 1; i <= X; i++) {
		if(X % i == 0) cont++;
	}

	if(cont == 2) return X; //é primo

	else if(cont > 2 || cont < 2){
		clear();
		printf("Numero digitado nao eh impar\nDigite novamente: ");
		scanf("%d", &X);
		primo(X);
	}

	return X;
}

/*int calcE(int n) {
	int i

}
*/
int main() {
	int n = 0, p = 0, q = 0, totiente, e;

	printf("p: ");
	scanf("%d", &p);
	p = primo(p);

	printf("q: ");
	scanf("%d", &q);
	q = primo(q);

	n = p * q;
	printf("%d = %d * %d\n", n, p, q);

	//calcula chave publica
	totiente = (p-1)*(q-1);
	calcE(totiente);

	return 0;
}
