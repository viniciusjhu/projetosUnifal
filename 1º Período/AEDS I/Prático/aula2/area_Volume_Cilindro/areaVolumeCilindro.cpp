/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro
 *
 * Created on 4 de março de 2024, 17:33
 * Update on 11 de março de 2024
 */

#include <cstdlib>
#include <stdio.h>
#define PI 3.14

using namespace std;

/*Programa para calcular Area e Volume de um Cilindro*/
int main(int argc, char** argv) {
    
    float raioCilindro, alturaCilindro, volumeCilindro, areaCilindro;
    
    printf("-----------------------------------");
    printf("\n|       Area e Volume           |\n");
    printf("-----------------------------------");
    
    printf("\n Digite o raio do cilindro: ");
    scanf(" %f", &raioCilindro);
    while (raioCilindro < 0 || raioCilindro){
        printf("\n Valor incorreto. Digite novamente: ");
        scanf(" %f", &raioCilindro);
    }
    
    printf("\n Digite a altura do cilindro: ");
    scanf(" %f", &alturaCilindro);
    while (alturaCilindro < -0 || alturaCilindro){
        printf("\n Valor incorreto. Digite novamente: ");
        scanf(" %f", &alturaCilindro);
    }
   
    areaCilindro = (2*PI*raioCilindro)*(raioCilindro+alturaCilindro);
    
    volumeCilindro = (PI*raioCilindro*raioCilindro*alturaCilindro);
    
    printf("\n O volume é: %.2f", volumeCilindro);
    printf("\n Já a area é de: %.2f", areaCilindro);
    
    return 0;
}

