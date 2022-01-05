//
//  interface.hpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//


#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <stdio.h>
#include <iostream>
#include "ilha.h"
#include <vector>
#include "jogada.h"

typedef struct controlo {  //qunatidade de zonas e edificios
    int mont;
    int des;
    int pas;
    int flor;
    int pant;
    int zonX;
    int minaf;

    float nh, nv;// nº horizontal e nº vertical
} control;

class interface {
public:
    vector<ilha> mapa;
    control controlo = {0};
    
void init();
void fill();
void coor();
void print();
void menu();

interface();
~interface();
    
};



#endif //POO_INTERFACE_H
