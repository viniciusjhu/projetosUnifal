/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro
 *
 * Created on 11 de março de 2024, 16:12
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

/*Programa para calcular média de 10 pessoas*/
int main(int argc, char** argv) {
    
    float altura, media;
    int i;
    
    printf("-----------------------------------");
    printf("\n|      Média do seu grupo      \n");
    printf("-----------------------------------");
    
    media = 0;
    i = 0;
    
    while( i < 10){
        
        cout <<"\n Digite a "<<i+1<<"ª altura: ";
        cin >> altura;
        
        while (altura < 0 || altura >2.9){
            cout <<"\n Valor incorreto. Digite novamente a " <<i+1<<"ª altura: ";
            cin >> altura;
        }
       
        media = media+altura;
        i = i+1;
    }
    
    media = (media/10);
    cout <<"\n A média do grupo é de: "<<media<< "entre as 10 pessoas";
    
    return 0;
}