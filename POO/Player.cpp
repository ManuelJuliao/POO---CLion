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
    this->steel=0;
    this->coal=0;
    this->wood=0;
    this->woodbeams=0;
    this->energy=0;
}

Player::~Player(){

}


void Player::calcprod(vector<Ilha> *arr, Player *player1, vector<Building> *build){
    vector<Ilha>::iterator ptr;
    vector<Building>::iterator ptr2;
//    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
//        if( ptr->edif == "MnF "){
//            for (ptr2 = build->begin(); ptr2 < build->end(); ptr2++){
//                if(ptr2->x == ptr->x && ptr2->y == ptr->y){
//                    if(ptr2->power == 1){
//                        for(int i=0; i < sizeof(ptr->trab); i++){
//                            if (ptr->trab[i] == 'M') {
//                                player1->ironprod++; }
//                        }
//                    }
//                }
//            }
//
//        }
//    }
    for(ptr = arr->begin(); ptr < arr->end(); ptr++){ // percorrer array do tabuleiro
        for(ptr2 = build->begin(); ptr2 < build->end(); ptr2++){ // percorrer array de edificios
            if(ptr->x == ptr2->x && ptr->y == ptr2->y){
                if(ptr2->power == 1){
                    if(ptr2->name == "MnF " && ptr2->recursos < ptr2->cap){
                        if(ptr->zona == "dsr "){
                            ptr2->recursos += 1;
                        }
                        else if(ptr->zona == "mnt "){
                            ptr2->recursos += 4;
                        }
                        else{
                            ptr2->recursos += 2;
                        }
                    }
                    else if(ptr2->name == "MnC " && ptr2->recursos < ptr2->cap){
                        if(ptr->zona == "dsr "){
                            ptr2->recursos += 1;
                        }
                        else if(ptr->zona == "mnt "){
                            ptr2->recursos += 4;
                        }
                        else{
                            ptr2->recursos += 2;
                        }
                    }
                    else if(ptr2->name == "elec"){
                        if(player1->wood != 0 && player1->coal != 0){
                            player1->wood -= 1;
                            player1->coal -= 1;
                            player1->energy += 1;
                        }
                        else{
                            break;
                        }
                    }
                    else if(ptr2->name == "fund"){
                        if(player1->iron != 0 && player1->coal != 0){
                            player1->iron -= 1;
                            player1->coal -= 1;
                            player1->steel += 1;
                        }
                        else{
                            break;
                        }

                    }
                    else if(ptr2->name == "edx "){
                        if(player1->wood >= 2){
                            player1->wood -= 2;
                            player1->woodbeams += 1;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
    }
    //cout << player1->ironprod << endl;

}

void Player::prod(Player *player1, vector<Building> *build){
    vector<Building>::iterator ptr;
    for(ptr = build->begin(); ptr < build->end(); ptr++){
        if(ptr->name == "MnF "){
            player1->iron += ptr->recursos;
        }
        if(ptr->name == "MnC "){
            player1->coal += ptr->recursos;
        }
    }

}

