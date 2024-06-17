/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 27 de maio de 2024, 16:11
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int menu(){
    
    int opcao;
    
        
    cout << "1: Insirir um valor" <<endl;
    cout << "2: Buscar um valor" <<endl;
    cout << "3: Sair" <<endl;
    cout << "Digite a opção: ";
    cin >> opcao;

    while (opcao <= 0 || opcao > 4) {

        cout << "Digite novamente a opção correta: ";
        cin >> opcao;

    }   
    
    return opcao;
    
}

void BubbleSort(int v[], int tam){
    
    for(int i; i < tam; i++){
        
        cout << "" << v[i] <<endl;
        
    }    
    
    cout <<endl;
    
}

//
        
int main() {
    
    const int TAM = 10;
    int vetor[10] = {7, 8, 4, 2, 1, 3, 9, 10, 6, 5};
    
    do{
    
        switch(menu()){
        
            case 1:
            
                cout << "Insira o valor que deseja: " <<endl;
                BubbleSort(vetor, TAM);
            
            break;    
        
            case 2:
            
                cout << "Digite o valor que deseja buscar: " <<endl;
            
            break;  
        
        }
    
    } while(menu() != 3);
    
    return 0;
}