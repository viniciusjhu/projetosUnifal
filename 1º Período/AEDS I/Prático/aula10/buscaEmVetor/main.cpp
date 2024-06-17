/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on 8 de abril de 2024, 15:44
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

#define VALOR 1000

using namespace std;

//Projeto para realizar buscas num vetor//
int main(int argc, char** argv) {
    
    double nGerado[VALOR], posicoes[VALOR], qualValor, interInicial, interFinal;
    int i, vezes, posicao, opcao, opcaoN, opcaoN2;
    string resposta;
    
    resposta = "não";
    qualValor = 0;
    vezes = 0;
    
    srand (time(NULL));
    
    for( i = 0; i < VALOR; i++){
        nGerado[i] = (100 + rand()% 101);
        cout << "O"<<i<<" numeros gerados foram: " << *(nGerado + i) <<endl;
    }
    
    cout <<"\n-------------------------------------" <<endl;
    cout << "\n \t BUSCA DE VALOR"                   <<endl;
    cout <<"\n-------------------------------------" <<endl;
    
    do{
        
        printf("--------------------------------------------------------------------------------------------------------------------------------------");
        cout << "\n Escolha qual opção que deseja fazer a busca: " <<endl;
        cout << "\n 1: Buscar um valor | 2: Buscar um intervalo | 3: Encontrar quais posições está um número | 4: Sair" <<endl;
        cout << "\n Digite a opção desejada: " <<endl;
        cin >> opcao;
        printf("--------------------------------------------------------------------------------------------------------------------------------------");
        
        switch (opcao){
            
            case 1: 
                
                resposta = "não";
                
                cout <<"\n Informe o valor, entre 100 e 200, que você deseja buscar: " <<endl;
                cin >> qualValor;
                
                while ( qualValor > 200 or qualValor < 100 ){
                    cout <<"\n Informe um valor válido, entre 100 e 200, que você deseja buscar: " <<endl;
                    cin >> qualValor;
                }
                
                for( i = 0; i < VALOR && resposta == "não"; i++){
                    if(qualValor == nGerado[i]){
                        resposta = "sim";
                        vezes++;
                        posicao = i+1;
                        cout <<"\n O valor " <<qualValor << " existe no vetor" << " e está na posição " <<posicao <<endl;
                    }  
                }
                
                if (resposta == "não"){
                    cout <<"\n O valor " <<qualValor << " não existe no vetor" <<endl;
                }    
                
            break;
            
            case 2: 
                
                cout <<"\n Informe o valor inicial do intervalo, entre 100 e 200, que você deseja buscar: " <<endl;
                cin >> interInicial;
                
                while ( interInicial > 200 or interInicial < 100 ){
                    cout <<"\n Informe um valor válido inicial do intervalo, entre 100 e 200, que você deseja buscar: " <<endl;
                    cin >> interInicial;
                }
                
                cout <<"\n Informe o valor final do intervalo, entre 100 e 200, que você deseja buscar: " <<endl;
                cin >> interFinal;
                
                while ( interFinal > 200 or interFinal < 100 ){
                    cout <<"\n Informe um valor válido final do intervalo, entre 100 e 200, que você deseja buscar: " <<endl;
                    cin >> interFinal;
                }
                
                for(i = 0; i < VALOR; i++){
                    if(nGerado[i] >= interInicial && nGerado[i] <= interFinal){
                        vezes++;
                    }
                }
                
                cout <<"\n O intervalo entre " <<interInicial <<" e " <<interFinal << " apareceu "<<vezes << "vezes"<<endl;
                
            break;
            
            case 3:
                
                cout <<"\n Informe o valor, entre 100 e 200, que você deseja buscar: " <<endl;
                cin >> qualValor;
                
                while ( qualValor > 200 or qualValor < 100 ){
                    cout <<"\n Informe um valor válido, entre 100 e 200, que você deseja buscar: " <<endl;
                    cin >> qualValor;
                }
                
                cout << "\n O valor se encontra nas posições: \n \t";
                        
                for(i = 0; i < VALOR; i++){
                    if ( qualValor == nGerado[i] ){
                        posicoes[i] = i+1;
                        cout << " " << "\n " <<posicoes[i] <<endl;
                    }
                }
            
            break;    
        }
        
    }while (opcao != 4);
       
return 0;
    
}