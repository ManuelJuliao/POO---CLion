//
//  ilha.hpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//


#ifndef ILHA_H
#define ILHA_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;



class Ilha {
public:
    int x,y;
    string zona;
    string edif;
    char trab[50]; //string trabalhadores
    int num_trab;
    Ilha ();
    ~Ilha();
    
};




#endif //POO_ILHA_H