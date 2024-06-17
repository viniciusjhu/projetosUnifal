/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro ( 2023.2.08.003 )
 *
 * Created on 26 de março de 2024, 16:19
 */

#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

//Jogo para Adivinhar o número gerado//
int main() {
    
    int nGerado, nChute;
    
    cout << "Vamos jogar? Tente adivinhar qual é o número que foi gerado pelo PC" <<endl;
    
    srand (time(NULL));
    nGerado = 1+rand()%100;
    
    cout <<"\n O número já foi gerado. Qual é o seu chute? " <<endl;
    cin >> nChute;
    
    while (nChute != nGerado){
        if (nChute < nGerado){
            cout << "\n Você errou! O número que você chutou é menor do que o número gerado. Tente novamente: " <<endl;
            cin >> nChute;
        } else {
            if (nChute > nGerado){
                cout << "\n Você errou! O número que você chutou é maior do que o número gerado. Tente novamente: " <<endl;
                cin >> nChute;
            }
        }
    }
    
    cout <<"\n Uhull! Você acertou! " <<endl;
    
    return 0;
}