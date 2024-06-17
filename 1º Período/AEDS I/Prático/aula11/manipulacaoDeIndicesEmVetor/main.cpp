/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on 15 de abril de 2024, 16:06
 * EDITADO HOJE
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

#define VALOR_TAM 5
int VALOR;

using namespace std;

//Projeto para realizar buscas num vetor//
int main(int argc, char** argv) {
    VALOR = VALOR_TAM;
    double nGerado[VALOR_TAM], posicoes[VALOR_TAM], qualValor, interInicial, interFinal, inverter;
    int i, j, k, vezes, posicao, opcao, reserva, nVezes, tam;
    string resposta, valorEncontrado;
    
    nVezes = 0;
    resposta = "não";
    qualValor = 0;
    vezes = 0;
    tam = 0;
    
    srand (time(NULL));
    
    for( i = 0; i < VALOR; i++){
        nGerado[i] = (100 + rand()% 101);
        cout << "O"<<i<<"º numero gerado foi: " << *(nGerado + i) <<endl;
    }
    
    cout <<"\n-------------------------------------" <<endl;
    cout << "\n \t BUSCA DE VALOR"                   <<endl;
    cout <<"\n-------------------------------------" <<endl;
    
    do{
        
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------");
        cout << "\n Escolha qual opção deseja proseguir: " <<endl;
        cout << "\n 1: Buscar um valor";
        cout << "\n 2: Buscar um intervalo";
        cout << "\n 3: Encontrar quais posições está um número";
        cout << "\n 4: Inverter os valores do vetor";
        cout << "\n 5: Retirar um valor do vetor";
        cout << "\n 6: Retirar do vetor todos os valores repetidos";
        cout << "\n 7: Sair" <<endl;
        cout << "\n Digite a opção desejada: ";
        cin >> opcao;
        printf("--------------------------------------------------------------------------------------------------------------------------------------");
        
        switch (opcao){
            
            case 1: //Buscar um valor//
                
                resposta = "não";
                
                cout <<"\n Informe o valor, entre 100 e 200, que você deseja buscar: ";
                cin >> qualValor;
                
                while ( qualValor > 200 or qualValor < 100 ){
                    cout <<"\n Informe um valor válido, entre 100 e 200, que você deseja buscar: ";
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
            
            case 2: //Buscar um intervalo//
                
                cout <<"\n Informe o valor inicial do intervalo, entre 100 e 200, que você deseja buscar: ";
                cin >> interInicial;
                
                while ( interInicial > 200 or interInicial < 100 ){
                    cout <<"\n Informe um valor válido inicial do intervalo, entre 100 e 200, que você deseja buscar: ";
                    cin >> interInicial;
                }
                
                cout <<"\n Informe o valor final do intervalo, entre 100 e 200, que você deseja buscar: ";
                cin >> interFinal;
                
                while ( interFinal > 200 or interFinal < 100 ){
                    cout <<"\n Informe um valor válido final do intervalo, entre 100 e 200, que você deseja buscar: ";
                    cin >> interFinal;
                }
                
                for(i = 0; i < VALOR; i++){
                    if(nGerado[i] >= interInicial && nGerado[i] <= interFinal){
                        vezes++;
                    }
                }
                
                cout <<"\n O intervalo entre " <<interInicial <<" e " <<interFinal << " apareceu "<<vezes << "vezes"<<endl;
                
            break;
            
            case 3: //Encontrar quais posições está um número//
                
                cout <<"\n Informe o valor, entre 100 e 200, que você deseja buscar: ";
                cin >> qualValor;
                
                while ( qualValor > 200 or qualValor < 100 ){
                    cout <<"\n Informe um valor válido, entre 100 e 200, que você deseja buscar: " <<endl;
                    cin >> qualValor;
                }
                
                cout << "\n O valor se encontra nas posições: \n \t";
                        
                for(i = 0; i < VALOR; i++){
                    if ( qualValor == nGerado[i] ){
                        posicoes[i] = i;
                        cout << " " << "\n " <<posicoes[i] <<endl;
                    }
                }
            
            break;
            
            case 4: //Inverter os valores do vetor//
                
                cout <<"\n Vamos inverter os valores, portanto o vetor ficará: " <<endl;
                
                for(i = 0; i < VALOR; i++){

                    nGerado[VALOR] = nGerado[VALOR + (-i) - 1];
                   
                    cout << " " <<"\n " <<nGerado[VALOR] <<endl;
                }       
                
            break;
            
            case 5: // Retirar um valor do vetor //
                
                //Inicio da Verificação se o número tem no vetor ou não//
                
                valorEncontrado = "não";
                
                cout <<"\n Qual valor você deseja retirar do vetor? ";
                cin >> qualValor;
                
                for(i = 0; i < VALOR; i++){
                    if ( nGerado[i] == qualValor ){
                        valorEncontrado = "sim";
                    }
                }
                
                while ( valorEncontrado == "não" ){
                    cout <<"\n Valor não encontrado! " <<endl;
                    cout <<"\n Digite o valor novamente: ";
                    cin >> qualValor;
                        
                    for(i = 0; i < VALOR; i++){
                        if ( nGerado[i] == qualValor ){
                            valorEncontrado = "sim";
                        }
                    }
                }
                
                //Final da verificação //
                
                // Processando a solicitação//
                
                cout <<"\n Vamos retirar do vetor todas ocorrências do valor " << qualValor << ". Portanto, ele ficou assim: " <<endl;
                
                for(i = 0; i < VALOR && valorEncontrado == "sim"; i++){
                    
                    if ( nGerado[i] == qualValor ){
                        nVezes++;
                        nGerado[i] = (nGerado[i] - qualValor);
                    }
                    
                    reserva = i;
                    
                    if( nGerado[i] == 0 ){
                        while ( i < VALOR ){
                            nGerado[i] = nGerado[i+1];
                            tam = i;
                            i++;
                        }
                    }
                    
                    i = reserva;
                    
                    cout << " " <<"\n " <<nGerado[i] <<endl;
                }
                
                cout << "\n O número apareceu " << nVezes << " vezes" <<endl;
                nVezes = 0;
                
            break;    
            
            case 6: 
               
                
                cout <<"\n Vamos retirar do vetor os valores repetido : \n" <<endl;
                
                
                for(i = 0; i < VALOR; i++){
                    
                    for(j = 0; j < VALOR; j++){
                        
                        if ( nGerado[i] == nGerado[j] ){
                            cout << " Os números repetido foram: " << nGerado[j] <<endl;
                        }
                        
                        for(k = j+1; k < VALOR; k++){
                            nGerado[k] = nGerado[j];
                            cout << "\n Os valores de k são: " << nGerado[k] <<endl;
                        }
                    } 
                } 
               
            break;    
        }   
        
    }while (opcao != 7);
       
return 0;
    
}