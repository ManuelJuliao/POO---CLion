//
//  interface.hpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//


#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <cstdio>
#include <iostream>
#include "Ilha.h"
#include <vector>
#include "Jogada.h"
#include "Player.h"
#include "Worker.h"
#include "Building.h"

typedef struct controlo {  //qunatidade de zonas e edificios
    int mont;
    int des;
    int pas;
    int flor;
    int pant;
    int zonX;
    int minaf;
    int minc;
    int central;
    int bat;
    int fund;
    int edx;


    float nh, nv;// nº horizontal e nº vertical
} control;

class Interface {
public:
    vector<Ilha> mapa;
    vector<Worker> workers;
    vector<Building> buildings;
    control controlo = {0};
    int day=1;
    
void init();
void fill();
void coor();
void print();
void menu();
void night(vector<Ilha> *mapa, Player *player1, vector<Worker> *workers,vector<Building> *buildings);
void dawn(vector<Ilha> *mapa, Player *player1, vector<Worker> *workers, vector<Building> *buildings);

Interface();
~Interface();
    
};



#endif //POO_INTERFACE_H
