/* 
 * File:   matrizes.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on 3 de junho de 2024, 16:56
 */

#include <cstdlib>
#include <iostream>

#define TAM 2

using namespace std;

// Código para manipular soma de matrizes //

int main() {
    int mat1[TAM][TAM];
    int mat2[TAM][TAM];
    int soma[TAM][TAM];

    cout << "\nDigite a primeira matriz para soma:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "\nAgora, digite a segunda matriz para soma:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cin >> mat2[i][j];
        }
    }

    cout << "\nSomando as matrizes: " << endl;

    // Mostrando a matriz 1
    cout << "\nMatriz 1:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    // Mostrando a matriz 2
    cout << "\nMatriz 2:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }

    // Calculando e mostrando a matriz soma
    cout << "\nMatriz Soma:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            soma[i][j] = mat1[i][j] + mat2[i][j];
            cout << soma[i][j] << " ";
        }
        cout << endl; 
    }

    return 0;
}