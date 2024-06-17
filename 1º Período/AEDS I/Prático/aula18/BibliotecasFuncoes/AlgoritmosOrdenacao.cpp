/* 
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Descrição: Biblioteca com os Algoritmos de Ordenação
 * 
 * Created on 03 de junho de 2024, 16:10
 */

//Algoritmos de Ordenação//

#include <iostream>

using namespace std;

//Algoritmo coloca o maior elemento sempre nas últimas posições//

void BubbleSort(int v[], int tam) {

    int vAnterior;
    
    cout << "\n Ordenando o vetor: ";
    for (int i = 0; i < tam; i++) {
        cout << v[i] << ",";
    }

    for (int i = 0; i < tam; i++) {

        for (int j = i + 1; j < tam; j++) {

            if (v[i] > v[j]) {

                vAnterior = v[i];
                v[i] = v[j];
                v[j] = vAnterior;

            }

        }

    }

    cout << endl;
    
    cout << "\n Ordenação concluída com sucesso!" <<endl;

    for (int i = 0; i < tam; i++) {

        cout << "\n Vetor[" << i << "]:" << v[i];
    }

    cout << endl;
}

//Algoritmo passa sempre o menor valor do vetor para a primeira posição//

void SelectionSort(int v[], int tam) {

    int aux, pos;

    cout << "\n Ordenando o vetor: ";
    for (int i = 0; i < tam; i++) {
        cout << v[i] << ",";
    }

    for (int i = 0; i < tam; i++) {

        aux = v[i];
        pos = i;

        for (int j = i + 1; j < tam; j++) {

            if (v[j] < aux) {

                aux = v[j];
                pos = j;

            }

        }

        aux = v[i];
        v[i] = v[pos];
        v[pos] = aux;

    }

    cout << endl;
    
    cout << "\n Ordenação concluída com sucesso!" <<endl;

    for (int i = 0; i < tam; i++) {

        cout << "\n Vetor[" << i << "]:" << v[i];
    }

    cout << endl;

}

//Algoritmo que vai deixando os elementos mais à esquerda ordenados//

void InsertionSort(int v[], int tam) {

    int vAnterior, aux, j;

    cout << "\n Ordenando o vetor: ";
    for (int i = 0; i < tam; i++) {
        cout << v[i] << ",";
    }

    for (int i = 1; i < tam; i++) {

        aux = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > aux) {

            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = aux;

    }

    cout << endl;
    
    cout << "\n Ordenação concluída com sucesso!" <<endl;
    
    for (int i = 0; i < tam; i++) {

        cout << "\n Vetor[" << i << "]:" << v[i];
    }

    cout << endl;

}