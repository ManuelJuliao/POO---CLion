//
//  interface.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//


#include "interface.h"
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>
#include "jogada.h"
#include <iostream>
#include <sstream>

using namespace std;


interface::interface(){}

interface::~interface(){}


void interface::init(){
    int i, tam;
    cout << "Introduza nº de linhas e colunas" << endl;
    cin >> controlo.nv >> controlo.nh;
    tam = controlo.nv * controlo.nh;
    //cout << controlo.nv << "..." << controlo.nh << endl;
    for (i = 0; i < tam; i++){
        this->mapa.push_back (ilha());
    }
}
void interface::fill(){
    int flag = 0;
    float thres = ceil((controlo.nh*controlo.nv)/6);
    string zona;
    vector<ilha>::iterator ptr;
    for (ptr = this->mapa.begin(); ptr < mapa.end(); ptr++) {
        while(flag == 0){
        int z = rand() % 6;
        switch (z) {
            case 0:
                zona = "mnt ";
                controlo.mont++;
                if(controlo.mont <= thres)
                    flag = 1;
                break;
            case 1:
                zona = "dsr ";
                controlo.des++;
                if(controlo.des <= thres)
                    flag = 1;
                break;
            case 2:
                zona = "pas ";
                controlo.pas++;
                if(controlo.pas <= thres)
                    flag = 1;
                break;
            case 3:
                zona = "flr ";
                controlo.flor++;
                if(controlo.flor <= thres)
                    flag = 1;
                break;
            case 4:
                zona = "pnt ";
                controlo.pant++;
                if(controlo.pant <= thres)
                    flag = 1;
                break;
            case 5:
                zona = "znX ";
                controlo.zonX++;
                if(controlo.zonX <= thres)
                    flag = 1;
                break;
            default:
                break;
            }//switch
        }//while
        
        ptr->zona = zona;
        flag=0;
    }
    for (ptr = this->mapa.begin(); ptr < mapa.end(); ptr++){
        
        cout << ptr->zona << endl;
    }
    
}

void interface::coor(){
    int i=1;
    int j=1;
    vector<ilha>::iterator ptr2;
    ptr2 = this->mapa.begin();
        for(i=1;i<=controlo.nv;i++){ //coor vertical , linha
            for(j=1;j<=controlo.nh;j++){ // coor vertical , coluna
                ptr2->x=i;
                ptr2->y=j;
                ptr2++;
            }
        }
    for (ptr2 = this->mapa.begin(); ptr2 < mapa.end(); ptr2++){
        
        cout << "x: " <<ptr2->x << " y: " << ptr2->y  << endl;
    }
    
}


void interface::print(){
    int aux, cont=0;
    string straux;
    vector<ilha>::iterator ptr3;
    ptr3 = this->mapa.begin();
    aux = 4*controlo.nh + 2 + (controlo.nh-1);
    
    for(int j=0;j<controlo.nv;j++){
        for(int i=0;i<aux;i++){ //limite superior
            cout << "-";
        }
        cout << endl;
            cout << "|";
            for (int k=0+cont; k<controlo.nh+cont; k++) {
                //ptr3 = this->mapa.at(cont);
                cout << ptr3[k].zona << "|";
            }
        
            cout << endl;
    
            cout << "|";
            for (int k=0+cont; k<controlo.nh+cont; k++) {
                //ptr3 = this->mapa.at(cont);
                cout << ptr3[k].edif << "|";
            }
    
            cout << endl;
        
            cout << "|";
            for (int k=0+cont; k<controlo.nh+cont; k++) {
                //ptr3 = this->mapa.at(cont);
                for (int n=0; n<4; n++) {
                    cout << ptr3[k].trab[n];
                }
                cout << "|";
            }
    
            cout << endl;
    
            cout << "|";
            for (int k=0+cont; k<controlo.nh+cont; k++) {
                //ptr3 = this->mapa.at(cont);
                if(ptr3[k].num_trab < 10){
                    cout << ptr3[k].num_trab << "   " << "|";
                }
                if(ptr3[k].num_trab > 10){
                    cout << ptr3[k].num_trab << "  " << "|";
                    
                }
            }
        cout << endl;
        cont = cont + controlo.nh;
    }
    for(int i=0;i<aux;i++){ //limite inferior
        cout << "-";
        
    }
}

void interface::menu(){
    string fullcomm; //input completo
    string comm; //ordem
    string p1, p2, p3; //parametros
    string dummy;
    int jog;
    jogada jogada1;
    cout << endl << "Menu inicial:" << endl;
    do{
        cout << "Ordem: ";
        cin.clear();
        getline(cin >> ws, fullcomm);
        istringstream iss(fullcomm);
        iss >> comm >> p1 >> p2 >> p3;
        //cin >> comm >> p1 >> p2 >> p3;
        jog = jogada1.valida(comm);
        switch (jog) {
            case 1:
                jogada1.joga1(comm, p1, p2, p3, &mapa);
                break;
            case 2:
                jogada1.joga2(comm, p1, &mapa);
                break;
            case 3:
                jogada1.joga3(comm, p1, p2, &mapa);
                break;
            case 4:
                jogada1.joga4(comm, p1, p2, &mapa);
                break;
            case 5:
                jogada1.joga5(comm, p1, p2, p3, &mapa);
                break;
            case 6:
                jogada1.joga6(comm, p1, p2, &mapa);
                break;
            case 7:
                jogada1.joga7(comm, p1, &mapa);
                break;
            case 8:
                jogada1.joga8(comm, p1, p2, &mapa);
                break;
            case 9:
                jogada1.joga9(comm, &mapa);
                break;
            case 10:
                jogada1.joga10(comm, p1, &mapa);
                break;
            case 11:
                jogada1.joga11(comm, p1, &mapa);
                break;
            case 12:
                jogada1.joga12(comm, p1, &mapa);
                break;
            case 13:
                jogada1.joga13(comm, p1, &mapa);
                break;
            case 14:
                jogada1.joga14(comm, p1, &mapa);
                break;
            case 15:
                jogada1.joga15(comm, p1, p2, p3, &mapa);
                break;
            case 16:
                jogada1.joga16(comm, p1, &mapa);
                break;
                
                
            default:
                break;
        }
        print();
        cout << endl <<  "Continuar? [y/n]" << endl;
        cin >> dummy;
    } while (comm != "sair") ;
    
}
