/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 5 de junho de 2024, 12:41
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include "AlgoritmosOrdenacao.h"
#include "GerarVetor.h"

using namespace std;

void separador() {

    cout << "\n-------------------------------------------------------------" << endl;

}

int menu() {

    int opcao;

    separador();
    cout << "\n Escolha qual opção deseja proseguir: " << endl;
    cout << "\n 1: Algoritmo Bubble Sort";
    cout << "\n 2: Algoritmo Selection Sort";
    cout << "\n 3: Algoritmo Insertion Sort";
    cout << "\n 4: Sair" << endl;
    cout << "\n Digite a opção desejada: ";
    cin >> opcao;
    separador;

    while (opcao <= 0 || opcao > 4) {

        cout << "\n Digite novamente uma opção válida: ";
        cin >> opcao;

    }

    return opcao;

}

//  //
int main() {
    
    ofstream arquivo("vetor.txt");
    
    separador();
    cout << "\n \t Algoritmos de Ordenação " << endl;
    separador();
    
    const int TAM = 30000;
    int vector[TAM];
    
    switch(menu()){
        
        case 1:
            
           VetorAleatorio(vector, TAM);
           BubbleSort(vector, TAM);
           
           VetorCrescente(vector, TAM);
           BubbleSort(vector, TAM);
           
           VetorDecrescente(vector, TAM);
           BubbleSort(vector, TAM);
                   
        break; 
        
        case 2:
            
            VetorAleatorio(vector, TAM);
            SelectionSort(vector, TAM);

            VetorCrescente(vector, TAM);
            SelectionSort(vector, TAM);

            VetorDecrescente(vector, TAM);
            SelectionSort(vector, TAM);
            
        break;    
        
        case 3:

            VetorAleatorio(vector, TAM);
            InsertionSort(vector, TAM);

            VetorCrescente(vector, TAM);
            InsertionSort(vector, TAM);

            VetorDecrescente(vector, TAM);
            InsertionSort(vector, TAM);
            
        break;    
    }

    return 0;
}