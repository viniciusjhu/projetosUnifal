/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2023.2.08.003
 *
 * Created on 25 de março de 2024, 16:08
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*Outras Variáveis*/
int main() {
    
    int valorint = 50;
    
    printf("\n Tipos de Variáveis e Alocação de Memória\n");
    
    printf("\n VariáveL inteira:\n");
    printf("\n Valor Armazenado: %d", valorint);
    printf("\n Endereço na memória: %p", &valorint);
    printf("\n Quantidade em byte: %li\n", sizeof(int));
    
    float valorfloat = 50;
    
    printf("\n VariáveL Float:\n");
    printf("\n Valor Armazenado: %f", valorfloat);
    printf("\n Endereço na memória: %p", &valorfloat);
    printf("\n Quantidade em byte: %li", sizeof(int));
    
    //Há outros tipos de váriavais, por exemplo://
    
    long int valorlongint = 50;
    
    printf("\n VariáveL LONG int:\n");
    printf("\n Valor Armazenado: %d", valorlongint);
    printf("\n Endereço na memória: %p", &valorlongint);
    printf("\n Quantidade em byte: %li\n", sizeof(int));
    
    short int valorshortint = 50;
    
    printf("\n VariáveL SHORT int:\n");
    printf("\n Valor Armazenado: %d", valorshortint);
    printf("\n Endereço na memória: %p", &valorshortint);
    printf("\n Quantidade em byte: %li\n", sizeof(int));
    
    unsigned int valorunsignedint = 50;
    
    printf("\n VariáveL UNSIGNED int:\n");
    printf("\n Valor Armazenado: %d", valorunsignedint);
    printf("\n Endereço na memória: %p", &valorunsignedint);
    printf("\n Quantidade em byte: %li\n", sizeof(int));
    
    double valordouble = 50;
    
    printf("\n VariáveL double float:\n");
    printf("\n Valor Armazenado: %f", valordouble);
    printf("\n Endereço na memória: %p", &valordouble);
    printf("\n Quantidade em byte: %li\n", sizeof(int));
    
    return 0;
}