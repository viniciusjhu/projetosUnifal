/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo
 *
 * Created on 12 de março de 2024, 17:18
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

//Código para verificar qual triângulo é formado a partir dos dados do usuário//

int main(int argc, char** argv) {
    
    float ladoA, ladoB, ladoC, triangulo;
    
    printf("-----------------------------------");
    printf("\n|    Qual o seu triângulo?     \n");
    printf("-----------------------------------");
    
    printf("\n Vamos identificar qual o formato do seu triângulo. Para isso, informe:");
    
    printf("\n Qual é a dimensão do lado A do seu triângulo? ");
    scanf(" %f", &ladoA);
    
    
    printf("\n Qual é a dimensão do lado B do seu triângulo? ");
    scanf("%f", &ladoB);

    printf("\n Qual é a dimensão do lado C de seu triângulo? ");
    scanf(" %f", &ladoC);
    while(ladoC <= 0){
        printf("\n Dados incorretos. Insira a dimensão do lado C novamente: ");
        scanf(" %f", &ladoC);
    }
    
    while(ladoA+ladoC <= ladoB || ladoA+ladoB <= ladoC || ladoB+ladoC <= ladoA){
        printf("\n Seu triângulo não pode ser formado, pois para formar um triângulo, é necessário que a soma de qualquer par de lados seja maior que o terceiro lado");
        printf("\n Verifique seus dados e os informe novamente.");
        
        printf("\n Qual é a dimensão do lado A do seu triângulo? ");
        scanf(" %f", &ladoA);
    
        printf("\n Qual é a dimensão do lado B do seu triângulo? ");
        scanf(" %f", &ladoB);

        printf("\n Qual é a dimensão do lado C de seu triângulo? ");
        scanf(" %f", &ladoC);  
    }
    
    if (ladoA != ladoB && ladoB != ladoC){
        printf("\n Com os dados que você informou, seu triângulo é Escaleno");
    }
         if (ladoA * ladoA + ladoB * ladoB == ladoC * ladoC || ladoA * ladoA + ladoC * ladoC == ladoB * ladoB || ladoB * ladoB + ladoC * ladoC == ladoA * ladoA) {
                printf("\n Com os dados que você informou, seu triângulo é Retângulo");
    } else {
        if (ladoA == ladoB && ladoB == ladoC ){
            printf("\n Com os dados que você informou, seu triângulo é Equilátero");
        } else {
            if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC){
                printf("\n Com os dados que você informou, seu triângulo é Isósceles");
            }
                 if (ladoA * ladoA + ladoB * ladoB == ladoC * ladoC || ladoA * ladoA + ladoC * ladoC == ladoB * ladoB || ladoB * ladoB + ladoC * ladoC == ladoA * ladoA) {
                printf("\n Com os dados que você informou, seu triângulo é Retângulo");
            } else{
                if (ladoA * ladoA + ladoB * ladoB == ladoC * ladoC || ladoA * ladoA + ladoC * ladoC == ladoB * ladoB || ladoB * ladoB + ladoC * ladoC == ladoA * ladoA) {
                printf("\n Com os dados que você informou, seu triângulo é Retângulo");
                }
            }
        }
    }
}