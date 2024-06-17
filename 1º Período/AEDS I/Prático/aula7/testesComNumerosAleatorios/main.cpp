/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro ( 2023.2.08.003 )
 *
 * Created on 26 de março de 2024, 16:03
 */

#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

//Gerando Testes com numeros aleatorios//

int main() {
    
    int segredo, chute;
    
    cout <<"Número Aleatório" <<endl;
    
    srand (time(NULL));
    segredo = 1+rand()%100;
    cout <<"O valor é: " <<segredo<<endl;

    return 0;
}

