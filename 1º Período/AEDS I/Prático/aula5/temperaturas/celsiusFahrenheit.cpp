/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro
 *
 * Created on 12 de março de 2024, 16:12
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

/*Programa Relacionando graus Celsius com Fahrenheit */
int main(int argc, char** argv) {
    
    float celsius, fahrenheit;
    int i;
    
    printf("-----------------------------------");
    printf("\n|   Tabela de Temperaturas     \n");
    printf("-----------------------------------");
    
    celsius = 0;
    i = 0;
    
    while( celsius <= 100){
        i = i+1;
        fahrenheit = ((celsius * 9/5) + 32); /*Converter para F*/
        printf("\n Celsius: %.2f", celsius);
        printf("equivale a: %.2f",fahrenheit);
        celsius = celsius + 5;
    }
   
    return 0;
}