/* 
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Descrição: Biblioteca para gerar diferentes vetores
 * 
 * Created on 10 de junho de 2024, 16:10
 */

#include <iostream>
#include <time.h>

using namespace std;

void VetorAleatorio(int *v, int qtd) {
    int gerandoPosicao;
    srand(time(NULL));

    for (int i = 0; i < qtd; i++) {

        v[i] = -1;

    }

    for (int j = 0; j < qtd; j++) {
        gerandoPosicao = rand() % qtd;

        // Se a posição gerada está ocupada, procura a posição mais próxima disponível
        while (v[gerandoPosicao] != -1) {
            gerandoPosicao = (gerandoPosicao + 1) % qtd;
        }

        v[gerandoPosicao] = j;
    }
}

void VetorCrescente(int *v, int qtd) {

    for (int i = 0; i < qtd; i++) {
        v[i] = i;
    }
}

void VetorDecrescente(int *v, int qtd) {

    for (int i = qtd; i > 0; i--) {
        v[qtd-i] = i;
    }
}
