//
//  jogada.h
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//
#include <stdio.h>
#include <string>
#include "Ilha.h"
#include "Worker.h"
#include "Building.h"
#include "Interface.h"
#include "Player.h"

#ifndef JOGADA_H
#define JOGADA_H

using namespace std;

class Jogada{
public:
    string comm;
    string comm_sp;
    int p1,p2;
    int cont_id;

    
    int joga1(string comm, string p1, string p2, string p3, vector<Ilha> *arr,  vector<Building> *build,struct controlo *controlo, Player *player1); // construir
    void joga2(string comm, string p1, vector<Ilha> *arr, vector<Worker> *work, int dia, vector<Building> *build, struct controlo *controlo, Player *player1); // exec
    int joga3(string comm, string p1, string p2, vector<Ilha> *arr, vector<Building> *build); // liga
    int joga4(string comm, string p1, string p2, vector<Ilha> *arr,  vector<Building> *build); // desliga
    void joga5(string comm, string p1, string p2, string p3, vector<Ilha> *arr, vector<Worker> *work,vector<Building> *build); // move
    void joga6(string comm, string p1, string p2, vector<Ilha> *arr); // vende rec ou edif
    int joga7(string comm, string p1, vector<Ilha> *arr, vector<Worker> *work, int dia, vector<Building> *build,Player *player1); // contrata
    int joga8(string comm, string p1, string p2, vector<Ilha> *arr,struct controlo *controlo, Player *player1,vector<Building> *build); // lista (tudo se p1 e p2 =0)
    //void joga9(string comm, vector<Ilha> *arr); // mnext
    void joga10(string comm, string p1, vector<Ilha> *arr); // save
    void joga11(string comm, string p1, vector<Ilha> *arr); // load
    void joga12(string comm, string p1, vector<Ilha> *arr); // apaga save
    void joga13(string comm, string p1, vector<Ilha> *arr); // config
    void joga14(string comm, string p1, vector<Ilha> *arr); // deb cash
    void joga15(string comm, string p1, string p2, string p3, vector<Ilha> *arr); // debed
    void joga16(string comm, string p1, vector<Ilha> *arr); // debkill

    int valida(string comm);

    Jogada();
    ~Jogada();
};

#endif //JOGADA_H
