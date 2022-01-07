//
// Created by Manuel Juliao on 04/01/2022.
//

#ifndef POO_PLAYER_H
#define POO_PLAYER_H


#include "ilha.h"

class player {
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

    static void calcprod(vector<ilha> *arr, player *player1);
    static void prod(player *player1);

    player();
    ~player();


};


#endif //POO_PLAYER_H
