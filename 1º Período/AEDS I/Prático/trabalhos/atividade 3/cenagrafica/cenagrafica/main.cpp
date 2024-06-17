/* 
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on 2 de abril de 2024, 15:44
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//Projeto que faz a leitura de um arquivo e faz o calculo dos objetos//
int main(int argc, char** argv) {
    
    float raio, altura, perímetro, base, lado1, lado2, lado3, volume, area;
    string solido;
    ifstream arquivo ("cenagrafica.txt");
    
    if(!arquivo.is_open()){ 
        cout << "\nErro: arquivo não existe. \n";
        return 1;
    }
    
    raio = 0;
    altura = 0;
    perímetro = 0;
    lado1 = 0;
    lado2 = 0;
    lado3 = 0;
    volume = 0;
    area = 0;
    
    arquivo >> solido;
    
    while ( solido != "Fim" or solido != "fim" ){
        if (solido == "cubo" or solido == "Cubo"){ //Lê cubo e faz o cálculo do volume e da area do cubo//
            
            arquivo >> lado1;
            
            volume = (lado1*lado1*lado1);
            area = (6*(lado1*lado1));
            
            printf("-----------------------------------");
            printf("\n             Cubo              \n");
            printf("-----------------------------------");
            
            cout << "\n O volume do Cubo informado é de: " << volume <<endl;
            cout << "\n A área do Cubo informado é de: " << area << "\n" <<endl;
        } else {
            if ( solido == "paralelepípedo" or solido == "Paralelepípedo"){ //Lê paralelepípedo e faz o cálculo do volume e da area do paralelepípedo//
                
                arquivo >> lado1;
                arquivo >> lado2; 
                arquivo >> lado3;
                
                volume = (lado1*lado2*lado3);
                area = ((2*lado1*lado2)+(2*lado2*lado3)+(2*lado3*lado1));
                
                printf("-----------------------------------");
                printf("\n       Paralelepípedo          \n");
                printf("-----------------------------------");
            
                cout << "\n O volume do paralelepípedo informado é de: " << volume <<endl;
                cout << "\n A área do paralelepípedo informado é de: " << area << "\n" <<endl;
            } else {
                if ( solido == "cilindro" or solido == "Cilindro"){ //Lê cilindro e faz o cálculo do volume e da area do cilindro//
                    
                    arquivo >> raio;
                    arquivo >> altura;
                    
                    volume = (3.14*(raio*raio)*altura);
                    area = ((2*3.14*(raio*raio))+(2*3.14*raio*altura));
                    
                    printf("-----------------------------------");
                    printf("\n          Cilindro             \n");
                    printf("-----------------------------------");
                    
                    cout << "\n O volume do cilindro informado é de: " << volume <<endl;
                    cout << "\n A área do cilindro informado é de: " << area << "\n" <<endl;
                } else {
                    if ( solido == "esfera" or solido == "Esfera"){ //Lê esfera e faz o cálculo do volume e da area da esfera//
                        
                        arquivo >> raio;
                        
                        volume = ((4/3)*3.14*(raio*raio*raio));
                        area = (4*3.14*(raio*raio));
                        
                        printf("-----------------------------------");
                        printf("\n          Esfera               \n");
                        printf("-----------------------------------");
                        
                        cout << "\n O volume da esfera informada é de: " << volume <<endl;
                        cout << "\n A área da esfera informada é de: " << area << "\n" <<endl;
                    } else {
                        if ( solido == "quadrado" or solido == "Quadrado"){ //Lê Quadrado e faz o cálculo da e do perímetro do quadrado//
                            
                            arquivo >> lado1;
                            
                            area = (lado1*lado1);
                            perímetro = (4*lado1);
                            
                            printf("-----------------------------------");
                            printf("\n          Quadrado             \n");
                            printf("-----------------------------------");
                            
                            cout << "\n O perímetro do quadrado informado é de: " << perímetro <<endl;
                            cout << "\n A área do quadrado informado é de: " << area << "\n" <<endl;
                        } else {
                            if ( solido == "circulo" or solido == "círculo" or solido == "Circulo" or solido == "Círculo"){ //Lê c e faz o cálculo da área e do perímetro do círculo//
                                
                                arquivo >> raio;
                                
                                area = (3.14*(raio*raio));
                                perímetro = (2*3.14*raio);
                                
                                printf("-----------------------------------");
                                printf("\n          Círculo              \n");
                                printf("-----------------------------------");
                                
                                cout << "\n O perímetro do círculo informado é de: " << perímetro <<endl;
                                cout << "\n A área do círculo informado é de: " << area << "\n" <<endl;
                            } else{
                                if( solido == "retangulo" or solido == "Retangulo" or solido == "retângulo" or solido == "Retângulo"){ //Lê retângulo e faz o cálculo da área e do perímetro do retangulo//
                                    
                                    arquivo >> base;
                                    arquivo >> altura;
                                    
                                    area = (base*altura);
                                    perímetro = ((2*base)+(2*altura));
                                    
                                    printf("-----------------------------------");
                                    printf("\n          Retângulo            \n");
                                    printf("-----------------------------------");
                                    
                                    cout << "\n O perímetro do retângulo informado é de: " << perímetro <<endl;
                                    cout << "\n A área do retângulo informado é de: " << area << "\n" <<endl;
                                } else{
                                    if ( solido == "cone" or solido == "Cone"){ //Lê Cone e faz o cálculo do volume e da area do cone//
                                        
                                        arquivo >> raio;
                                        arquivo >> altura;
                                        
                                        volume = ((float)1/3*3.14*(raio*raio)*altura);
                                        area = ((3.14*raio*sqrt((raio*raio)+(altura*altura))+(3.14*(raio*raio))));
                                        
                                        printf("-----------------------------------");
                                        printf("\n            Cone               \n");
                                        printf("-----------------------------------");
                                        
                                        cout << "\n O Volume do cone informado é de: " << volume <<endl;
                                        cout << "\n A área do cone informado é de: " << area << "\n" <<endl;
                                    } else {
                                        if ( solido == "triangulo" or solido == "Triangulo" or solido == "triângulo" or solido == "Triângulo"){ //Lê triângulo e faz o cálculo da área do triângulo//
                                            
                                            arquivo >> base;
                                            arquivo >> altura;
                                            
                                            area = ((base*altura)/2);
                                            
                                            printf("-----------------------------------");
                                            printf("\n          Triângulo            \n");
                                            printf("-----------------------------------");
                                            
                                            cout << "\n A área do triângulo informado é de: " << area <<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        arquivo >> solido;
    } //Fim do While//

    return 0;
}

