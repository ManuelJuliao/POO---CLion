//
//  ilha.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//

#include <vector>
#include<iterator>
#include "ilha.h"
using namespace std;


ilha::ilha() {
    this->zona = "    ";
    this->edif= "    ";
    this->num_trab= 0;
    for(int i=0; i<sizeof(this->trab);i++){
        this->trab[i]= ' ';
    }
    
}

ilha::~ilha(){
    
}
