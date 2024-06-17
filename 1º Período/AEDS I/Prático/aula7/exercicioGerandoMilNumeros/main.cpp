/* 
 * File:   main.cpp 
 * Author: Vinicius Ribeiro ( 2023.2.08.003 )
 *
 * Created on 26 de março de 2024, 17:00
 */

#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

//Gerando Mil Números Aleatórios e sua média//
int main() {
    
    int nGerado, i, nGeradoAnterior;
    float media;
    
    srand (time(NULL));
    i = 0;
    media = 0;
    nGeradoAnterior = 0;
    
    while ( i <= 999 ){
        nGerado = 1+rand()%100;
        nGeradoAnterior = nGeradoAnterior+nGerado;
        media = nGeradoAnterior;
        i = i+1;
        cout << nGerado <<endl;
    }
    
    media = media/i;
    
    cout << "A média é de: " <<media<<endl;
       
    
    return 0;
}