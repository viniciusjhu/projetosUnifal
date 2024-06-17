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

#define PEOPLE 1000

using namespace std;

//Utilizando a variável ALTURA como vetor//
int main(int argc, char** argv) {
    
    float altura[PEOPLE], nGeradoAnterior, media, maiorA, menorA, acimaMedia, desvio, raizDesvio; 
    int i;
    
    srand (time(NULL));
    media = 0;
    acimaMedia = 0;
    nGeradoAnterior = 0;
    
    for( i = 0; i < PEOPLE; i++){
        altura[i] = rand()% (230 + 1 - 150) + 150;
        altura[i] = altura[i]/100;
        nGeradoAnterior = nGeradoAnterior+altura[i];
        media = nGeradoAnterior;
        cout << "A "<<i<<"° altura gerada foi: " << altura <<endl;
        if (altura[i] > maiorA){
            maiorA = altura[i];
        }
        if (altura[i] < menorA or menorA == 0){
            menorA = altura[i];
        }
    }
    
    media = media/i;
    
    for( i = 0; i < PEOPLE; i++ ){
        if (altura[i] > media){
            acimaMedia++;
        }
    }
    
    for( i = 0; i < PEOPLE; i++ ){
        raizDesvio += ((altura[i]-media)*(altura[i]-media));
    }
    
    desvio = (sqrt(raizDesvio/i));
    
    cout << "\n A maior altura gerada foi: "<<maiorA <<endl;
    cout << "\n A menor altura gerada foi: "<<menorA <<endl;
    cout << "\n A média é de: " <<media<<endl;
    cout << "\n E a quantidade de pessoas acima da média foram de: " << acimaMedia <<endl;
    cout << "\n O desvio padrão é: " << desvio <<endl;
    
    return 0;
}