//
// Created by Manuel Juliao on 04/01/2022.
//

#ifndef POO_PLAYER_H
#define POO_PLAYER_H


#include "Ilha.h"
#include "Building.h"

class Player {
public :             // variaveis e devidas producoes por ronda
    int money;
    int iron;
    int steel;
    int coal;
    int wood;
    int woodbeams;
    int energy;
    int ntrab;

    static void calcprod(vector<Ilha> *arr, Player *player1, vector<Building> *build);
    static void prod(Player *player1, vector<Building> *build);

    Player();
    ~Player();


};


#endif //POO_PLAYER_H
