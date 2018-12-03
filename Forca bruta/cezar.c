#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void descifrar (char text[], int chave) {
	int i = 0;

	while (text[i] != '\0') {
		if(text[i] == '#') text[i] = ' ';
		text[i] = text[i] - chave; //descifra
		
		i++;
	}
	printf("Descifrando: %s\n", text);
}

void cifrar (char text[], int chave) {
	int i = 0;
	while (text[i] != '\0') {
		if(text[i] == ' ') text[i] = '#';
		text[i] = text[i] + chave; //faz a cifra
		
		i++;
	}
	printf("Cifrado: %s\n", text);
}
int main () {
	char text[50], copia[50], cifrado[50];
	int chave;

	printf("A entrada deve conter apenas Letras Maiusculas ou Minusculas\n\n");
	printf("Digite a frase: ");
	scanf("%[^\n]s", text);
	printf("Digite um numero para ser a chave: ");
	scanf("%d", &chave);

	strcpy(copia, text); //usado para comparar se foi descifrado

	cifrar(text, chave);

	strcpy(cifrado, text); //texto cifrado originalmente

	chave = 0; //reseta a chave 

	while (1) {
		descifrar(text, chave );
		if (strcmp(copia, text) == 0) { //achou a chave
			printf("Chave: %d -> Texto:%s\n", chave, text);
			break;
		}
		else {
			strcpy(text, cifrado); 
			chave++; 		
		}
	}
	
	return 0;
}
