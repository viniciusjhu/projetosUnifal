/*
 * File:   main.cpp
 * Author: Vinicius Ribeiro da Silva do Carmo ( 2023.2.08.003 )
 *
 * Created on 10 de maio de 2024, 15:00
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

const int TAM = 100;

using namespace std;

// Projeto de Base de Dados de Veículos  //

typedef struct {
    bool valido;
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potMotor;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string portas;
    string placa;
    double valor;

} Veiculo;

int main() {
    
    Veiculo bancoDados;
    Veiculo dataBase[TAM];
    
    cout << fixed << setprecision(2) << endl;

    int opcao = 0;
    int i, qtdCarros, qtdTotal;
    float porcentagem, precoMinimo, precoMaximo;
    bool incluiu, buscou;
    char opcao2;
    string placa, tipo, cambio, teste;
    
    teste = "";
    
    //Case 3//
    int totalVeiculos, totalKM, km = 0;

    int t = 6;
    int c = 3;

    string tipos[t] = {"Hatch", "SUV", "Pick-up", "Sedan", "Van", "Passeio"};
    string combustiveis[c] = {"Flex", "Diesel", "Gasolina"};
    
    string placaMaisBarato;
    float valorMaisBarato = 0.0;
    float prestacao = 0.0;
    bool tem = false;

    string placaMaisCaro;
    float valorMaisCaro = 0.0;
    float seguro = 0.0;
    bool tem2 = false;
    
    float mediaKM = 0.0;
    
    //Case 4//
    
    string placa2;

    incluiu = false;
   
    i = 0;
    qtdCarros = 0;
    
    cout << "\n-------------------------------------------------------------" << endl;
    cout << "\n \t Bem-vindo(a) ao nosso sistema veícular                   " << endl;
    cout << "\n-------------------------------------------------------------" << endl;

    ifstream arquivo("BD_veiculos.txt");
    if (!arquivo.is_open()) {
        cout << "Erro: arquivo não existe" << endl;
        return 1;
    }
    
    int cont = 0;
    
    //Lendo os dados do arquivo//
    
    for(i = 0; i < TAM && dataBase[i].modelo != "fim"; i++){
        
        arquivo >> dataBase[i].modelo;
        arquivo >> dataBase[i].marca;
        arquivo >> dataBase[i].tipo;
        arquivo >> dataBase[i].ano;
        arquivo >> dataBase[i].km;
        arquivo >> dataBase[i].potMotor;
        arquivo >> dataBase[i].combustivel;
        arquivo >> dataBase[i].cambio;
        arquivo >> dataBase[i].direcao;
        arquivo >> dataBase[i].cor;
        arquivo >> dataBase[i].portas;
        arquivo >> dataBase[i].placa;
        arquivo >> dataBase[i].valor;

        if (dataBase[i].modelo == "fim") {
            
            dataBase[i].valido = false;
            break;

        } else {

            dataBase[i].valido = true;
        } 
        
    }
    
    qtdCarros = i;
    qtdTotal = i;

    arquivo.close();

    do {

        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n Escolha qual opção deseja proseguir: " << endl;
        cout << "\n 1: Buscar um veículo";
        cout << "\n 2: Incluir um veículo";
        cout << "\n 3: Criar um relatório";
        cout << "\n 4: Excluir um veículo";
        cout << "\n 5: Alterar dados de um veículo";
        cout << "\n 6: Salvar e Sair" << endl;
        cout << "\n Digite a opção desejada: ";
        cin >> opcao;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

        switch (opcao) {
            
            case 1: //Buscar um Veículo//
                
                do{

                    cout << "\n Certo. Escolha como você deseja buscar o veículo: " << endl;
                    cout << "\n a: Buscar pela Placa";
                    cout << "\n b: Buscar pelo Tipo de veículo";
                    cout << "\n c: Buscar pelo Câmbio";
                    cout << "\n d: Buscar pela faixa de preço";
                    cout << "\n s: Sair" << endl;
                    cout << "\n Digite a opção desejada: ";
                    cin >> opcao2;
                    
                    switch (opcao2) {
                        
                        case 'a': //Buscar pela Placa//
                           
                            cout << "\n Qual é a placa do veículo? ";
                            cin >> placa;
                            
                            buscou = false;
                            
                            for (int a = 0; a < TAM && dataBase[a].modelo != "fim"; a++) {

                                if (dataBase[a].placa == placa) {

                                    cout << "------------------------------------------------------------------------------------" << endl;
                                    cout << "\n Achei o veículo que você está buscando! Confira os dados dele: \n \n";
                                    cout << "\t O modelo dele é: " << dataBase[a].modelo << endl;
                                    cout << "\t A marca do veículo é: " << dataBase[a].marca << endl;
                                    cout << "\t O tipo do veículo é: " << dataBase[a].tipo << endl;
                                    cout << "\t O ano dele é: " << dataBase[a].ano << endl;
                                    cout << "\t A quilometragem dele é: " << dataBase[a].km << endl;
                                    cout << "\t A potência do motor é: " << dataBase[a].potMotor << endl;
                                    cout << "\t O tipo de combustível deste veículo é: " << dataBase[a].combustivel << endl;
                                    cout << "\t O tipo de câmbio deste veículo é: " << dataBase[a].cambio << endl;
                                    cout << "\t O tipo de direção deste veículo é: " << dataBase[a].direcao << endl;
                                    cout << "\t A cor do veículo é: " << dataBase[a].cor << endl;
                                    cout << "\t Este veículo tem " << dataBase[a].portas << " portas" << endl;
                                    cout << "\t O valor deste veículo é: R$" << dataBase[a].valor << endl;
                                    
                                    buscou = true;
                                    
                                }    

                            }
                            
                            if(buscou == false){
                                
                                cout << "\n Não encontrei este veículo! \n \n";
                                
                            }    
                            
                        break;    
                        
                        case 'b': //Buscar pelo Tipo de veículo//
                            
                            cout << "\n Qual é o tipo do veículo? ";
                            cin >> tipo;
                            
                            buscou = false;
                            
                            for (int b = 0; b < TAM && dataBase[b].modelo != "fim"; b++) {
                                
                                if (dataBase[b].tipo == tipo) {

                                    cout << "------------------------------------------------------------------------------------" << endl;
                                    cout << "\n Achei o veículo que você está buscando! Confira os dados dele: \n \n";
                                    cout << "\t O modelo dele é: " << dataBase[b].modelo << endl;
                                    cout << "\t A marca do veículo é: " << dataBase[b].marca << endl;
                                    cout << "\t O ano dele é: " << dataBase[b].ano << endl;
                                    cout << "\t A quilometragem dele é: " << dataBase[b].km << endl;
                                    cout << "\t A potência do motor é: " << dataBase[b].potMotor << endl;
                                    cout << "\t O tipo de combustível deste veículo é: " << dataBase[b].combustivel << endl;
                                    cout << "\t O tipo de câmbio deste veículo é: " << dataBase[b].cambio << endl;
                                    cout << "\t O tipo de direção deste veículo é: " << dataBase[b].direcao << endl;
                                    cout << "\t A cor do veículo é: " << dataBase[b].cor << endl;
                                    cout << "\t Este veículo tem " << dataBase[b].portas << " portas" << endl;
                                    cout << "\t A placa respectiva deste veículo é: " << dataBase[b].placa << endl;
                                    cout << "\t O valor deste veículo é: R$" << dataBase[b].valor << endl;

                                buscou = true;

                                }

                            }

                            if (buscou == false) {

                                cout << "\n Não encontrei este veículo! \n \n";

                            }   
                            
                        break;    
                        
                        case 'c': //Buscar pelo Câmbio//
                            
                            cout << "\n Qual é o tipo de câmbio do veículo? ";
                            cin >> cambio;
                            
                            buscou = false;
                            
                            for (int c = 0; c < TAM && dataBase[c].modelo != "fim"; c++) {

                                if (dataBase[c].cambio == cambio) {

                                    cout << "------------------------------------------------------------------------------------" << endl;
                                    cout << "\n Achei o veículo que você está buscando! Confira os dados dele: \n \n";
                                    cout << "\t O modelo dele é: " << dataBase[c].modelo << endl;
                                    cout << "\t A marca do veículo é: " << dataBase[c].marca << endl;
                                    cout << "\t O tipo do veículo é: " << dataBase[c].tipo << endl;
                                    cout << "\t O ano dele é: " << dataBase[c].ano << endl;
                                    cout << "\t A quilometragem dele é: " << dataBase[c].km << endl;
                                    cout << "\t A potência do motor é: " << dataBase[c].potMotor << endl;
                                    cout << "\t O tipo de combustível deste veículo é: " << dataBase[c].combustivel << endl;
                                    cout << "\t O tipo de direção deste veículo é: " << dataBase[c].direcao << endl;
                                    cout << "\t A cor do veículo é: " << dataBase[c].cor << endl;
                                    cout << "\t Este veículo tem " << dataBase[c].portas << " portas" << endl;
                                    cout << "\t A placa respectiva deste veículo é: " << dataBase[c].placa << endl;
                                    cout << "\t O valor deste veículo é: R$" << dataBase[c].valor << endl;

                                    buscou = true;
                                }

                            }

                            if (buscou == false) {

                                cout << "\n Não encontrei este veículo! \n \n";

                            }    
                            
                        break;    
                        
                        case 'd': //Buscar pela faixa de preço//
                          
                            cout << "\n Qual é o preço mínimo deste veículo? ";
                            cin >> precoMinimo;
                            
                            cout << "\n Qual é o preço máximo deste veículo? ";
                            cin >> precoMaximo;
                            
                            buscou = false;
                            
                            for (int d = 0; d < TAM && dataBase[d].modelo != "fim"; d++) {

                                if (dataBase[d].valor >= precoMinimo && dataBase[d].valor <= precoMaximo) {

                                    cout << "------------------------------------------------------------------------------------" << endl;
                                    cout << "\n Achei este veículo nesta faixa de preço! Confira os dados dele: \n \n";
                                    cout << "\t O modelo dele é: " << dataBase[d].modelo << endl;
                                    cout << "\t A marca do veículo é: " << dataBase[d].marca << endl;
                                    cout << "\t O tipo do veículo é: " << dataBase[d].tipo << endl;
                                    cout << "\t O ano dele é: " << dataBase[d].ano << endl;
                                    cout << "\t A quilometragem dele é: " << dataBase[d].km << endl;
                                    cout << "\t A potência do motor é: " << dataBase[d].potMotor << endl;
                                    cout << "\t O tipo de combustível deste veículo é: " << dataBase[d].combustivel << endl;
                                    cout << "\t O tipo de câmbio deste veículo é: " << dataBase[d].cambio << endl;
                                    cout << "\t O tipo de direção deste veículo é: " << dataBase[d].direcao << endl;
                                    cout << "\t A cor do veículo é: " << dataBase[d].cor << endl;
                                    cout << "\t Este veículo tem " << dataBase[d].portas << " portas" << endl;
                                    cout << "\t A placa respectiva deste veículo é: " << dataBase[d].placa << endl;
                                    cout << "\t O valor deste veículo é: R$" << dataBase[d].valor << endl;

                                    buscou = true;

                                }

                            }

                            if (buscou == false) {

                                cout << "\n Não encontrei este veículo! \n \n";

                            }    
                            
                        break;    
                            
                    }
                    
                    
                } while (opcao2 != 's');
                
            break;
            
            case 2: //Incluir um veículo//
                
                //Verificando qual é a última posição do registro//
                
                int temp;

                temp = -1;

                for (int k = 0; k < TAM && temp == -1; k++) {

                    if (dataBase[k].valido == false) {

                        temp = k;
                        
                        if (dataBase[k].modelo == "fim"){

                            dataBase[k + 1].modelo = "fim";
                            dataBase[k + 1].modelo = false;
                            qtdTotal++;
                        }

                    }

                }
                
                //Após encontrar um índice disponível, o programa solicita ao usuário que insira várias informações sobre o veículo//

                cout << "\n Qual é o modelo do veículo? ";
                cin >> dataBase[temp].modelo;

                cout << "\n Qual é a marca do veículo? ";
                cin >> dataBase[temp].marca;

                cout << "\n Qual o tipo do veículo? ";
                cin >> dataBase[temp].tipo;

                cout << "\n Qual é o ano do veículo? ";
                cin >> dataBase[temp].ano;
                
                cout << "\n Qual é a kilometragem do veículo? ";
                cin >> dataBase[temp].km;
                
                cout << "\n Qual é a potência do motor? ";
                cin >> dataBase[temp].potMotor;
                
                cout << "\n Qual é o tipo de combustível deste veículo? ";
                cin >> dataBase[temp].combustivel;
                
                cout << "\n Qual é o câmbio do veículo? ";
                cin >> dataBase[temp].cambio;
                
                cout << "\n Qual é o tipo de direção deste veículo? ";
                cin >> dataBase[temp].direcao;
                
                cout << "\n Digite a cor do veículo: ";
                cin >> dataBase[temp].cor;
                
                cout << "\n Quantas portas este veículo possui? ";
                cin >> dataBase[temp].portas;
                
                cout << "\n Agora, digite a placa deste veículo: ";
                cin >> dataBase[temp].placa;
                
                cout << "\n Qual é o valor deste veículo? ";
                cin >> dataBase[temp].valor;

                dataBase[temp].valido = true;
                incluiu = true;

                cout << "\n Pronto! Incluimos o veículo " << dataBase[temp].modelo << " no banco de dados!" << endl;
                
            break;    
            
            case 3: //Criar um relatório//
                
                cout << "\n Criando seu relatório..." <<endl;
                
                cout << "\n Temos um total de " << qtdCarros << " carro(s) em nosso banco de dados" <<endl;
                
                cout << "\n ----------------------------------------------------------------------------------------" << endl;
                cout << "\n - Aqui está um relatório com porcentagens: " <<endl;

                for (int k = 0; k < t; k++) {
                    
                    int qtd = 0;
                    float porcentagem = 0.0;

                    for (int j = 0; j < TAM && dataBase[j].modelo != "fim"; j++) {
                        if (dataBase[j].tipo == tipos[k]) {
                            qtd++;
                        }
                    }

                    porcentagem = (qtd * 100.0) / qtdCarros;

                    cout << "\n \t Há " << porcentagem << "% de carros do tipo " << tipos[k] << " em nosso banco de dados" << endl;
                }

                
                for (int k = 0; k < c; k++) {
                    
                    int qtd = 0;
                    double porcentagem = 0.0;

                    for (int j = 0; j < TAM && dataBase[j].modelo != "fim"; j++) {
                        
                        if (dataBase[j].combustivel == combustiveis[k]) {
                            qtd++;
                        }
                        
                    }

                    porcentagem = (qtd * 100.0) / qtdCarros;
                    
                    cout << "\n \t Há " << porcentagem << "% de carros com combustível " << combustiveis[k] << " em nosso banco de dados" << endl;
                }
                
                cout << "\n ----------------------------------------------------------------------------------------" << endl;
                cout << "\n - Aqui está um relatório do veículo mais barato com potência do motor 1.0: " <<endl;
                
                for(int k = 0; k <= qtdTotal; k++){
                    
                    if(dataBase[k].valido == true){
                        
                        if (dataBase[k].potMotor == 1 or dataBase[k].potMotor == 1.0) {

                            tem = true;
                            
                            if(valorMaisBarato == 0){
                                valorMaisBarato = dataBase[k].valor;
                            }
                            
                            if(tem == true){
                                
                               if (dataBase[k].valor <= valorMaisBarato) {
                                    placaMaisBarato = dataBase[k].placa;
                                    valorMaisBarato = dataBase[k].valor;
                                } 
                                
                            }
                            
                        }
                        
                        if (dataBase[k].direcao == "Hidráulica" && dataBase[k].cambio == "Automático") {

                            tem2 = true;
                            
                            if(valorMaisCaro == 0){
                                valorMaisCaro = dataBase[k].valor;
                            }
                            
                            if(tem2 == true){
                                
                                if (dataBase[k].valor >= valorMaisCaro) {
                                    placaMaisCaro = dataBase[k].placa;
                                    valorMaisCaro = dataBase[k].valor;
                                }
                                
                            }
                                    
                                    
                        }
                        
                    }
                    
                }
                
                if(tem == false or tem2 == false){
                    
                    cout <<"\nNão encontrei nenhum carro com as especificações" <<endl;
                    
                }
                    
                prestacao = ((valorMaisBarato * pow(1 + 0.0166, 60)) / 60);

                cout << "\n \tO veículo tem a placa: " << placaMaisBarato << endl;
                cout << "\n \tO seu valor é: R$" << valorMaisBarato << endl;
                cout << "\n \tO valor da prestação do financiamento em 60 meses é: R$" << prestacao << "/Mês" << endl;
                  
                cout << "\n ----------------------------------------------------------------------------------------" << endl;
                cout << "\n - Aqui está um relatório do veículo mais caro com direção hidráulica e câmbio automático: " << endl;


                seguro = (valorMaisCaro * 0.065);

                cout << "\n \tO veículo tem a placa: " << placaMaisCaro << endl;
                cout << "\n \tO seu valor é: R$" << valorMaisCaro << endl;
                cout << "\n \tO valor do seguro é de: R$" << seguro << " levando em conta uma porcentagem de 6,5% sobre o valor do veículo" << endl;

                cout << "\n ----------------------------------------------------------------------------------------" << endl;
                cout << "\n - Aqui está um relatório com a quantidade e média de quilometragem dos veículos com 5 anos ou mais (Ano Ref.: 2024): " << endl;
                
                for(int k = 0; k < TAM && dataBase[k].modelo != "fim"; k++){
                    
                    if ((2024 - dataBase[k].ano) >= 5) {
                        totalVeiculos++;
                        km = dataBase[k].km;
                        totalKM = totalKM + km;
                    }
                }    
                
                if (totalVeiculos > 0) {
                    
                    mediaKM = (totalKM / totalVeiculos);
                    
                    cout << "\n \tQuantidade de veículos com 5 anos ou mais: " << totalVeiculos << endl;
                    cout << "\n \tMédia de quilometragem dos veículos com 5 anos ou mais: " << mediaKM << "km" << endl;
                    
                } else {
                    cout << "Não há veículos com 5 anos ou mais no banco de dados." << endl;
                }
                
            break;    
            
            case 4: //Excluir um veículo//

                cout << "\n Para achar qual veículo deseja excluir, digite a placa deste veículo corretamente: ";
                cin >> placa2;

                for (int k = 0; k < TAM; k++) {

                    if (placa2 == dataBase[k].placa) {

                        dataBase[k].valido = false;
                        cout << "\n Pronto! Excluimos o veículo: " << dataBase[k].modelo << endl;

                    }

                }

                incluiu = true;
                
            break;    
            
            case 5: //Alterar dados de um veículo//

                string escolha, placa3;
                bool achou, feito = false;
                bool continuar = true;

                while (continuar == true) {

                    if (feito == false) {

                        cout << "\n Primeiro, para encontrar o veículo, digite corretamente a placa: ";
                        cin >> placa3;

                    }

                    if (feito == true) {

                        cout << "\n Digite a placa do veículo corretamente: ";
                        cin >> placa3;

                    }

                    for (int k = 0; k < qtdTotal; k++) {

                        if (placa3 == dataBase[k].placa) {

                            achou = true;

                            cout << "\n Conseguir localizar o veículo!" << endl;

                            while (escolha != "s" and escolha != "S") {

                                cout << "\n--------------------------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "\n Digite: a) Para alterar o MODELO do veículo; ";
                                cout << "\n Digite: b) Para alterar a MARCA do veículo; ";
                                cout << "\n Digite: c) Para alterar a CATEGORIA do veículo; ";
                                cout << "\n Digite: d) Para alterar o ANO do veículo; ";
                                cout << "\n Digite: e) Para alterar a QUILOMETRAGEM do veículo; ";
                                cout << "\n Digite: f) Para alterar a POTÊNCIA DO MOTOR do veículo; ";
                                cout << "\n Digite: g) Para alterar o TIPO DE COMBUSTÍVEL do veículo; ";
                                cout << "\n Digite: h) Para alterar o TIPO DE CÂMBIO do veículo; ";
                                cout << "\n Digite: i) Para alterar o TIPO DE DIREÇÃO do veículo; ";
                                cout << "\n Digite: j) Para alterar a COR do veículo; ";
                                cout << "\n Digite: k) Para alterar o Nº DE PORTAS do veículo; ";
                                cout << "\n Digite: l) Para alterar a PLACA do veículo; ";
                                cout << "\n Digite: m) Para alterar o VALOR do veículo; ";
                                cout << "\n Digite: s) Para SAIR da edição; \n ";
                                cout << "\n--------------------------------------------------------------------------------------------------------------------------------------" << endl;

                                cout << "\n Qual dado do veículo " << dataBase[k].modelo << " você gostaria de alterar? ";
                                cin >> escolha;

                                if (escolha == "a" or escolha == "A") {

                                    cout << "\n Qual novo MODELO você gostaria dar para o veículo? ";
                                    cin >> dataBase[k].modelo;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "b" or escolha == "B") {

                                    cout << "\n Qual a nova MARCA do veículo? ";
                                    cin >> dataBase[k].marca;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "c" or escolha == "C") {

                                    cout << "\n Qual nova CATEGORIA do veículo? ";
                                    cin >> dataBase[k].tipo;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "d" or escolha == "D") {

                                    cout << "\n Qual novo ANO do veículo? ";
                                    cin >> dataBase[k].ano;
                                    dataBase[k].valido = true;

                                }
                                
                                if (escolha == "e" or escolha == "E") {

                                    cout << "\n Qual a nova QUILOMETRAGEM do veículo? ";
                                    cin >> dataBase[k].km;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "f" or escolha == "F") {

                                    cout << "\n Qual a nova a POTÊNCIA DO MOTOR do veículo? ";
                                    cin >> dataBase[k].potMotor;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "g" or escolha == "G") {

                                    cout << "\n Qual é o novo TIPO DE COMBUSTÍVEL do veículo? ";
                                    cin >> dataBase[k].combustivel;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "h" or escolha == "H") {

                                    cout << "\n Qual é o novo TIPO DE CÂMBIO do veículo? ";
                                    cin >> dataBase[k].cambio;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "i" or escolha == "I") {

                                    cout << "\n Qual é o novo TIPO DE DIREÇÃO do veículo? ";
                                    cin >> dataBase[k].direcao;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "j" or escolha == "J") {

                                    cout << "\n Qual é a nova COR do veículo? ";
                                    cin >> dataBase[k].cor;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "k" or escolha == "K") {

                                    cout << "\n Qual novo Nº DE PORTAS do veículo? ";
                                    cin >> dataBase[k].portas;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "l" or escolha == "L") {

                                    cout << "\n Qual é a nova PLACA do veículo? ";
                                    cin >> dataBase[k].placa;
                                    dataBase[k].valido = true;

                                }

                                if (escolha == "m" or escolha == "M") {

                                    cout << "\n Qual é o novo VALOR do veículo? ";
                                    cin >> dataBase[k].valor;
                                    dataBase[k].valido = true;

                                }

                                incluiu = true;
                            }

                            continuar = false;
                        }
                    }

                    feito = true;

                    if (achou == false) {

                        cout << "\n Não encontrei nenhum veículo!" << endl;

                    } else {
                        
                        cout << "\n Alterei os dados do veículo" <<endl;
                        
                    }

                }
                
            break;   
            
        } //Chave do Switch
    } while (opcao != 6);    
    
    //Após inclusão, exclusão ou alterações no veículo//
    
    if (incluiu == true) {

        ofstream arquivo2("BD_veiculos.txt");

        for (int k = 0; k <= qtdTotal; k++) {

            if (dataBase[k].valido == true) {
                
                arquivo2 << dataBase[k].modelo << " " << dataBase[k].marca << " " << dataBase[k].tipo << " " << dataBase[k].ano << " " << dataBase[k].km << " " << dataBase[k].potMotor << " " << dataBase[k].combustivel << " " << dataBase[k].cambio << " " << dataBase[k].direcao << " " << dataBase[k].cor << " " << dataBase[k].portas << " " << dataBase[k].placa << " " << dataBase[k].valor <<endl;

            }
            
        }
        
        arquivo2 << "fim" <<endl;
        
        arquivo2.close();

    }

    return 0;
    
}