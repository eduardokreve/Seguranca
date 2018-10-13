#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	1 passo: converter a entrada e a chave para Hexadecimal(chave de 128 bits ou seja, 16 carac.)
	2 passo: colocar na matriz de estado (4x4)
	3 passo: soma exclusiva entre os bytes da mensagem e da chave (func. addRoundKey)
	e assim por diante.
	Funções principais por ordem de execução:

	addRoundKey 1x

	subBytes 9x
	shiftRows 9x
	mixColumns 9x

	subBytes 1x
	shiftRows 1x
	addRoundKey 1x

	Função para gerar subchaves:

	keyExpansion (10x)
	rotWord (10x) eu acho
	
	Fonte: https://www.youtube.com/watch?v=tzj1RoqRnv0
*/

int main(){
	
        
    return 0;
}
