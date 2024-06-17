/*
 * File:   matrizVendas.cpp
 * Author: 2023.2.08.003
 *
 * Created on 4 de junho de 2024, 15:08
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Código que calcula a qtd produtos foram vendidos por mês e qual foi o total de produtos vendidos no ano //

int main() {

    string meses[] = {"Jan", "Fev", "Mar", "Apr", "Mai", "Jun", "Jul", "Aug", "Set", "Oct", "Nov", "Dec"};
    string produtos[] = {"Produto1", "Produto2", "Produto3", "Produto4", "Produto5", "Produto6", "Produto7", "Produto8", "Produto9", "Produto10"};

    const int numProduts = 10;
    const int numMeses = 12;
    
    int vendas[numProduts][numMeses] = {
        {100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650},
        {110, 160, 210, 260, 310, 360, 410, 460, 510, 560, 610, 660},
        {120, 170, 220, 270, 320, 370, 420, 470, 520, 570, 620, 670},
        {130, 180, 230, 280, 330, 380, 430, 480, 530, 580, 630, 680},
        {140, 190, 240, 290, 340, 390, 440, 490, 540, 590, 640, 690},
        {150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700},
        {160, 210, 260, 310, 360, 410, 460, 510, 560, 610, 660, 710},
        {170, 220, 270, 320, 370, 420, 470, 520, 570, 620, 670, 720},
        {180, 230, 280, 330, 380, 430, 480, 530, 580, 630, 680, 730},
        {190, 240, 290, 340, 390, 440, 490, 540, 590, 640, 690, 740}
    };

    // Calculando o total de vendas por mês //
    
    double totalPorMes[numMeses];
    
    for (int i = 0; i < numMeses; i++) {
        
        for (int j = 0; j < numProduts; j++) {
            
            totalPorMes[i] += vendas[j][i];
            
        }
        
    }

    // Calculando o total de vendas por produto //
    
    double totalPorProduto[numProduts];
    
    for (int i = 0; i < numProduts; i++) {
        
        for (int j = 0; j < numMeses; j++) {
            
            totalPorProduto[i] += vendas[i][j];
            
        }
    }

    // Definindo a largura fixa para as colunas //
    int colWidth = 11.5;

    // Exibindo os resultados em formato de tabela //
    
    cout << setw(colWidth) << " ";
    for (int mes = 0; mes < numMeses; mes++) {
        cout << setw(colWidth) << meses[mes];
    }
    
    cout << setw(colWidth) << "Total" << endl;

    for (int produto = 0; produto < numProduts; produto++) {
        cout << setw(colWidth) << produtos[produto];
        for (int mes = 0; mes < numMeses; mes++) {
            cout << setw(colWidth) << vendas[produto][mes];
        }
        cout << setw(colWidth) << totalPorProduto[produto] << endl;
    }
    
    cout << setw(colWidth) << "Tot. p/mês:";
    for (int mes = 0; mes < numMeses; mes++) {
        cout << setw(colWidth) << totalPorMes[mes];
    }
    cout << endl;

    return 0;
    
}