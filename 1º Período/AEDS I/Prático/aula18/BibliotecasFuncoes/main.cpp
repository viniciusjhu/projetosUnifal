/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 03 de junho de 2024, 16:10
 */

#include <cstdlib>
#include <iostream>
#include "AlgoritmosOrdenacao.h"
#include ""

using namespace std;

void separador(){
    
    cout << "\n-------------------------------------------------------------" << endl;
    
}

int menu(){
    
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
    
    while(opcao <= 0 || opcao > 4){
        
        cout << "\n Digite novamente uma opção válida: ";
        cin >> opcao;
        
    }
    
    return opcao;
    
}

// Atividade utilizando funções e algoritmo de ordenação//
int main() {
    
    int opcao;
    
    separador();
    cout << "\n \t Algoritmos de Ordenação " << endl;
    separador();

    const int TAM = 10;
    int vetor[TAM] = {7, 8, 4, 2, 1, 3, 9, 10, 6, 5};
    
    switch(menu()){
            
        case 1:
                
            separador();
            BubbleSort(vetor, TAM);
                
        break; 
            
        case 2:
                
            separador();
            SelectionSort(vetor, TAM);
                
        break;    
            
        case 3:
                
            separador();
            InsertionSort(vetor, TAM);
                
        break;    
    }
    
    return 0;
}