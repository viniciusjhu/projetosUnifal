/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on June 12, 2024, 4:15 PM
 */

#include <cstdlib>
#include <iostream>
#include "matrizes.h"

using namespace std;

void separador() {

    cout << "\n-------------------------------------------------------------" << endl;

}

int menu() {

    int opcao;

    separador();
    cout << "\n Escolha qual opção deseja proseguir: " << endl;
    cout << "\n 1: Transposta da matriz";
    cout << "\n 2: Soma das matrizes";
    cout << "\n 3: Multiplicacao das matrizes";
    cout << "\n 4: Media dos valores da matriz";
    cout << "\n 5: Sair" << endl;
    cout << "\n Digite a opção desejada: ";
    cin >> opcao;
    separador;

    while (opcao <= 0 || opcao > 5) {

        cout << "\n Digite novamente uma opção válida: ";
        cin >> opcao;

    }

    return opcao;

}

// Programa que realiza operações com matrizes //

int main() {

    int linhas, colunas;
    
    cout << "\nDigite o número de linhas das matrizes: ";
    cin >> linhas;
    
    cout << "\nAgora, digite o número de colunas das matrizes: ";
    cin >> colunas;

    tMatriz mat1 = criarMatriz(linhas, colunas);
    tMatriz mat2 = criarMatriz(linhas, colunas);
    
    separador();
    cout << "Antes de realizar as operações, vamos preencher a primeira matriz!" <<endl;
    preencherMatriz(mat1);
    cout << "\n A 1ª matriz informada é:" <<endl;
    imprimirMatriz(mat1);
    cout << "\nEssa matriz será usada para todas as operações a seguir" <<endl;
    
    int option;
    tMatriz transResult, somaResult, multiResult;
    double mediaResult;

    do {
        
        option = menu();

        switch (option) {
            
            case 1:
            
                transResult = transpostaMatriz(mat1);
                cout << "\nTransposta da matriz:";
                imprimirMatriz(transResult);
                
            break;
            
            case 2:
            
                cout << "\nPara realizar a soma, primeiro precisamos preencher uma segunda matriz.";
                preencherMatriz(mat2);
                
                somaResult = somaMatriz(mat1, mat2);
                cout << "\n A soma das matrizes informadas é:";
                imprimirMatriz(somaResult);
                
            break;
            
            case 3:

                if (mat1.colunas != mat2.linhas) {
                    cout << "\nErro: Número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz para multiplicação." <<endl;
                } else {
                    cout << "\nPara realizar a multiplicação, primeiro precisamos preencher uma segunda matriz. Digite os valores";
                    preencherMatriz(mat2);
                    multiResult = multiplicacaoMatriz(mat1, mat2);
                    cout << "\nO resultado da multiplicação é:" <<endl;
                    imprimirMatriz(multiResult);
                }
                
            break;
            
            case 4:
            
                mediaResult = mediaMatriz(mat1);
                cout << "\n A média dos valores da matriz: " << mediaResult <<endl;
                
            break;
             
        }
        
    } while (option != 5);
    
    return 0;
}

