#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define tam 26

int searchLetra(char alf[tam], char letra) {
    int i;
    for (i = 0; i < tam; i++) {
        if(alf[i] == letra) break;
    }
    return i;
}

int main() {
    char text[50], chave[tam];
    char alf[tam] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i, j;
    bool ok = false;

    printf("Mensagem a ser Cifrada\n(apenas letras maiusculas)\n-->");
    scanf("%[^\n]s", text);
    printf("Chave: ");
    scanf("%s", chave);

    /*Complementa a chave com as demais letras do alfabeto*/
    for (i = 0; i < tam; i++) { //alfabeto (cada i é uma letra verificando)
        ok = false;
        for (j = 0; j < strlen(chave); j++) { 
            if(alf[i] == chave[j]) { //a letra verificada esta na chave
                ok = true;
                break;
            }   
        }
        //A letra não esta na chave
        if (ok == false) chave[j] = alf[i]; //entao é inserida
    }

    /*Cifrando*/
    for (i = 0; i < strlen(text); i++) {
        if(text[i] != ' ') {
            int pos = searchLetra(alf, text[i]);
            text[i] = chave[pos];
        }
    }
    printf("Texto cifrado: %s\n", text);

    /*Descifrando*/
    for (i = 0; i < strlen(text); i++) {
        if(text[i] != ' ') {
            int pos = searchLetra(chave, text[i]);
            text[i] = alf[pos];
        }
    }

    printf("Texto descifrado: %s\n", text);

    return 0;
}
