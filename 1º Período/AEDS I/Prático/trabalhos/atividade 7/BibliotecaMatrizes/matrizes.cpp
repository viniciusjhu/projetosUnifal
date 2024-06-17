/* 
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Descrição: Biblioteca que realizam operações de matrizes
 * 
 * Created on 12 de junho de 2024, 16:15
 */

#include <cstdlib>
#include <iostream>
#include "matrizes.h"

using namespace std;

// Criando uma Matriz //

tMatriz criarMatriz(int linhas, int colunas) {
    tMatriz matriz;
    matriz.linhas = linhas;
    matriz.colunas = colunas;
    return matriz;
}

// APós criar a matriz, irá preenchê -la /

void preencherMatriz(tMatriz& matriz) {
    cout << "Digite os valores da matriz (" << matriz.linhas << "x" << matriz.colunas << "), um em cada linha: \n";
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            cin >> matriz.matArmazem[i][j];
        }
    }
}

// Função para exibir uma matriz formatada //

void imprimirMatriz(const tMatriz& matriz) {
    cout << "\n";
    for (int i = 0; i < matriz.linhas; ++i) {
        for (int j = 0; j < matriz.colunas; ++j) {
            cout << " " << matriz.matArmazem[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

// Operações de Matrizes //

tMatriz transpostaMatriz(const tMatriz& matriz) {
    tMatriz resultado = criarMatriz(matriz.colunas, matriz.linhas); // Chama a função que criará uma matriz resultado //
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            resultado.matArmazem[j][i] = matriz.matArmazem[i][j];
        }
    }
    return resultado;
}

tMatriz somaMatriz(const tMatriz& matriz1, const tMatriz& matriz2) {
    tMatriz resultado = criarMatriz(matriz1.linhas, matriz1.colunas); // Chama a função que criará uma matriz resultado //
    for (int i = 0; i < matriz1.linhas; i++) {
        for (int j = 0; j < matriz1.colunas; j++) {
            resultado.matArmazem[i][j] = matriz1.matArmazem[i][j] + matriz2.matArmazem[i][j];
        }
    }
    return resultado;
}

tMatriz multiplicacaoMatriz(const tMatriz& matriz1, const tMatriz& matriz2) {
    tMatriz resultado = criarMatriz(matriz1.linhas, matriz2.colunas); // Chama a função que criará uma matriz resultado //
    for (int i = 0; i < matriz1.linhas; ++i) {
        for (int j = 0; j < matriz2.colunas; ++j) {
            resultado.matArmazem[i][j] = 0;
            for (int k = 0; k < matriz1.colunas; ++k) {
                resultado.matArmazem[i][j] += matriz1.matArmazem[i][k] * matriz2.matArmazem[k][j];
            }
        }
    }
    return resultado;
}

double mediaMatriz(const tMatriz& matriz) {
    int soma = 0;
    for (int i = 0; i < matriz.linhas; ++i) {
        for (int j = 0; j < matriz.colunas; ++j) {
            soma += matriz.matArmazem[i][j];
        }
    }
    return (soma / (matriz.linhas * matriz.colunas));
}