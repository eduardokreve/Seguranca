#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 26

void tiraEspaco (char text[50]) {
	int j = 0;

	for (int i = 0; i <= strlen(text); i++) {
		if (text[i] != ' ') text[j++] = text[i];
	}
}

//calcula quantas linhas são necessárias para a tabela de transposição
int calcLinhas (float tamText, float tamChav) {
	float valor = tamText/tamChav;
	
	if (valor == (int)valor) return valor;
	else return valor+1; 
}

int comparaString (char text[], char original[], int n) {
	int i;

	for (i = 0; i < n; i++) {
		if(text[i] != original[i]) return 0;

	}

	return 1;
} 

void descifrar (char alf[], char text[], char chave[], char TRANSP[][tam], int linhas, int colunaText) {
	int i, j, k, cont = 0;
	char menorLetra = ']';
	/*Descifrar*/
	cont = 0;
	for (j = 0; j < strlen(chave); j++) { //Coloca a mensagem cifrada de volta na tabela
		for (i = 0; i < linhas; i++) TRANSP[i][j] = text[cont++];
	}
	char tabela[linhas][strlen(chave)];

	//reordena a tabela
	cont = 0;
	for (j = 0; j < strlen(chave); j++) { 
		menorLetra = ']';
		for (i = 0; i < strlen(chave); i++) { //acha a menor letra
			if (chave[i] < menorLetra) {
				menorLetra = chave[i];
				colunaText = i; //é a posição onde tem a menor letra na chave
			}
		}
		chave[colunaText] = 'a'; //para não achar a mesma letra e repetir a coluna

		for (k = 0; k < linhas; k++) {
			tabela[k][colunaText] = TRANSP[k][cont]; //coloca na ordem original
		}
		cont++;
	}

	//Coloca a tabela na string original
	cont = 0;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < strlen(chave); j++) text[cont++] = tabela[i][j];
	}

	printf("\nTexto Descifrado:\n%s\n", text);
}

void cifrar (char alf[], char text[], char chave[]) {
	int i, j, linhas, cont = 0, colunaText = 0, posicaoChave = 0, posicaoAlf = 0;
	char menorLetra = ']', copyChave[tam], original[50];

	srand(time(NULL)); //para não repetir as letras

	/*Faz o tratamento para criar a tabela de transposição*/
	tiraEspaco(text);
	linhas = calcLinhas(strlen(text), strlen(chave)); //calcula a quant. de linhas necessárias
	char TRANSP[linhas][strlen(chave)];
	
	//preenche a tabela de transposição
	for (i = 0; i < linhas; i++) { 
		for (j = 0; j < strlen(chave); j++) {
			if (cont < strlen(text)) { //preenche com o texto ate acabar
				TRANSP[i][j] = text[cont++];
			}
			else { //depois usa letras aleatorias do alfabeto
				int LETRA = rand () % 26;
				TRANSP[i][j] = alf[LETRA]; 
			}  
		}
	}
	//IMPRIME A TABELA
	printf("\n");
	for (i = 0; i < linhas; i++) { 
		for (j = 0; j < strlen(chave); j++) printf("%c", TRANSP[i][j]);
		printf("\n");
	}

	strcpy(copyChave, chave); //faz uma copia da chave de cifra
	strcpy(original, text); //para comparar na hora de achar a chave
	

	/*Cifrar*/
	//tira da tabela e coloca na string cifrando
	cont = 0;
	for (j = 0; j < strlen(chave); j++) { 
		menorLetra = ']';
		for (i = 0; i < strlen(chave); i++) { //acha a menor letra
			if (copyChave[i] < menorLetra) {
				menorLetra = copyChave[i];
				colunaText = i;
			}
		}
		copyChave[colunaText] = 'a'; //para não achar a mesma letra e repetir a coluna
	  
		for (int k = 0; k < linhas; k++) {
			text[cont++] = TRANSP[k][colunaText];
		}
	}
	
	printf("\nTexto Cifrado:\n%s\n", text);

	//vai tentar achar a chave
	char keyTent[tam], mensagCifrada[tam];
	keyTent[posicaoChave] = alf[posicaoAlf]; //valor inicial

	strcpy(mensagCifrada,text); //mensagem cifrada originalmente

	while (1) { 
		descifrar(alf, text, keyTent, TRANSP, linhas, colunaText);

		if (comparaString(text, original, strlen(original)) == 1) { //achou a chave
			printf("Chave: %s --> Texto: %s\n", keyTent, text);
		}
		else {
			strcpy(text, mensagCifrada); //retorna a mensagem cifrada originalmente
			

			if(keyTent[posicaoChave] == 'Z') {
				//pensar como vai mudar a sequencia de chaves possiveis
			}
		}
	}
}

int main() {
	char chave[tam], text[50];
	char alf[tam] = {'A','B','C','D','E','F','G','H','I','J','K','L',
					'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	printf("Mensagem a ser Cifrada\n(apenas letras maiusculas)\n-->");
	scanf("%[^\n]s", text);
	printf("Chave (letras nao repetidas): ");
	scanf("%s", chave);

	
	cifrar(alf, text, chave);
	return 0;
}