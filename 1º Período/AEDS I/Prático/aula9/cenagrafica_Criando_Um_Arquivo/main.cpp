/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on 8 de abril de 2024, 15:44
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//Projeto cria um arquivo e escreve as variáveis de acordo com a escolha do usuario//
int main(int argc, char** argv) {
    
    int opcao;
    float a, b, c;
    string solido;
    ofstream arquivo ("cenagrafica.txt");
    
    if(!arquivo.is_open()){ 
        cout << "\nErro: arquivo não existe. \n";
        return 1;
    }
    
    do {
        printf("--------------------------------------------------------------------------------------------------------------------------------------");
        cout << "\n Escolha quais são os objetos geométricos que você deixa calcular e digite 0 quando terminar de escolher seus objetos: " <<endl;
        cout << "\n 1: Cubo | 2: paralelepípedo | 3: cilindro | 4: esfera | 5: quadrado | 6: círculo | 7: retângulo | 8: cone | 9: triângulo" <<endl;
        cout << "\n Digite a opção desejada: " <<endl;
        cin >> opcao;
        printf("--------------------------------------------------------------------------------------------------------------------------------------");
        
        
        switch (opcao){
            case 1: cout << "\n Digite o lado do cubo: \n" <<endl;
                cin >> a;
                arquivo << "\ncubo " << a <<endl;
                break;
                
            case 2: cout << "\n Digite os lados do paralelepípedo, separando-os por espaço: " <<endl;
                cin >> a;
                cin >> b;
                arquivo << "\nparalelepípedo " << a << " " << b <<endl;
                break;  
                
            case 3: cout << "\n Digite o raio e altura do cilindro, separando-os por espaço: \n" <<endl;
                cin >> a;
                cin >> b;
                arquivo << "\ncilindro " << a << " " << b <<endl;
                break;
    
            case 4: cout << "\n Digite o raio da esfera: \n" <<endl;
                cin >> a;
                arquivo << "\nesfera " << a <<endl;
                break;
                
            case 5: cout << "\n Digite o lado do quadrado: \n" <<endl;
                cin >> a;
                arquivo << "\nquadrado " << a <<endl;
                break;
                
            case 6: cout << "\n Digite o raio do círculo: \n" <<endl;
                cin >> a;
                arquivo << "\ncirculo " << a <<endl;
                break;
    
            case 7: cout << "\n Digite a base e altura do retângulo, separando-os por espaço: \n" <<endl;
                cin >> a;
                cin >> b;
                arquivo << "\nretângulo " << a << " " << b <<endl;
                break;
                
            case 8: cout << "\n Digite o raio e o altura do cone, separando-os por espaço: \n" <<endl;
                cin >> a;
                cin >> b;
                arquivo << "\ncone " << a << " " << b <<endl;
                break;
                
            case 9: cout << "\n Digite a base e a altura do triângulo, separando-os por espaço; \n" <<endl;
                cin >> a;
                cin >> b;
                arquivo << "\ntriângulo " << a << " " << b <<endl;
                break;
                
            default: "Opção Inválida";
        } 
    } while (opcao != 0);
    
    arquivo << "fim";

    arquivo.close();
    return 0;
}