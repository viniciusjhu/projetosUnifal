/*
 * File:   main.cpp
 * Author: Vinicius Ribeiro ( 2023.2.08.003 )
 *
 * Created on 29 de abril de 2024, 16:05
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

#define TAM 5

using namespace std;

// Projeto para armazenar informações em registros de dados  //

typedef struct{
    
    bool valido;
    string nome;
    string celular;
    string cidade;
    string email;
    
} Pessoa;
        
int main( ) {
    
    Pessoa amigo;
    Pessoa agenda[TAM];
    
    int opcao = 0;
    int i, j;
    string nome, telefone;
    bool incluiu = false;
    
    cout << "\n-------------------------------------" << endl;
    cout << "\n \t   DADOS DE UM AMIGO              " << endl;
    cout << "\n-------------------------------------" << endl;
    
    ifstream arquivo("agenda.txt");
    if (!arquivo.is_open()) {
        cout << "Erro: arquivo não existe" << endl;
        return 1;
    }
    
    cout << "\n ALGUNS AVISOS:" <<endl;
    cout << "\n \t No arquivo Agenda escreva um nome embaixo do outro com os dados deste amigo, logo abaixo do respectivo nome do seu amigo, e ao finalizar adicione 'fim' " <<endl;
    cout << "\n \t Quando tiver um nome ou cidade tiver espaço, adicione um underline '_' \n" <<endl;
    cout << "\n----------------------------------------------------------------------------" << endl;
    
    //Lendo os dados do arquivo//
    
    for(i = 0; i < TAM && agenda[i].nome != "fim"; i++){
        
        arquivo >> agenda[i].nome;
        arquivo >> agenda[i].celular;
        arquivo >> agenda[i].cidade;
        arquivo >> agenda[i].email;
        
        if(agenda[i].nome == "fim"){
            
            agenda[i].valido = false;
            
        } else {
            
            agenda[i].valido = true;
            
        }
        
    }
    
    for(j = 0; j < TAM && agenda[j].nome != "fim"; j++){
        
        if(agenda[j].valido == true){
            
            cout << "\n O nome do " << j + 1 << "° amigo é: " << agenda[j].nome << endl;
            cout << "\n O celular do " << j + 1 << "° amigo é: " << agenda[j].celular << endl;
            cout << "\n A cidade do " << j + 1 << "° amigo é: " << agenda[j].cidade << endl;
            cout << "\n O email do " << j + 1 << "° amigo é: " << agenda[j].email << "\n " << endl;
            cout << "\n----------------------------------------------------------------------------" << endl;
            
        }
      
    }
    
    arquivo.close();
    
    do{
        
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------" <<endl;
        cout << "\n Escolha qual opção deseja proseguir: " << endl;
        cout << "\n 1: Buscar um nome";
        cout << "\n 2: Buscar um telefone";
        cout << "\n 3: Incluir um amigo";
        cout << "\n 4: Excluir um amigo";
        cout << "\n 5: Alterar dados de um amigo";
        cout << "\n 6: Sair" << endl;
        cout << "\n Digite a opção desejada: ";
        cin >> opcao;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" <<endl;
        
        switch (opcao){
            
            case 1: //Buscar um nome//

                cout << "\n Qual o nome do seu amigo que você deseja buscar? ";
                cin >> nome;

                for (int a = 0; a < TAM && agenda[a].nome != "fim"; a++) {

                    if (agenda[a].nome == nome) {
                        
                        cout << "------------------------------------------------------------------------------------" <<endl;
                        cout << "\n Achei seu amigo! Confira os dados dele: \n \n";
                        cout << "\t O nome do seu amigo é: " << agenda[a].nome << endl;
                        cout << "\t O celular dele é: " << agenda[a].celular << endl;
                        cout << "\t A cidade que você cadastrou para ele é: " << agenda[a].cidade << endl;
                        cout << "\t O email dele é: " << agenda[a].email << "\n " << endl;

                    } else{
                        cout << "\n Não encontrei seu amigo! \n \n";
                    }

                }

            break;
            
            case 2: //Buscar um telefone//
                
                cout << "\n Qual é o telefone do seu amigo que você deseja buscar? ";
                cin >> telefone;

                for (int b = 0; b < TAM && agenda[b].nome != "fim"; b++){

                    if (agenda[b].celular == telefone){

                        cout << "------------------------------------------------------------------------------------" << endl;
                        cout << "\n Achei o telefone do seu amigo! Confira os dados dele: \n \n";
                        cout << "\t O nome do seu amigo é: " << agenda[b].nome << endl;
                        cout << "\t O celular dele é: " << agenda[b].celular << endl;
                        cout << "\t A cidade que você cadastrou para ele é: " << agenda[b].cidade << endl;
                        cout << "\t O email dele é: " << agenda[b].email << "\n " << endl;

                    } else {
                        cout << "\n Não encontrei o telefone do seu amigo! \n \n";
                    }
                    
                }    
                
            break;
            
            case 3: //Incluir um amigo//
                
                int temp;
                
                temp = -1;
                
                for(int k = 0; k < TAM && temp == -1; k++){
                    
                    if(agenda[k].valido == false){
                        
                        temp = k;
                        if(agenda[k].nome == "fim"){
                            
                            agenda[k+1].nome = "fim";
                            agenda[k+1].valido = false;
                            
                        }
                        
                    }
               
                }
                
                cout << "\n Qual é o nome do seu amigo que você deseja adicionar? ";
                cin >> agenda[temp].nome;

                cout << "\n Qual é o telefone do seu amigo que você deseja adicionar? ";
                cin >> agenda[temp].celular;

                cout << "\n Qual é a cidade do seu amigo que você deseja adicionar? ";
                cin >> agenda[temp].cidade;

                cout << "\n Qual é o email do seu amigo que você deseja adicionar? ";
                cin >> agenda[temp].email;
                
                agenda[temp].valido = true;
                incluiu = true;
                
                cout << "\n Pronto! Incluimos seu amigo " <<agenda[temp].nome << " na agenda!" <<endl;
                
            break;
            
            case 4: //Excluir um amigo//
                
                telefone = "";
                
                cout << "\n Para achar seu amigo, primeiro digite o telefone dele: ";
                cin >> telefone;
                        
                for(int k = 0; k < TAM; k++){
                    
                    if(telefone == agenda[k].celular){
                        
                        agenda[k].valido = false;
                        cout << "\n Pronto! Excluimos seu amigo: " << agenda[k].nome <<endl;
                        
                    }
                    
                }
                
                incluiu = true;
                
            break;
            
            case 5: //Alterar dados de um amigo//
                
                string escolha;
                
                cout << "\n Primeiro, para achar seu amigo, digite o telefone dele: ";
                cin >> telefone;
                
                for (int k = 0; k < TAM; k++) {

                    if (telefone != agenda[k].celular) {

                        cout << "\n Não conseguimos localizar seu amigo!" << endl;

                        cout << "\n Digite novamente o telefone, correto, dele: ";
                        cin >> telefone;

                    } else {
                    
                    if (telefone == agenda[k].celular) {

                        cout <<"\n Conseguir localizar os dados dele!" <<endl;
                        
                        cout << "\n Digite: a) Para alterar o NOME do seu amigo; ";
                        cout << "\n Digite: b) Para alterar o CELULAR do seu amigo; ";
                        cout << "\n Digite: c) Para alterar o CIDADE do seu amigo; ";
                        cout << "\n Digite: d) Para alterar o EMAIL do seu amigo; \n ";
                        
                        cout <<"\n Qual dado do seu amigo " <<agenda[k].nome << " você gostaria de alterar? ";
                        cin >> escolha;
                        
                        if(escolha == "a" or escolha == "A"){

                            cout << "\n Qual novo NOME você gostaria de dar ao seu amigo?";
                            cin >> agenda[k].nome;
                            agenda[k].valido = true;
                            
                        }
                        
                        if (escolha == "b" or escolha == "B") {

                            cout << "\n Qual novo CELULAR você gostaria de dar ao seu amigo?";
                            cin >> agenda[k].celular;
                            agenda[k].valido = true;

                        }

                        if (escolha == "c" or escolha == "C") {

                            cout << "\n Qual nova CIDADE você gostaria de dar ao seu amigo?";
                            cin >> agenda[k].cidade;
                            agenda[k].valido = true;

                        }

                        if (escolha == "d" or escolha == "D") {

                            cout << "\n Qual novo EMAIL você gostaria de dar ao seu amigo?";
                            cin >> agenda[k].email;
                            agenda[k].valido = true;

                        }
                        
                        incluiu = true;
                    }    
                    } 
                }
                
            break;    
            
        } //Chave do Switch
        
    } while (opcao != 6);
    
    if (incluiu == true){
        
        ofstream arquivo2("agenda.txt");
    
        for (int k = 0; k < TAM; k++) {
            
            if(agenda[k].valido == true){
                
                arquivo2 << "\n" << agenda[k].nome;
                arquivo2 << "\n" << agenda[k].celular;
                arquivo2 << "\n" << agenda[k].cidade;
                arquivo2 << "\n" << agenda[k].email;
                
            } else if(agenda[k].valido == false && agenda[k].nome=="fim"){
                
                arquivo2 <<"\n"<<agenda[k].nome;
            }

        }
   
        arquivo2.close();
    
    }    

    return 0;
}