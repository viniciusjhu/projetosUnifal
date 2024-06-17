/*
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 20 de maio de 2024, 16:15
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

const int TAM = 100000;

using namespace std;

//Gerando um vetor com posições aleatórios e não repetidos//
        
int main() {
    
    ofstream arquivo("vetor.txt");
    
    long int numAleatorios[TAM];
    long int temp, gerandoPosicao;
    
    srand (time(NULL));
    
    for(int i = 0; i < TAM; i++){
        
        numAleatorios[i] = -1;
        
    }

    for (int j = 0; j < TAM; j++) {
        gerandoPosicao = rand() % TAM;

        // Se a posição gerada está ocupada, procura a posição mais próxima disponível
        while (numAleatorios[gerandoPosicao] != -1) {
            gerandoPosicao = (gerandoPosicao + 1) % TAM;
        }

        numAleatorios[gerandoPosicao] = j;
    }

    for (long int k = 0; k < TAM; k++) {
        arquivo << "Vetor [" << k << "]: " << numAleatorios[k] << endl;
    }

    return 0;
    
}

