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
    int trees;
    int maxtree;
    float prod;
    int storage;
    int maxday;

    Ilha ();
    ~Ilha();
    
};

class floresta : public Ilha {

public:

    floresta();
    ~floresta();
};

class deserto : public Ilha {

public:
    int redux_mine;
    deserto();
    ~deserto();
};

class pastagem : public Ilha {

public:
    pastagem();
    ~pastagem();
};

class montanha : public Ilha {

public:
    int mul;

    float prob;
    montanha();
    ~montanha();
};

class pantano : public Ilha {

public:

    pantano();
    ~pantano();
};

class zonax : public Ilha {

public:
    int mul;
    zonax();
    ~zonax();
};








#endif //POO_ILHA_H
