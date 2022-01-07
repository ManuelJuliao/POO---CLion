//
//  jogada.h
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//

#ifndef jogada_h
#define jogada_h

#include <stdio.h>
#include <string>
#include "ilha.h"
using namespace std;


class jogada{
public:
    string comm;
    string comm_sp;
    int p1,p2;
    int cont_id;
    
    
    void joga1(string comm, string p1, string p2, string p3, vector<ilha> *arr); // construir
    void joga2(string comm, string p1, vector<ilha> *arr); // exec
    void joga3(string comm, string p1, string p2, vector<ilha> *arr); // liga
    void joga4(string comm, string p1, string p2, vector<ilha> *arr); // desliga
    void joga5(string comm, string p1, string p2, string p3, vector<ilha> *arr); // move
    void joga6(string comm, string p1, string p2, vector<ilha> *arr); // vende rec ou edif
    void joga7(string comm, string p1, vector<ilha> *arr); // contrata
    void joga8(string comm, string p1, string p2, vector<ilha> *arr); // lista (tudo se p1 e p2 =0)
    void joga9(string comm, vector<ilha> *arr); // mnext
    void joga10(string comm, string p1, vector<ilha> *arr); // save
    void joga11(string comm, string p1, vector<ilha> *arr); // load
    void joga12(string comm, string p1, vector<ilha> *arr); // apaga save
    void joga13(string comm, string p1, vector<ilha> *arr); // config
    void joga14(string comm, string p1, vector<ilha> *arr); // deb cash
    void joga15(string comm, string p1, string p2, string p3, vector<ilha> *arr); // debed
    void joga16(string comm, string p1, vector<ilha> *arr); // debkill


    









    int valida(string comm);

    jogada();
    ~jogada();
};

#endif /* jogada_h */
