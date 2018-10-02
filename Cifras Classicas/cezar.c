#include <stdio.h>
#include <stdlib.h>

int main() {
	char text[50];
	int i = 0, chave = 3;

	printf("A entrada deve conter apenas Letras Maiusculas ou Minusculas\n\n");
	printf("Digite a frase: ");
	scanf("%[^\n]s", text);

	/*Cifrar*/
	while (text[i] != '\0') {
		if(text[i] == ' ') text[i] = '#';
		else {
			if(text[i] >= 88 && text[i] < 91) { //limita o intervalo para letras Maiusculas
				text[i] = text[i] - 26;
			}
			else if (text[i] >= 120 && text[i] < 123) { //limita o intervalo para letras Minusculas
				text[i] = text[i] - 26;
			}
			text[i] = text[i] + chave; //faz a cifra
		}
		i++;
	}
	printf("Cifrado: %s\n", text);

	/*Descifrar */
	i = 0;
	while (text[i] != '\0') {
		if(text[i] == '#') text[i] = ' ';
		else {
			if( text[i] >= 65 && text[i] <= 67 ) {
				text[i] = text[i] + 26;
			}
			else if(text[i] >= 97 && text[i] <= 99) {
				text[i] = text[i] + 26;
			}
			text[i] = text[i] - chave; //descifra
		}
		i++;
	}
	printf("Descifrado: %s\n", text);

	return 0;
}
