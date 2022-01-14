//
// Created by Manuel Julião on 11/01/2022.
//

#include "Building.h"

Building::Building(){

}

Building::~Building() {

}
minaf::minaf(int x, int y, char trablist[]) {
    this->lvl=1;
    this->x = x;
    this->y = y;
    this->cap=100;
    this->name = "MnF ";
    this->perc = 0.15;
    this->power = 0;
    for(int i=0; i<50;i++){
        this->trab[i] = trablist[i];
    }
}

minaf::~minaf() {

}


minc::minc(int x, int y, char trablist[]) {
    this->lvl=1;
    this->x = x;
    this->y = y;
    this->cap=100;
    this->name = "MnC ";
    this->perc = 0.1;
    this->power = 0;
    for(int i=0; i<50;i++){
        this->trab[i] = trablist[i];
    }
}

minc::~minc() {

}

central::central(int x, int y, char trablist[]) {
    this->x = x;
    this->y = y;
    this->cap=100;
    this->name = "elec";
    this->power = 0;
    for(int i=0; i<50;i++){
        this->trab[i] = trablist[i];
    }
}

central::~central() {

}

bat::bat(int x, int y, char trablist[]) {
    this->x = x;
    this->y = y;
    this->cap=100;
    this->name = "bat ";
    this->power = 0;
    for(int i=0; i<50;i++){
        this->trab[i] = trablist[i];
    }
}

bat::~bat() {

}

fund::fund(int x, int y, char *trablist) {
    this->x = x;
    this->y = y;
    this->name = "bat ";
    this->power = 0;
    for(int i=0; i<50;i++){
        this->trab[i] = trablist[i];
    }
}

fund::~fund(){

}

edx::edx(int x, int y, char *trablist) {
    this->x = x;
    this->y = y;
    this->name = "edx ";
    for(int i=0; i<50;i++){
        this->trab[i] = trablist[i];
    }
}

edx::~edx() {

}