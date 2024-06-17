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

/*Tabela ASCII*/
int main() {
    
    unsigned char codigoASCII = 0;
    
    printf("\t Tabelas ASCII: \n");
    
    codigoASCII = 0;
    while (codigoASCII < 255){
        printf("\t\t Caracter: %c", codigoASCII);
        printf("\t\t Código: %d\n", codigoASCII);
        codigoASCII++;
    }
    
}