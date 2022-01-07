//
//  jogada.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//
#include <string>
#include "jogada.h"
#include <stdio.h>
#include "ilha.h"
#include "interface.h"
#include <iostream>
#include <fstream>
#include <sstream>



using namespace std;


jogada::jogada(){
    this->cont_id = 0;
}

jogada::~jogada(){

}


void jogada::joga1(string comm, string p1, string p2, string p3, vector<ilha> *arr){
    string play;
    int x = stoi(p2);
    int y = stoi(p3);
        if(p1 == "minaf"){
            play = "MnF ";
        }
        if(p1 == "minc"){
            play = "MnC ";
        }
        if(p1 == "central"){
            play = "elec ";
        }
        if(p1 == "bat"){
            play = "bat ";
        }
        if(p1 == "fund"){
            play = "fund ";
        }
        if(p1 == "edx"){
            play = "ext ";
        }
   
    
    
    vector<ilha>::iterator ptr;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if(ptr->x == x && ptr->y == y){
            if (ptr->edif != "    ") {
                cout << "Não é possivel construir nesta zona" << endl;
            }
            else
            ptr->edif = play;
        }
    }
    
}
void jogada::joga2(string comm, string p1, vector<ilha> *arr){
    string play, p2, p3;
    string path = "/Users/manueljuliao/desktop/poo/";
    string fullpath;
    fullpath = path + p1;
    vector<string> read;
    int p;
    ifstream ReadFile;
    
    //ReadFile.open(fullpath);
    ReadFile.open("text.txt", ios::in);
    if (ReadFile) {
        while (!ReadFile.eof())
            play.push_back(ReadFile.get());
      }
    //while (ReadFile >> play) {
    //  read.push_back(play);}
    //getline(ReadFile, play);
    ReadFile.close();
    //istringstream iss(play);
    //iss >> comm >> p1 >> p2 >> p3;
    
    p = valida(comm);
    
    switch (p) {
        case 1:
            joga1(comm, p1, p2, p3, arr);
            break;
        case 3:
            joga3(comm, p1, p2, arr);
            break;
        case 4:
            joga4(comm, p1, p2, arr);
            break;
        case 5:
            joga5(comm, p1, p2, p3, arr);
            break;
        case 6:
            joga6(comm, p1, p2, arr);
            break;
        case 7:
            joga7(comm, p1, arr);
            break;
        case 8:
            joga8(comm, p1, p2, arr);
            break;
        case 9:
            joga9(comm, arr);
            break;
        case 10:
            joga10(comm, p1, arr);
            break;
        case 11:
            joga11(comm, p1, arr);
            break;
        case 12:
            joga12(comm, p1, arr);
            break;
        case 13:
            joga13(comm, p1, arr);
            break;
        case 14:
            joga14(comm, p1, arr);
            break;
        case 15:
            joga15(comm, p1, p2, p3, arr);
            break;
        case 16:
            joga16(comm, p1, arr);
            break;
            
            
        default:
            break;
    }
    
    
    cout << "Jogada 2" << endl;
}

void jogada::joga3(string comm, string p1, string p2, vector<ilha> *arr){
    cout << "Jogada 3" << endl;

}
void jogada::joga4(string comm, string p1, string p2, vector<ilha> *arr){
    cout << "Jogada 4" << endl;

}
void jogada::joga5(string comm, string p1, string p2, string p3, vector<ilha> *arr){
    cout << "Jogada 5" << endl;
    
}
void jogada::joga6(string comm, string p1, string p2, vector<ilha> *arr){
    cout << "Jogada 6" << endl;

}
void jogada::joga7(string comm, string p1, vector<ilha> *arr){
    // oper | len | miner
    char play;
    if(p1 == "miner"){
        play = 'M';
    }
    
    vector<ilha>::iterator ptr;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if(ptr->zona == "pas "){
            for (int i=0; i<=sizeof(ptr->trab); i++) {
                if (ptr->trab[i] == ' ') {
                    ptr->trab[i] = play;
                    ptr->num_trab++;
                    break;
                }
                
            }
            break;
        }
    
    }
    cont_id++;
    //cout << "Jogada 7" << endl;

}
void jogada::joga8(string comm, string p1, string p2, vector<ilha> *arr){
    //interface anInterface;
    vector<ilha>::iterator ptr;
    
    if(p1.empty() || p2.empty()){
        return;
    }
    else{
        int x = stoi(p1);
        int y = stoi(p2);
        for (ptr = arr->begin(); ptr < arr->end(); ptr++){
            if(ptr->x == x && ptr->y == y){
                cout << "Zona: " << ptr->zona << endl;
                cout << "Edificio: " << ptr->edif << endl;
                cout << "Trabalhadores: ";
                for (int n=0; n<sizeof(ptr->trab); n++) {
                    if (ptr->trab[n] == ' ') {
                        break;
                    }
                    cout << " " << ptr->trab[n];
                }
                cout << endl;
                cout << "Nº de trabalhadores: " << ptr->num_trab;
                break;
            }
        }
    }
    
    
    //cout << "Jogada 8" << endl;

}
void jogada::joga9(string comm, vector<ilha> *arr){
    cout << "Jogada 9" << endl;

}
void jogada::joga10(string comm, string p1, vector<ilha> *arr){
    cout << "Jogada 10" << endl;

}
void jogada::joga11(string comm, string p1, vector<ilha> *arr){
    cout << "Jogada 11" << endl;
}
void jogada::joga12(string comm, string p1, vector<ilha> *arr){
    cout << "Jogada 12" << endl;

}
void jogada::joga13(string comm, string p1, vector<ilha> *arr){
    cout << "Jogada 13" << endl;

}
void jogada::joga14(string comm, string p1, vector<ilha> *arr){
    cout << "Jogada 14" << endl;

}
void jogada::joga15(string comm, string p1, string p2, string p3, vector<ilha> *arr){
    cout << "Jogada 15" << endl;

}
void jogada::joga16(string comm, string p1, vector<ilha> *arr){
    cout << "Jogada 16" << endl;

}


int jogada::valida(string comm){
    int jog=0;
    if(comm == "const"){
        jog = 1;
        return jog;
    }
    if(comm == "exec"){
        jog = 2;
        return jog;
    }
    if(comm == "liga"){
        jog = 3;
        return jog;
    }
    if(comm == "des"){
        jog = 4;
        return jog;
    }
    if(comm == "move"){
        jog = 5;
        return jog;
    }
    if(comm == "vende"){
        jog = 6;
        return jog;
    }
    if(comm == "cont"){
        jog = 7;
        return jog;
    }
    if(comm == "list"){
        jog = 8;
        return jog;
    }
    if(comm == "next"){
        jog = 9;
        return jog;
    }
    if(comm == "save"){
        jog = 10;
        return jog;
    }
    if(comm == "load"){
        jog = 11;
        return jog;
    }
    if(comm == "apaga"){
        jog = 12;
        return jog;
    }
    if(comm == "config"){
        jog = 13;
        return jog;
    }
    if(comm == "debcash"){
        jog = 14;
        return jog;
    }
    if(comm == "debed"){
        jog = 15;
        return jog;
    }
    if(comm == "debkill"){
        jog = 16;
        return jog;
    }
    else
        return 0;
}
