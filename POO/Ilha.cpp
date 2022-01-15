//
//  Ilha.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//

#include <vector>
#include<iterator>
#include "Ilha.h"
using namespace std;


Ilha::Ilha() {
    this->zona = "    ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    
}

Ilha::~Ilha(){
    
}

floresta::floresta() {
    this->x=0;
    this->y=0;
    this->zona = "flr ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    this->trees = rand() % 40 + 20; //entre 20 e 40 arvores

}

floresta::~floresta() {

}

deserto::deserto() {
    this->x=0;
    this->y=0;
    this->zona = "dsr ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    this->redux_mine= 0.5;
}

deserto::~deserto() {

}

pastagem::pastagem() {
    this->x=0;
    this->y=0;
    this->zona = "pas ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
}

pastagem::~pastagem() {

}

montanha::montanha() {
    this->x=0;
    this->y=0;
    this->zona = "mnt ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    this->mul = 2;
    this->prod= 0.1;
    this->storage=0;
    this->prob=0.05;
}

montanha::~montanha() {

}

pantano::pantano() {
    this->x=0;
    this->y=0;
    this->zona = "pan ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    this->maxday = 10;
}

pantano::~pantano() {

}

zonax::zonax() {
    this->x=0;
    this->y=0;
    this->zona = "ZnX ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    this->mul = 0.5;
}

zonax::~zonax() {

}
