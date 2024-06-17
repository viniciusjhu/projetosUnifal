/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro ( 2023.2.08.003 )
 *
 * Created on 22 de abril de 2024, 16:00
 */

#include <cstdlib>
#include <stdio.h>
#include <string>

#define TAM 30


// Este programa opera manipulações de vetores de caracteres //

using namespace std;

int main(int argc, char** argv) {

    char nome[TAM], sobrenome[TAM], nomeCompleto[TAM * 2 + 2], buscaNome[TAM];
    int i, j, guardaI, nomeEncontrado;
    
    i = 0;
    j = 0;
    nomeEncontrado = 0;
    
    nome[0] = 'V';
    nome[1] = 'i';
    nome[2] = 'n';
    nome[3] = 'i';
    nome[4] = 'c';
    nome[5] = 'i';
    nome[6] = 'u';
    nome[7] = 's';
    nome[8] = '\0';

    printf("\n Nome: %s.\n", nome);

    sobrenome[0] = 'R';
    sobrenome[1] = 'i';
    sobrenome[2] = 'b';
    sobrenome[3] = 'e';
    sobrenome[4] = 'i';
    sobrenome[5] = 'r';
    sobrenome[6] = 'o';
    sobrenome[7] = '\0';

    printf("\n Sobrenome: %s.\n", sobrenome);
    
    
     // Juntando o Nome e Sobrenome//
    
    for(i = 0; i < TAM && nome[i] != '\0'; i++){
        
        nomeCompleto[i] = nome[i];
    }
    
    guardaI = i;
    nomeCompleto[i] = ' '; // Adicionando um espaço//
    
    for(j = 0; j < TAM && sobrenome[j] != '\0'; j++){
        
        nomeCompleto[i + 1 + j] = sobrenome[j];
    }
    
    nomeCompleto[(i + 1) + j] = '\0';
    
    printf("\n Nome Completo: %s.\n", nomeCompleto);
    
    //Colocando os caracteres do nome completo em maiusculas//
   
    for(i = 0; i < TAM; i++){
        
        if(nomeCompleto[i] > 96){ // 96 pois as letras minusculas começam acima do 96//
            nomeCompleto[i] = nomeCompleto[i] - 32;
        }
    }
    
    printf("\n Nome Completo tudo MAIUSCULO: %s.\n", nomeCompleto);
    
    //Colocando os caracteres em minúsculas, menos as primeiras letras do nome completo//
    
    for(i = 1; i < TAM; i++){
        
        if(nomeCompleto[i] > 64 && nomeCompleto[i] <= 90){
            nomeCompleto[i] = nomeCompleto[i] + 32;
        } else {
            if(nomeCompleto[i] > 96){
                nomeCompleto[i] = nomeCompleto[i] - 32;
            } else {
                if (nomeCompleto[i] == ' ' ){
                    i++;
                }
            }
        }
    }
    
    printf("\n Nome Completo tudo MAIUSCULO e minusculo: %s.\n", nomeCompleto);
    
    //Retirando os espaços de um nome completo;//

    for (i = guardaI; nomeCompleto[i] != '\0'; i++) {
        
        nomeCompleto[i] = nomeCompleto[i+1];
    }
    
    printf("\n Nome Completo sem espaço: %s.\n", nomeCompleto);
    
    //Procurar se um nome está dentro de um nome completo//
    
    printf("\n Qual nome você deseja buscar? \n");
    scanf("%s", buscaNome);
    
    for (i = 0; nomeCompleto[i] != '\0'; i++) {
        if (nomeCompleto[i] == buscaNome[0]) {
            nomeEncontrado = 1;
            for (j = 1; buscaNome[j] != '\0' && nomeCompleto[i + j] != '\0'; j++) {
                if (nomeCompleto[i + j] != buscaNome[j]) {
                    nomeEncontrado = 0;
                }
            }
        }
    }

    if (nomeEncontrado == 1) {
        printf("\n O nome '%s' foi encontrado no nome completo.\n", buscaNome);
    } else {
        printf("\n O nome '%s' não foi encontrado no nome completo.\n", buscaNome);
    }
    
    return 0;
}
