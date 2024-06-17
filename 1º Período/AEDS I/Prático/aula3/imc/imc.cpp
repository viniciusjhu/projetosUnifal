/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro
 *
 * Created on 5 de março de 2024, 16:25
 * Update on 11 de março de 2024
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*Calcular o índice de Massa Corporal de uma pessoa*/
int main(int argc, char** argv) {
    
    float peso, altura, imc;
    
    printf("-----------------------------------");
    printf("\n|       Qual seu IMC?           |\n");
    printf("-----------------------------------");
    
    printf("\n Digite seu peso em KG: ");
    scanf(" %f", &peso);
    while (peso < 0 || peso >200){
        printf("\n Valor incorreto. Digite novamente: ");
        scanf(" %f", &peso);
    }
    
    printf("\n Digite sua altura em M: ");
    scanf(" %f", &altura);
    while (altura < 0 || altura >2.9){
        printf("\n Valor incorreto. Digite novamente: ");
        scanf(" %f", &altura);
    }
   
    imc = (peso/(altura*altura));
   
    printf("\n Seu índice corporal é de: %.2f kg/m²", imc);
    
    if (imc <= 18.5){
        printf("\n Portanto, você está abaixo do peso ideal");
    } else
            if (imc < 24.9){
                printf("\n Portanto, você está no peso ideal");
            } else
                if (imc < 29.9){
                 printf("\n Portanto, você está sobrepeso");
                } else
                    if (imc < 34.9){
                        printf("\n Portanto, você está com obesidade Grau 1");
                    } else
                        if (imc < 39.9){
                            printf("\n Portanto, você está com obesidade Grau 2");
                        } else 
                            printf("\n Portanto, você está com obesidade Grau 3. Cuidado!");
                
    
    return 0;
}

