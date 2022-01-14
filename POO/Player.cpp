//
// Created by Manuel Juliao on 04/01/2022.
//

#include "Player.h"
#include "Interface.h"
#include "Ilha.h"

using namespace std;


Player::Player() {
    this->money =100;
    this->iron = 0;
    this->ironprod=0;
    this->steel=0;
    this->steelprod=0;
    this->coal=0;
    this->coalprod=0;
    this->wood=0;
    this->woodprod=0;
    this->woodbeams=0;
    this->energy=0;
    this->energyprod=0;
}

Player::~Player(){

}


void Player::calcprod(vector<Ilha> *arr, Player *player1, vector<Building> *build){
    vector<Ilha>::iterator ptr;
    vector<Building>::iterator ptr2;
    player1->ironprod=0;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if( ptr->edif == "MnF "){
            for (ptr2 = build->begin(); ptr2 < build->end(); ptr2++){
                if(ptr2->x == ptr->x && ptr2->y == ptr->y){
                    if(ptr2->power == 1){
                        for(int i=0; i < sizeof(ptr->trab); i++){
                            if (ptr->trab[i] == 'M') {
                                player1->ironprod++; }
                        }
                    }
                }
            }

        }
    }
    //cout << player1->ironprod << endl;

}

void Player::prod(Player *player1){
    player1->iron += player1->ironprod;
}