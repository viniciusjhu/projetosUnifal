/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro
 *
 * Created on 4 de março de 2024, 16:12
 * Update on 11 de março de 2024
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*Programa para Notas*/
int main(int argc, char** argv) {
    
    float nota1, nota2, nota3, media;
    
    printf("-----------------------------------");
    printf("\n|       Hello Students           |\n");
    printf("-----------------------------------");
    
    printf("\n Digite sua Primeira Nota: ");
    scanf(" %f", &nota1);
    printf("\n Digite sua Segunda Nota: ");
    scanf(" %f", &nota2);
    printf("\n Digite sua Terceira Nota: ");
    scanf(" %f", &nota3);
    
    media = (nota1*3.0+nota2*3+nota3*4)/10;
    
    printf("\n A minha média de AEDS I Prática é: %.2f", media);
    printf("\n Se a nota for >= 6.0, você está aprovado");
    printf("\n Se a nota for <= 6.0, você está reprovado");
    
    return 0;
}