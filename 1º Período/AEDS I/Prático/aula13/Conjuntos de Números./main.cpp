/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on 23 de abril de 2024, 15:58
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

#define TAMA 10
#define TAMB 10
#define TAMC 10*2

void removerRepetidos(int conjunto1[], int& c1, int conjunto2[], int& c2, bool& feito) {
    
    std::cout << "\nRetirando do Conjunto 1:\n";
    
    for (int i = 0; i < c1; ++i) {
        
        for (int j = i + 1; j < c1;) {
            
            if (conjunto1[i] == conjunto1[j]) {
                
                for (int k = j; k < c1 - 1; ++k) {
                    conjunto1[k] = conjunto1[k + 1];
                }
                
                --c1; // Diminui o tamanho do vetor
                
            } else {
                ++j;
            }
        }
        
        std::cout << "\nO " << i << "º valor do Conjunto 1 agora é: " << conjunto1[i] << "\n" << std::endl;
    }

    std::cout << "\n---------------------------------------------------------------------------" << std::endl;
    std::cout << "\nAgora, vamos retirar do Conjunto 2:\n" << std::endl;

    for (int i = 0; i < c2; ++i) {
        
        for (int a = i + 1; a < c2;) {
            
            if (conjunto2[i] == conjunto2[a]) {
                
                for (int b = a; b < c2 - 1; ++b) {
                    conjunto2[b] = conjunto2[b + 1];
                }
                
                --c2; // Diminui o tamanho do vetor
                
            } else {
                ++a;
            }
        }
        
        std::cout << "\nO " << i << "º valor do Conjunto 2 agora é: " << conjunto2[i] << "\n" << std::endl;
    }
    
    feito = true;
}

using namespace std;

// Projeto que realiza operações básicas sobre conjuntos de valores, como união e intersecção entre eles, como remover os valores repetidos de cada um deles //

int main(int argc, char** argv) {
    
    int conjunto1[TAMA] = {5, 4, 2, 5, 3, 2, 4, 8, 2, 9};
    int conjunto2[TAMB] = {7, 1, 12, 10, 9, 2, 8, 1, 2, 7};
    int conjuntoUniao[TAMC];
    int conjuntoInter[TAMA];
    int opcao, i, k, c1, c2, c3, c4, nVezes;
    bool feito, jaFez;
    
    nVezes = 0;
    k = 0;
    c1 = TAMA;
    c2 = TAMB;
    c3 = TAMC;
    c4 = TAMA;
    feito = false;
    jaFez = false;
    
    do {

        printf("\n--------------------------------------------------------------------------------------------------------------------------------------");
        cout << "\n Escolha qual opção deseja proseguir: " << endl;
        cout << "\n 1: Retirar do vetor todos os valores repetidos";
        cout << "\n 2: Fazer a união dos conjuntos";
        cout << "\n 3: Fazer a intersecção entre os conjuntos";
        cout << "\n 4: Sair" << endl;
        cout << "\n Digite a opção desejada: ";
        cin >> opcao;
        printf("--------------------------------------------------------------------------------------------------------------------------------------");

        switch (opcao) {
            
            case 1: //Retirar do vetor todos os valores repetidos//
                
                cout << "\n Vamos retirar dos vetors os valores repetido : \n" << endl;
                
                removerRepetidos(conjunto1, c1, conjunto2, c2, feito);
                
            break;
            
            case 2: //Fazer a união dos conjuntos//
                
                if(feito == false ){
                    
                    cout << "\n \n Vamos fazer a remoção dos valores repetidos de cada vetor, antes de fazer a união: \n" <<endl;
                    removerRepetidos(conjunto1, c1, conjunto2, c2, feito);
                    
                }
                
                
                if (feito == true) {
                    
                    cout << "\n---------------------------------------------------------------------------" <<endl;
                    cout << "\n Vamos fazer a união dos conjuntos: \n" << endl;

                    // Copia o conjunto1 para o conjuntoUniao
                    
                    for (i = 0; i < c1; i++) {
                        conjuntoUniao[i] = conjunto1[i];
                    }

                    // Copia os elementos do conjunto2 que não estão em conjunto1 para o conjuntoUniao
                    
                    for (int j = 0; j < c2; j++) {
                        conjuntoUniao[i++] = conjunto2[j];
                    }
                    
                    c3 = i;
                    
                    cout << "\n Portanto, o Conjunto União ficou: \n \n";
                    
                    for(i = 0; i < c3; i++){
                        
                        cout << "\t " <<conjuntoUniao[i] <<endl;
                        
                    }
                }
                
            break;
            
            case 3: //Fazer a intersecção entre os conjuntos//
                
                if (feito == false) {

                    cout << "\n \n Vamos fazer a remoção dos valores repetidos de cada vetor, antes de fazer a interseccção: \n" << endl;
                    removerRepetidos(conjunto1, c1, conjunto2, c2, feito);

                }
                
                if ( jaFez == false ){
                
                    if ( feito == true ){
                    
                        for(i = 0; i < c1; i++){
                    
                            for(int j = 0; j < c2; j++){
                        
                                if(conjunto1[i] == conjunto2[j]){
                            
                                    nVezes++;
                                    conjuntoInter[k] = conjunto1[i];
                                    k++;
                                }
                            }
                        }
                    }    
                   
                    c4 = c4 - k - 1;
                
                    cout << "\n---------------------------------------------------------------------------" << endl;
                    cout << "\n O Conjunto Intersecção, entre o Conjunto 1 e Conjunto 2, ficou: \n \n";

                    for (k = 0; k < c4 - k; k++) {

                        cout << "\t " << conjuntoInter[k] << endl;

                    }
                
                } 
                
                if (jaFez == true) {

                    cout << "\n---------------------------------------------------------------------------" << endl;
                    cout << "\n Você já fez uma fez a intersecção, portanto o conjunto Interseccção ficou da mesma forma: \n \n";

                    for (k = 0; k < c4 - k; k++) {

                        cout << "\t " << conjuntoInter[k] << endl;

                    }

                }
                
                jaFez = true;
                
            break;    
            
        } // Colchetes do Switch //
           
    }while (opcao != 4);        
    
    return 0;
    
}