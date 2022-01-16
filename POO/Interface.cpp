//
//  interface.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//


#include "Interface.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <math.h>
#include "Worker.h"
#include "Jogada.h"
#include <iostream>
#include <sstream>
#include "Player.h"

using namespace std;


Interface::Interface(){}

Interface::~Interface(){}


void Interface::init(){ //inicializa ilha [vetor] com o tamanho indicado pelo utilizador
    int i, tam;
    cout << "Introduza numero de linhas e colunas" << endl;
    cin >> controlo.nv >> controlo.nh;
    tam = controlo.nv * controlo.nh;
    //cout << controlo.nv << "..." << controlo.nh << endl;
    for (i = 0; i < tam; i++){
        this->mapa.push_back (Ilha());
    }
}
void Interface::fill(){ //fill vetor com tipos de zona equilibrados
    int flag = 0;
    int i, tam;
    cout << "Introduza numero de linhas e colunas" << endl;
    cin >> controlo.nv >> controlo.nh;
    tam = controlo.nv * controlo.nh;
    float thres = ceil((controlo.nh*controlo.nv)/6);
    string zona;
    vector<Ilha>::iterator ptr;
    //for (ptr = this->mapa.begin(); ptr < mapa.end(); ptr++) {
    for (i = 0; i < tam; i++){
        while(flag == 0){
            int z = rand() % 6;
            switch (z) {
                case 0:
                    if(controlo.mont > thres){
                        flag = 1;
                        break;
                    }
                    else{
                        mapa.push_back (montanha());
                        zona = "mnt ";
                        controlo.mont++;
                    }

                case 1:
                    if(controlo.des > thres){
                        flag = 1;
                        break;
                    }
                    else{
                        mapa.push_back (deserto());
                        zona = "dsr ";
                        controlo.des++;
                    }
                case 2:
                    if(controlo.pas > thres){
                        flag = 1;
                        break;
                    }
                    else{
                        mapa.push_back (pastagem());
                        zona = "pas ";
                        controlo.pas++;
                    }

                case 3:
                    if(controlo.flor > thres){
                        flag = 1;
                        break;
                    }
                    else{
                        mapa.push_back (floresta());
                        zona = "flr ";
                        controlo.flor++;
                    }

                case 4:
                    if(controlo.pant > thres){
                        flag = 1;
                        break;
                    }
                    else{
                        mapa.push_back (pantano());
                        zona = "pnt ";
                        controlo.pant++;
                    }

                case 5:
                    if(controlo.zonX > thres){
                        flag = 1;
                        break;
                    }
                    else{
                        mapa.push_back (zonax());
                        zona = "znX ";
                        controlo.zonX++;
                    }

                default:
                    break;
                }//switch
        }//while
        

        flag=0;
    }
//    for (ptr = this->mapa.begin(); ptr < mapa.end(); ptr++){
//
//        cout << ptr->zona << endl;
//    }
    
}

void Interface::coor(){ // fill vetor com coordenadas (x,y)
    int i=1;
    int j=1;
    vector<Ilha>::iterator ptr2;
    ptr2 = this->mapa.begin();
        for(i=1;i<=controlo.nv;i++){ //coor vertical , linha
            for(j=1;j<=controlo.nh;j++){ // coor vertical , coluna
                ptr2->x=i;
                ptr2->y=j;
                ptr2++;
            }
        }
        // funcao teste: imprime as coordenadas de cada posicao do vetor
//     for (ptr2 = this->mapa.begin(); ptr2 < mapa.end(); ptr2++){
//
//        cout << "x: " <<ptr2->x << " y: " << ptr2->y  << endl;
//    }
    
}


void Interface::print(){  // imprime tabuleiro
    int aux, cont=0;
    string straux;
    vector<Ilha>::iterator ptr3;
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

void Interface::menu(){
    string fullcomm; //input completo
    string comm; //ordem
    string p1, p2, p3; //parametros
    string dummy; //condicao de continuacao
    int jog; // switch
    int flag = 0;
    Jogada jogada1;
    Player player1;
    cout << endl << "Menu inicial:" << endl;
    do{

//        if(day > 1){
//            dawn(&mapa, &player1); // amanhecer
//        }
        do{
            comm.clear();
            p1.clear();
            p2.clear();
            p3.clear();
            dawn(&mapa, &player1, &workers, &buildings);
            cout << "Ordem: ";
            cin.clear();
            getline(cin >> ws, fullcomm);
            istringstream iss(fullcomm);
            iss >> comm >> p1 >> p2 >> p3;
            //cin >> comm >> p1 >> p2 >> p3;
            jog = jogada1.valida(comm);
            if(jog == 0){
                cout << "Comando incorreto" << endl;
                continue;
            }

            switch (jog) {
                case 1:
                    flag=jogada1.joga1(comm, p1, p2, p3, &mapa, &buildings, &controlo, &player1);
                    break;
                case 2:
                    jogada1.joga2(comm, p1, &mapa, &workers, day, &buildings, &controlo, &player1);
                    break;
                case 3:
                    flag=jogada1.joga3(comm, p1, p2, &mapa, &buildings);
                    break;
                case 4:
                    jogada1.joga4(comm, p1, p2, &mapa, &buildings);
                    break;
                case 5:
                    flag=jogada1.joga5(comm, p1, p2, p3, &mapa, &workers, &buildings);
                    break;
                case 6:
                    jogada1.joga6(comm, p1, p2, &mapa, &controlo, &player1, &buildings);
                    break;
                case 7:
                    flag= jogada1.joga7(comm, p1, &mapa, &workers, day, &buildings, &player1);
                    break;
                case 8:
                    flag= jogada1.joga8(comm, p1, p2, &mapa, &controlo, &player1, &buildings);
                    break;
//                case 9:
//                    jogada1.joga9(comm, &mapa);
//                    break;
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
                    jogada1.joga14(comm, p1, &player1);
                    break;
                case 15:
                    jogada1.joga15(comm, p1, p2, p3, &mapa, &buildings, &controlo);
                    break;
                case 16:
                    jogada1.joga16(comm, p1, &mapa, &workers, &buildings);
                    break;


                default:
                    break;
            }
            if(flag == 1){
                continue;
            }
            //player1.calcprod(&mapa, &player1);
            if(comm == "sair")
                exit(0);
        }while(comm != "next");

        print();
        night(&mapa, &player1, &workers,&buildings);
        day++;
        cout << endl <<  "Continuar? [y/n]" << endl;
        cin >> dummy;
        if(dummy == "n"){
            break;
        }
    }while (comm != "sair");

}

void Interface::night(vector<Ilha> *mapa, Player *player1, vector<Worker> *workers, vector<Building> *buildings) {
    vector<Worker>::iterator ptr;
    player1->calcprod(mapa, player1, buildings);
    player1->prod(player1, buildings);
    cout << endl << "Dia: " << day << endl << "Dinheiro: " <<player1->money << endl << "Ferro: " << player1->iron << endl << "Barras de aco: " << player1->steel << endl << "Carvao: " << player1->coal << endl << "Madeira: " << player1->wood << endl << "Vigas de madeira: " << player1->woodbeams << endl << "Eletricidade: " << player1->energy << endl;
    cout << endl << player1->ntrab << " Trabalhadores" << endl;
    cout << "Tipo" << "\tNome" << "\tID"<< endl;
    for(ptr = workers->begin(); ptr < workers->end(); ptr++){
        cout << ptr->c << "\t" << ptr->name << "\t" << ptr->id << endl;
    }
    //amanhecer -> update recursos etc


}

void Interface::dawn(vector<Ilha> *mapa, Player *player1, vector<Worker> *workers, vector<Building> *buildings){
    vector<Ilha>::iterator ptr;
    vector<Building>::iterator ptr2;

    for(ptr = mapa->begin(); ptr < mapa->end(); ptr++){
        if(ptr->zona == "flr "){
            if(ptr->trees < ptr->maxtree){
                ptr->trees += 1;
            }
        }
        if(ptr->zona == "mnt "){
            ptr->storage += ptr->prod;
        }
        if(ptr->zona == "pnt "){
            if(ptr->edif != "    "){
                ptr->maxday--;
            }
            if(ptr->maxday == 8){
                ptr->edif = "    ";
                ptr->maxday = 10;
                for (ptr2 = buildings->begin(); ptr2 < buildings->end(); ptr2++){
                    if (ptr2->x == ptr->x && ptr2->y == ptr->y){
                        buildings->erase(ptr2);
                    }
                }
            }
        }
    }

}





