#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 26

//Retorna a LINHA do caractere no quadrado de vigenere
int searchCarac(char letra, char vig[tam][tam]) { 
	int i;

	for (i = 0; i < tam; i++) {
		if(vig[i][0] == letra) break;
	}
	return i; 
}

//Retorna a coluna
int searchColuna(int linha, char vig[tam][tam], char letra) {
	int i;

	for (i = 0; i < tam; i++) {
		if (vig[linha][i] ==  letra) break;
	}

	return i;
}

void descifrar (char text[], char vig[][tam], char chave[]) {
	int lin = 0, col = 0, i, j;

	while (text[lin] != '\0') {
		if(text[lin] != ' ') {
			j = searchCarac(chave[col], vig);
			i = searchColuna(j, vig, text[lin]); //linha, vigenere, letra

			text[lin] = vig[0][i];

			col++;
			if (col >= strlen(chave)) col = 0;   
		}
		lin++;
	}

	printf("Texto descifrado: %s\n",text); 
}

void cifrar (char text[], char vig[][tam], char chave[]) {
	int lin = 0, col = 0, i, j;

	while (text[lin] != '\0') {
		if(text[lin] != ' ') {
			i = searchCarac(text[lin], vig);
			j = searchCarac(chave[col], vig);

			text[lin] = vig[i][j]; //troca o caract. pela letra correspondente pela chave e o texto no quadrado de vig.

			col++;
			if (col >= strlen(chave)) col = 0;
		}
		lin++;
	}
	printf("\nTexto cifrado: %s\n",text); 
}

int main() {
	int lin, col, i; 
	char text[50], copia[50], cifrado[50];
	char chave[tam], keyAux[5];
	char vig[tam][tam]; //tabela
	char alf[tam] = {'A','B','C','D','E','F','G','H','I','J','K','L',
					'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	/*Cria o quadrado de Vigenere*/
	for (lin = 0; lin < tam; lin++) {
		i = lin;
		for (col = 0; col < tam; col++) {
			if (i >= tam) i = 0;
			vig[lin][col] = alf[i++];
		}
	}

	FILE *dic = fopen("wordlist.txt", "r");

	printf("Mensagem a ser Cifrada\n(apenas letras maiusculas)\n-->");
	scanf("%[^\n]s", text);
	printf("Chave (5 caracteres todos maiusculos): ");
	scanf("%s", chave);

	strcpy(copia, text);
	
	cifrar(text, vig, chave); //usado para comparar se foi descifrado
	
	strcpy(cifrado, text); //texto cifrado originalmente

	while (fgets(keyAux, 6, dic) != NULL) { //vai percorrer o dicionario
		descifrar(text, vig, keyAux);
		
		if (strcmp(copia, text) == 0) { //achou a chave
			printf("Chave: %s -> Texto:%s\n", keyAux, text);
			break;
		}
		else {
			strcpy(text, cifrado); 	//retorna o texto cifrado 
		}

	}
	
   

	return 0;
}
