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
    int ironprod;
    int steel;
    int steelprod;
    int coal;
    int coalprod;
    int wood;
    int woodprod;
    int woodbeams;
    int energy;
    int energyprod;

    static void calcprod(vector<Ilha> *arr, Player *player1, vector<Building> *build);
    static void prod(Player *player1);

    Player();
    ~Player();


};


#endif //POO_PLAYER_H
