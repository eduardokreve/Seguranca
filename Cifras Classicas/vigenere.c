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

int main() {
    int i, j;
    int lin, col; 
    char text[50];
    char chave[tam];
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

    printf("Mensagem a ser Cifrada\n(apenas letras maiusculas)\n-->");
    scanf("%[^\n]s", text);
    printf("Chave: ");
    scanf("%s", chave);
    
    /*Cifrar*/
    lin = col = 0;

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

    /*Descifrar*/
    lin = col = 0;

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

    return 0;
}
