//
// Created by Manuel Juliao on 04/01/2022.
//

#include "player.h"
#include "interface.h"
#include "ilha.h"

using namespace std;


player::player() {

}

player::~player(){

}


void player::calcprod(vector<ilha> *arr, player player1){
    vector<ilha>::iterator ptr;
    int aux1=0;

    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if( ptr->edif == "minaf"){
            for(int i=0; i < sizeof(ptr->trab); i++){
                if (ptr->trab[i] == 'M') {
                    player1.ironprod++; }
            }
        }
    }

}