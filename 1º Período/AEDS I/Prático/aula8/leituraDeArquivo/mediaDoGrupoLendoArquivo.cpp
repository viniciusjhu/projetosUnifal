/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Created on 01 de abril de 2024, 16:12
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

/*Programa para calcular média do grupo, de acordo com as alturas definidas em um arquivo*/
int main(int argc, char** argv) {
    
    float altura, media;
    int i;
    ifstream arquivo ("entrada.txt");
    if(!arquivo.is_open()){ 
        cout << "Erro: arquivo não existe" <<endl;
        return 1;
    }
    
    printf("-----------------------------------");
    printf("\n      Média do seu grupo      \n");
    printf("-----------------------------------");
    
    media = 0;
    i = 0;

    while( altura > 0 ){
        
        arquivo >> altura;  // cin >> altura
        cout <<"\n O valor da "<<i+1<<"ª altura é de: " << altura << "m";
        
        
            while (altura < 0 || altura >2.9){
                arquivo >> altura; // cin >> altura
                cout <<"\n Valor incorreto. Digite novamente a " <<i+1<<"ª altura: ";
            }
        
         media = media+altura;
         i = i+1;

    }
    
    if (i != 0){
        media = (media/i);
        cout <<"\n Portanto, a média do seu grupo é de: "<<media<<"m";
    } else {
        media = (media/i);
        cout <<"\n Portanto, a média do seu grupo é de: "<<media<<"m";
    } 
        
    return 0;
}