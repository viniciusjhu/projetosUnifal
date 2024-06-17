/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2023.2.08.003
 *
 * Created on 25 de março de 2024, 16:08
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*Loop Infinito*/
int main() {
    
    long int anteriorLONG, proximoLONG;
    
    anteriorLONG = -1;
    proximoLONG = 0;
    
    while (proximoLONG > anteriorLONG){
        anteriorLONG = proximoLONG;
        proximoLONG++;
    }
    
    printf("\n Valor de anterior LONG: %d", anteriorLONG);
    printf("\n Valor de proximo LONG: %d", proximoLONG);
    
    //short int anteriorSHORT, proximoSHORT;
    
    //anteriorSHORT = -1;
    //proximoSHORT = 0;
    
    //while (proximoSHORT > anteriorSHORT){
        //anteriorSHORT = proximoSHORT;
        //proximoSHORT++;
    //}
    
    //printf("\n Valor de anterior SHORT: %d", anteriorSHORT);
    //printf("\n Valor de proximo SHORT: %d", proximoSHORT);
    
    //unsigned int anteriorUS, proximoUS;
    
    //anteriorUS = 1;
    //proximoUS = 2;
    
    //while (proximoUS > anteriorUS){
        //anteriorUS = proximoUS;
        //proximoUS++;
    //}
    
    //printf("\n Valor de anterior US: %d", anteriorUS);
    //printf("\n Valor de proximo US: %d", proximoUS);
            
    return 0;
}