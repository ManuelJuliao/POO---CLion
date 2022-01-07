//
// Created by Manuel Juliao on 04/01/2022.
//

#include "player.h"
#include "interface.h"
#include "ilha.h"

using namespace std;


player::player() {
    this->money =0;
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

player::~player(){

}


void player::calcprod(vector<ilha> *arr, player *player1){
    vector<ilha>::iterator ptr;
    int aux1=0;

    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if( ptr->edif == "MnF "){
            for(int i=0; i < sizeof(ptr->trab); i++){
                if (ptr->trab[i] == 'M') {
                    player1->ironprod++; }
            }
        }
    }
    cout << player1->ironprod << endl;

}

void player::prod(player *player1){
    player1->iron += player1->ironprod;
}