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
    int i, j, linhas, cont = 0;
    int colunaText = 0, ponto = 0;
    char chave[tam], copyChave[tam], text[50], cifra[70], menorLetra = ']';
    char alf[tam] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    srand(time(NULL)); //para não repetir as letras
    
    printf("Mensagem a ser Cifrada\n(apenas letras maiusculas)\n-->");
    scanf("%[^\n]s", text);
    printf("Chave:\n");
    scanf("%s", chave);
    printf("\n");

    /*Faz o tratamento para criar a tabela de transposição*/
    tiraEspaco(text);
    linhas = calcLinhas(strlen(text), strlen(chave)); //calcula a quant. de linhas necessárias
    char TRANSP[linhas][strlen(chave)];
    
    //preenche a tabela de transposição
    for (i = 0; i < linhas; i++) { 
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
    //IMPRIME A TABELA
    for (i = 0; i < linhas; i++) { 
        for (j = 0; j < strlen(chave); j++) printf("%c", TRANSP[i][j]);
        printf("\n");
    }

    //faz uma copia da chave de cifra
    strcpy(copyChave, chave);

    //tira da tabela e coloca na string cifrando
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
            cifra[ponto] = TRANSP[k][colunaText];
            ponto++; //ponto de parada na string
        }
    }
    
    printf("\nTexto Cifrado:\n%s\n", cifra);

    return 0;
}