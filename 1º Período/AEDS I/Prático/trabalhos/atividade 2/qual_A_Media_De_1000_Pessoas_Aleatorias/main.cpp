/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 26 de março de 2024, 17:42
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <iomanip> //Permitir formatar os números com casas após a vírgula//

using namespace std;

//Neste projeto, iremos gerar aleatoriamente alturas de 1000 pessoas entre 1.5 e 2.3 de altura e encontrar a média, a maior e a menor altura entre eles//

int main() {
    
    int i;
    float alturasGeradas, media, soma, maiorAltura, menorAltura, pessoas2m, porcentagem;
    
    //Definindo alguns valores//
    srand (time(NULL));
    soma = 0;
    i = 0;
    maiorAltura = 0;
    menorAltura = 0;
    pessoas2m = 0;
    porcentagem = 0;
    
    //Gerando as alturas e fazendo algumas verificações//
    while ( i <= 999 ){
        alturasGeradas = rand()% (230 + 1 - 150) + 150;
        alturasGeradas = alturasGeradas/100;
        i = i+1;
        soma += alturasGeradas;
        if(alturasGeradas > maiorAltura){
            maiorAltura = alturasGeradas;
        }
        if (alturasGeradas < menorAltura or menorAltura == 0){
            menorAltura = alturasGeradas;
        }
        if (alturasGeradas > 2.0){
            pessoas2m = pessoas2m + 1;
        }
    }
    
    //Fazendo alguns cálculos//
    porcentagem = pessoas2m*100/i;
    media = soma/i;
    
    cout << fixed << setprecision (2) <<endl; //Formatando os valores mostrados na tela com apenas 2 casas depois da vírgula//
    
    cout <<"\n A média dessa alturas geradas é de: "<<media<<"m"<<endl;
    cout <<"\n A menor altura gerada foi de: "<<menorAltura<<endl;
    cout <<"\n A maior altura foi de: "<<maiorAltura<<endl;
    
    cout << fixed << setprecision (1) <<endl; //Formatando os valores mostrados na tela com apenas 2 casas depois da vírgula//
    cout <<"\n Quantidades de pessoas de 2m: "<<pessoas2m<<endl;
    
    cout <<"\n Tivemos "<<porcentagem<<"% de pessoas com ou mais 2 metros"<<endl;
           
    return 0;
}