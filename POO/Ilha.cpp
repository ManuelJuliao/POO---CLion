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
