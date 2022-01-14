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
    int power; // 0 ou 1. on or off
    int x,y; // coor
    float perc; // probabilidade de desabar
    string name; // name
    char trab[50]; //string trabalhadores

    Building();
    ~Building();


};

class minaf : public Building {

public:
    minaf(int x,int y, char trablist[]);
    ~minaf();
};

class minc : public Building {

public:
    minc(int x,int y, char trablist[]);
    ~minc();
};

class central : public Building {

public:
    central(int x, int y, char trablist[]);
    ~central();
};

class bat : public Building {

public:
    bat(int x, int y, char trablist[]);
    ~bat();
};

class fund : public Building {

public:
    fund(int x, int y, char trablist[]);
    ~fund();
};

class edx : public Building {

public:
    edx(int x, int y, char trablist[]);
    ~edx();
};




#endif //POO_BUILDING_H
