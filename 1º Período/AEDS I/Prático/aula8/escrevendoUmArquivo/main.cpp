/* 
 * File:   main.cpp 
 * Author: Vinicius Ribeiro ( 2023.2.08.003 )
 *
 * Created on 01 de abril de 2024, 17:00
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

//Gerando Mil Números Aleatórios e sua média e escrevendo estes números num arquivo//
int main() {
    
    float nGerado, nGeradoAnterior, maiorN, menorN, media;
    int i;
    ofstream arquivo ("numeros.txt");
    if(!arquivo.is_open()){ 
        cout << "Erro: arquivo não existe" <<endl;
        return 1;
    }
    
    srand (time(NULL));
    i = 0;
    media = 0;
    nGeradoAnterior = 0;
    maiorN = 0;
    menorN = 0;
    
    while ( i <= 999 ){
        nGerado = rand()% (230 + 1 - 150) + 150;
        nGerado = nGerado/100;
        nGeradoAnterior = nGeradoAnterior+nGerado;
        media = nGeradoAnterior;
        i = i+1; 
        arquivo << "O "<<i<<"° número gerado foi: " << nGerado <<endl;
        if (nGerado > maiorN){
            maiorN = nGerado;
        }
        if (nGerado < menorN or menorN == 0){
            menorN = nGerado;
        }
    } 
    
    arquivo << "\n O maior número gerado foi: "<<maiorN <<endl;
    arquivo << "\n O menor número gerado foi: "<<menorN <<endl;

    media = media/i;
    arquivo << "\n A média desse números foram: " <<media <<endl;
    
       
    arquivo.close();
    
    return 0;
}