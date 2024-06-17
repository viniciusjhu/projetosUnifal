/* 
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Descrição: Biblioteca com os Algoritmos de Ordenação
 * 
 * Created on 03 de junho de 2024, 16:10
 */

//Algoritmos de Ordenação//

#include <iostream>
#include <time.h>

using namespace std;

//Algoritmo coloca o maior elemento sempre nas últimas posições//

void BubbleSort(int v[], int tam){
 
    long int BubbleCount = 0;
    int vAnterior;

    for (int i = 0; i < tam; i++) {

        for (int j = i + 1; j < tam; j++) {
            
            BubbleCount += 2;
            if (v[i] > v[j]) {

                vAnterior = v[i];
                v[i] = v[j];
                v[j] = vAnterior;
                BubbleCount += 4;

            }
            
            BubbleCount += 1;
        }
        
        BubbleCount += 1;

    }
    
    cout << "\n Número de operações com " << tam << ": " << BubbleCount <<endl;
}

//Algoritmo passa sempre o menor valor do vetor para a primeira posição//

void SelectionSort(int v[], int tam) {
    
    long int SelectionCount = 0;
    int aux, pos;

    for (int i = 0; i < tam; i++) {

        aux = v[i];
        SelectionCount += 1;
        pos = i;

        for (int j = i + 1; j < tam; j++) {
            
            SelectionCount += 1;
            if (v[j] < aux) {

                aux = v[j];
                pos = j;
                SelectionCount += 1;
            }
            
            SelectionCount += 1;
        }
        
        aux = v[i];
        v[i] = v[pos];
        v[pos] = aux;
        SelectionCount += 4;

    }
    
    cout << "\n Número de operações com " << tam << ": " << SelectionCount << endl;

}

//Algoritmo que vai deixando os elementos mais à esquerda ordenados//

void InsertionSort(int v[], int tam) {
    
    long int InsertionCount = 0;
    int vAnterior, aux, j;

    for (int i = 1; i < tam; i++) {

        aux = v[i];
        j = i - 1;
        
        InsertionCount += 1;
        while (j >= 0 && v[j] > aux) {

            v[j + 1] = v[j];
            j--;
            InsertionCount += 2;
        }
        
        InsertionCount += 3;
        v[j + 1] = aux;

    }
    
    cout << "\n Número de operações com " << tam << ": " << InsertionCount << endl;

}