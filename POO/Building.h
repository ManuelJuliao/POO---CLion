//
// Created by Manuel Julião on 11/01/2022.
//
#include <string>

#ifndef POO_BUILDING_H
#define POO_BUILDING_H


using namespace std;


class Building {
public:
    int lvl;
    int cap; // capacidade
    int recursos;
    int power; // 0 ou 1. on or off
    int x,y; // coor
    float perc; // probabilidade de desabar
    string name; // name
    char trab[50]; //string trabalhadores
    int cost;

    Building();
    ~Building();


};

class minaf : public Building {

public:
    minaf(int x,int y, char trablist[], int cost);
    ~minaf();
};

class minc : public Building {

public:
    minc(int x,int y, char trablist[], int cost);
    ~minc();
};

class central : public Building {

public:
    central(int x, int y, char trablist[], int cost);
    ~central();
};

class bat : public Building {

public:
    bat(int x, int y, char trablist[], int cost);
    ~bat();
};

class fund : public Building {

public:
    fund(int x, int y, char trablist[], int cost);
    ~fund();
};

class edx : public Building { //serraçao

public:
    edx(int x, int y, char trablist[], int cost);
    ~edx();
};




#endif //POO_BUILDING_H
