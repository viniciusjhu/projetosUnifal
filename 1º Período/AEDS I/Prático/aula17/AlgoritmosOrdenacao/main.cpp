/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 28 de maio de 2024, 10:40
 */

#include <cstdlib>
#include <iostream>

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

//Algoritmos de Ordenação//
//Algoritmo coloca o maior elemento sempre nas últimas posições//
void BubbleSort (int v[], int tam){
    
    int vAnterior;
    
    separador();
    
    cout << "\n Ordenando o vetor: ";
    for(int i = 0; i < tam; i++){
        cout << v[i] << ",";
    }
    
    for(int i = 0; i < tam; i++){
        
        for(int j = i+1; j < tam; j++){
            
            if(v[i] > v[j]){
                
                vAnterior = v[i];
                v[i] = v[j];
                v[j] = vAnterior;
                
            }    
            
        }    
        
    }
    
    cout << endl;
    
    for(int i = 0; i < tam; i++){
        
        cout << "\n Vetor[" << i << "]:" << v[i];
    }            
    
    cout << endl;
}

//Algoritmo passa sempre o menor valor do vetor para a primeira posição//
void SelectionSort (int v[], int tam){
    
    int aux, pos;
    
    cout << "\n Ordenando o vetor: ";
    for (int i = 0; i < tam; i++) {
        cout << v[i] << ",";
    }
    
    for(int i = 0; i < tam; i++){
       
        aux = v[i];
        pos = i;
        
        for(int j = i + 1; j < tam; j++){
            
            if(v[j] < aux){
                
                aux = v[j];
                pos = j;
                
            }
            
        }
        
        aux = v[i];
        v[i] = v[pos];
        v[pos] = aux;
        
    }

    cout << endl;

    for (int i = 0; i < tam; i++) {

        cout << "\n Vetor[" << i << "]:" << v[i];
    }

    cout << endl;
    
}

//Algoritmo que vai deixando os elementos mais à esquerda ordenados//
void InsertionSort (int v[], int tam){

    int vAnterior, aux, j;

    cout << "\n Ordenando o vetor: ";
    for (int i = 0; i < tam; i++) {
        cout << v[i] << ",";
    }

    for(int i = 1; i < tam; i++){
        
        aux = v[i];
        j = i - 1;
        
        while(j >= 0 && v[j] > aux){
          
            v[j + 1] = v[j];
            j--;
        }
        
        v[j+1] = aux;
        
    }
    
    cout << endl;

    for (int i = 0; i < tam; i++) {

        cout << "\n Vetor[" << i << "]:" << v[i];
    }

    cout << endl;
    
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
                
            BubbleSort(vetor, TAM);
                
        break; 
            
        case 2:
                
            SelectionSort(vetor, TAM);
                
        break;    
            
        case 3:
                
            InsertionSort(vetor, TAM);
                
        break;    
    }
    
    return 0;
}