#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 26

void tiraEspaco(char text[50]) {
    int j = 0;

    for (int i = 0; i <= strlen(text); i++) {
        if (text[i] != ' ') {
            text[j] = text[i];
            j++;
        }   
    }
}

//calcula quantas linhas são necessárias para a tabela de transposição
int calcLinhas(float tamText, float tamChav) {
    float valor = tamText/tamChav;
    
    if (valor == (int)valor) return valor;
    else return valor+1; 
}

int main() {
    srand(time(NULL));

    int i, j, linhas, cont = 0;
    char text[50];
    char chave[tam];
    char alf[tam] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    printf("Mensagem a ser Cifrada\n(apenas letras maiusculas)\n-->");
    scanf("%[^\n]s", text);
    printf("Chave: ");
    scanf("%s", chave);

    /*Faz o tratamento para criar a tabela de transposição*/
    tiraEspaco(text);
    linhas = calcLinhas(strlen(text), strlen(chave)); //calcula a quant. de linhas necessárias
    char TRANSP[linhas][strlen(chave)];

    for (i = 0; i < linhas; i++) { //preenche a tabela de transposição
        for (j = 0; j < strlen(chave); j++) {

            if (cont < strlen(text)) { //preenche com o texto ate acabar
                TRANSP[i][j] = text[cont];
                cont++;
            }
            else { //depois usa letras aleatorias do alfabeto
                int LETRA = rand () % 26;
                TRANSP[i][j] = alf[LETRA]; 
            }  
        }
    }

    for (i = 0; i < linhas; i++) { //preenche a tabela de transposição
        for (j = 0; j < strlen(chave); j++) {
            printf("%c", TRANSP[i][j]);
        }
        printf("\n");
    }







    return 0;
}