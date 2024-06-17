/* 
 * File:   matrizes.h
 * Author: Vinicius Ribeiro da Silva do Carmo (2023.2.08.003)
 *
 * Created on June 12, 2024, 4:18 PM
 */

#ifndef MATRIZES_H
#define MATRIZES_H

const int maxDeLinhas = 100;
const int maxDeColunas = 100;

typedef struct{
    
    int linhas;
    int colunas;
    int matArmazem[maxDeLinhas][maxDeColunas];
    
}tMatriz;

tMatriz criarMatriz(int linhas, int colunas);
void preencherMatriz(tMatriz& matriz);
void imprimirMatriz(const tMatriz& matriz);
tMatriz transpostaMatriz(const tMatriz& matriz);
tMatriz somaMatriz(const tMatriz& matriz1, const tMatriz& matriz2);
tMatriz multiplicacaoMatriz(const tMatriz& matriz1, const tMatriz& matriz2);
double mediaMatriz(const tMatriz& matriz);

#endif /* MATRIZES_H */

