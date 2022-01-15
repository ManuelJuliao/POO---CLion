//
//  jogada.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//
#include <string>
#include "Jogada.h"
#include <cstdio>
#include "Ilha.h"
#include "Interface.h"
#include "Building.h"
#include "Worker.h"
#include <iostream>

#include <fstream>
#include <sstream>



using namespace std;


Jogada::Jogada(){
    this->cont_id = 1;
}

Jogada::~Jogada(){

}


int Jogada::joga1(string comm, string p1, string p2, string p3, vector<Ilha> *arr, vector<Building> *build, struct controlo *controlo, Player *player1){
    string play;
    int cost;
    int flag=0, aux;
    int x = stoi(p2);
    int y = stoi(p3);
    string dummy;

    vector<Ilha>::iterator ptr;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if(ptr->x == x && ptr->y == y) {
            if (ptr->edif != "    ") {
                flag=1;
                cout << "Nao e possivel construir nesta zona" << endl;
            }
            else{
                break;
            }
        }
    }


    if(p1 == "minaf"){
        if(player1->woodbeams < 10 && player1->money < 100){
            cout << "Nao tem recurso suficientes (faltam " << 10-player1->woodbeams << " vigas de madeira)" << endl;
            flag=1;
        }
        else if(player1->woodbeams < 10){
            aux = (10-player1->woodbeams)*10;
            cout << "Sem vigas suficientes, gastar " << aux << "$? (y/n)" << endl;
            cin >> dummy;
            if(dummy == "y"){
                cost = aux;
                player1->money -= aux;
            }else{
                flag=1;
            }
        }
        if(flag == 0){
            play = "MnF ";
            build->push_back(minaf(x,y, ptr->trab, cost)); // add edif to array
            controlo->minaf++;
        }

    }
    else if(p1 == "minc"){
        if(player1->woodbeams < 10 && player1->money < 100){
            cout << "Recursos insuficientes (faltam " << 10-player1->woodbeams << " vigas de madeira)" << endl;
            flag=1;
        }
        else if(player1->woodbeams < 10){
            aux = (10-player1->woodbeams)*10;
            cout << "Sem vigas suficientes, gastar " << aux << "$? (y/n)" << endl;
            cin >> dummy;
            if(dummy == "y"){
                cost = aux;
                player1->money -= aux;
            }else{
                flag=1;
            }
        }
        if(flag == 0){
            play = "MnC ";
            build->push_back(minc(x,y, ptr->trab,cost)); // add edif to array
            controlo->minc++;
        }

    }
    else if(p1 == "central"){
        aux = 15-player1->money;
        if(player1->money < 15){
            cout << "Recursos insuficientes (faltam " << aux << "$)" << endl;
            flag = 1;
        }
        if(flag == 0){
            cost = 15;
            play = "elec";
            build->push_back(central(x,y, ptr->trab,cost)); // add edif to array
            controlo->central++;
        }

    }
    else if(p1 == "bat"){
        aux = 10-player1->money;
        int aux2 = 10-player1->woodbeams;
        if(player1->money < 10 && player1->woodbeams < 10){
            cout << "Recursos insuficientes (faltam " << aux << "$ e " << aux2 << " vigas)" << endl;
            flag = 1;
        }else if(player1->money < 10 && player1->woodbeams > 10){
            cout << "Recursos insuficientes (faltam " << aux << "$)" << endl;
            flag = 1;
        }else if(player1->money > 10 && player1->woodbeams < 10){
            cout << "Recursos insuficientes (faltam " << aux2 << " vigas)" << endl;
            flag = 1;
        }
        if(flag == 0){
            cost = 10;
            play = "bat ";
            build->push_back(bat(x,y, ptr->trab,cost)); // add edif to array
            controlo->bat++;
        }
    }

    else if(p1 == "fund"){
        aux = 10-player1->money;
        if(player1->money < 10){
            cout << "Recursos insuficientes (faltam " << aux << " $)" << endl;
            flag=1;
        }
        if(flag == 0){
            cost = 10;
            play = "fund";
            build->push_back(fund(x,y, ptr->trab,cost)); // add edif to array
            controlo->fund++;
        }

    }
    else if(p1 == "edx"){
        if(player1->wood < 20 && player1->money < 100){
            cout << "Nao tem recurso suficientes (faltam " << 10-player1->wood << " unidades de madeira)" << endl;
            flag=1;
        }
        else if(player1->wood < 10){
            aux = (20-player1->wood)*5;
            cout << "Sem vigas suficientes, gastar " << aux << "$? (y/n)" << endl;
            cin >> dummy;
            if(dummy == "y"){
                cost = aux;
                player1->money -= aux;
            }else{
                flag=1;
            }
        }
        if(flag == 0){
            play = "ext ";
            build->push_back(edx(x,y, ptr->trab,cost)); // add edif to array
            controlo->edx++;
        }

    }
    else{
        flag=1;
        cout << "Comando incorreto" << endl;
    }

    if(flag == 0){
        ptr->edif = play;
    }
    //vector<ilha>::iterator ptr2;




    return flag;
    
}
void Jogada::joga2(string comm, string p1, vector<Ilha> *arr, vector<Worker> *work, int dia, vector<Building> *build, struct controlo *controlo, Player *player1){
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
            joga1(comm, p1, p2, p3, arr, build, controlo, player1);
            break;
        case 3:
            joga3(comm, p1, p2, arr, build);
            break;
        case 4:
            joga4(comm, p1, p2, arr, build);
            break;
        case 5:
            joga5(comm, p1, p2, p3, arr, work, build);
            break;
        case 6:
            joga6(comm, p1, p2, arr,controlo, player1,build);
            break;
        case 7:
            joga7(comm, p1, arr, work,dia, build, player1);
            break;
        case 8:
            joga8(comm, p1, p2, arr, controlo, player1,build);
            break;
//        case 9:
//            joga9(comm, arr);
//            break;
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
            joga14(comm, p1, player1);
            break;
        case 15:
            joga15(comm, p1, p2, p3, arr, build, controlo);
            break;
        case 16:
            joga16(comm, p1, arr, work, build);
            break;
            
            
        default:
            break;
    }
    
    
    cout << "Jogada 2" << endl;
}

int Jogada::joga3(string comm, string p1, string p2, vector<Ilha> *arr, vector<Building> *build){
    int x = stoi(p1);
    int y = stoi(p2);
    int flag=0;
    vector<Ilha>::iterator ptr;
    vector<Building>::iterator ptr2;

    for(ptr2 = build->begin(); ptr2 < build->end(); ptr2++){
        if(ptr2->x == x && ptr2->y == y){
            if(ptr2->name == "MnF " || ptr2->name == "MnC ") {
                for (int i = 0; i < sizeof(ptr2->trab); i++) {
                    if (ptr2->trab[i] == 'M') {
                        ptr2->power = 1;
                        break;
                    }
                }
                if(ptr2->power == 0) {
                    flag = 1;
                    cout << "Requer trabalhador" << endl;
                }
            }
            else{
                ptr2->power = 1;
            }
        }
        else{
            flag = 1;
            cout << "Nao existe edificio" << endl;
            break;
        }
    }

    return flag;

    // cout << "Jogada 3" << endl;

}


int Jogada::joga4(string comm, string p1, string p2, vector<Ilha> *arr,  vector<Building> *build){

    int x = stoi(p1);
    int y = stoi(p2);
    int flag=0;
    vector<Ilha>::iterator ptr;
    vector<Building>::iterator ptr2;

    for(ptr2 = build->begin(); ptr2 < build->end(); ptr2++){
        if(ptr2->x == x && ptr2->y == y){
            if (ptr2->name == "    "){
                cout << "Nao existe edificio" << endl;
                flag=1;
                break;
            }
            else{
                ptr2->power = 0;

            }
        }
    }


    return flag;

    //cout << "Jogada 4" << endl;

}
int Jogada::joga5(string comm, string p1, string p2, string p3, vector<Ilha> *arr, vector<Worker> *work, vector<Building> *build){
    //move -> id
    int i,aux;
    int flag=0;
    string id = p1;
    int x = stoi(p2);
    int y = stoi(p3);
    vector<Worker>::iterator ptr;
    vector<Ilha>::iterator ptr2;
    for(ptr = work->begin(); ptr < work->end(); ptr++){
        if(ptr->id == id){
            for(ptr2 = arr->begin(); ptr2 < arr->end(); ptr2++){
                if(ptr2->x == ptr->x && ptr2->y == ptr->y){
                    for(i=0; i<sizeof(ptr2->trab);i++){ // apagar do array de trabalhadores da celula
                        if(ptr2->trab[i] == ptr->c){
                            ptr2->trab[i]=' ';
                            aux = i;
                            break;
                        }
                    }
                    for(int j=aux;j<sizeof(ptr2->trab);j++){    // ajustar valores imprimidos
                        ptr2->trab[j] = ptr2->trab[j+1];
                    }
                    ptr2->num_trab--;
                }
            }
            ptr->x = x;
            ptr->y = y;
            flag=0;
            break;
        }
        else{
            flag=1;
        }


    }
    if(flag==0){
        for(ptr2 = arr->begin(); ptr2 < arr->end(); ptr2++){ // reescrever nas novas coordenadas
            if(ptr2->x == x && ptr2->y == y){
                for (int i=0; i<=sizeof(ptr2->trab); i++) {
                    if (ptr2->trab[i] == ' ') {
                        ptr2->trab[i] = ptr->c;
                        ptr2->num_trab++;
                        break;
                    }
                }
            }
        }

        vector<Building>::iterator ptr3;

        for (ptr3 = build->begin(); ptr3 < build->end(); ptr3++){ // preenche no edificio caso exista
            if(ptr3->x == x && ptr3->y == y){
                for(int i=0; i<50; i++){
                    ptr3->trab[i] = ptr2->trab[i];
                }
                break;
            }

        }
    }
    else{
        cout << "Trabalhador nao existe" << endl;
    }

    return flag;

    //cout << ptr->c << endl;
    //cout << "Jogada 5" << endl;
    
}
int Jogada::joga6(string comm, string p1, string p2, vector<Ilha> *arr, struct controlo *controlo, Player *player1,vector<Building> *build){
    int flag=0;
    vector<Ilha>::iterator ptr;
    vector<Building>::iterator ptr2;
    //se p1 for numero, vende edificio
    if (isNumber(p1)){
        int x = stoi(p1);
        int y = stoi(p2);
        for (ptr = arr->begin(); ptr < arr->end(); ptr++){
            if (ptr->x == x && ptr->y == y){
                ptr->edif = '    ';
            }
        }
        for (ptr2 = build->begin(); ptr2 < build->end(); ptr2++){
            if (ptr2->x == x && ptr2->y == y){
                // add resource to player
                build->erase(ptr2);
            }
        }
    }
    //se p1 for palavra, vende recurso
    else{
        int qt = stoi(p2);
        if(p1 == "ferro"){
            if(player1->iron < qt){
                cout << "Não tem ferro suficiente" << endl;
                flag =1;
            }else{
                player1->iron -= qt;
                player1->money += qt;
            }
        }
        else if(p1 == "aco"){
            if(player1->steel < qt){
                cout << "Não tem aço suficiente" << endl;
                flag =1;
            }else{
                player1->steel -= qt;
                player1->money += qt*2;
            }
        }
        else if(p1 == "carvao"){
            if(player1->coal < qt){
                cout << "Não tem carvao suficiente" << endl;
                flag =1;
            }else{
                player1->coal -= qt;
                player1->money += qt;
            }
        }
        else if(p1 == "mad"){
            if(player1->wood < qt){
                cout << "Não tem madeira suficiente" << endl;
                flag =1;
            }else{
                player1->wood -= qt;
                player1->money += qt;
            }
        }
        else if(p1 == "viga"){
            if(player1->woodbeams == 0){
                cout << "Não tem vigas suficiente" << endl;
                flag =1;
            }else{
                player1->woodbeams -= qt;
                player1->money += qt*2;
            }
        }
        else if(p1 == "eletr"){
            if(player1->energy < qt){
                cout << "Não tem energia suficiente" << endl;
                flag =1;
            }else{
                player1->energy -= qt;
                player1->money += qt*(1.5);
            }
        }

    }

    //cout << "Jogada 6" << endl;

}
int Jogada::joga7(string comm, string p1, vector<Ilha> *arr, vector<Worker> *work, int dia, vector<Building> *build, Player *player1){
    // oper | len | miner
    char play;
    int flag=0;
    vector<Ilha>::iterator ptr;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if(ptr->zona == "pas "){
            break; // ptr -> pastagem
        }
    }

    if(p1 == "miner"){
        if(player1->money<10){
            cout << "Nao tem dinheiro suficiente (faltam " << 10-player1->money << "$)" << endl;
            flag=1;
        }else{
            play = 'M';
            work->push_back (miner(cont_id,dia, ptr->x, ptr->y)); // instance worker (miner)
            player1->money -= 10;
        }
    }
    else if(p1 == "oper"){
        if(player1->money<15){
            cout << "Nao tem dinheiro suficiente (faltam " << 15-player1->money << "$)" << endl;
            flag=1;
        }else{
            play = 'O';
            work->push_back (operario(cont_id,dia, ptr->x, ptr->y));
            player1->money -= 15;
        }

        }
    else if(p1 == "len"){
        if(player1->money<20){
            cout << "Nao tem dinheiro suficiente (faltam " << 20-player1->money << "$)" << endl;
            flag=1;
        }else{
            play = 'L';
            work->push_back (lenhador(cont_id,dia, ptr->x, ptr->y));
            player1->money -= 20;
        }


    }
    else {
        cout << "Trabalhador invalido!" << endl;
        flag = 1;
    }
    if(flag==0){
        for (int i=0; i<=sizeof(ptr->trab); i++) {
            if (ptr->trab[i] == ' ') {
                ptr->trab[i] = play;
                ptr->num_trab++;
                break;
            }
        }// preenche no tabuleiro

        vector<Building>::iterator ptr2;

        for (ptr2 = build->begin(); ptr2 < build->end(); ptr2++){ // preenche no edificio caso exista
            if(ptr2->x == ptr->x && ptr2->y == ptr->y){
                for(int i=0; i<50; i++){
                    ptr2->trab[i] = ptr->trab[i];
                }
                break;
            }

        }
        cont_id++;
    }

    return flag;
    //cout << "Jogada 7" << endl;

}
int Jogada::joga8(string comm, string p1, string p2, vector<Ilha> *arr, struct controlo *controlo, Player *player1,vector<Building> *build){
    //interface anInterface;
    vector<Ilha>::iterator ptr;
    int flag=0;
    string onoff;
    
    if(p1.empty()){
        cout << "Dados de jogo" << endl;
        cout <<  "Minas de ferro: " << controlo->minaf << "\tFerro: " << player1->iron << "\tProducao: " << player1->ironprod << endl;
        cout <<  "Minas de carvao: " << controlo->minc << "\tCarvao: " << player1->coal << "\tProducao: " << player1->coalprod << endl;
        cout <<  "Centrais eletricas: " << controlo->central << "\tEnergia: " << player1->energy  << endl;
        cout <<  "Baterias: " << controlo->bat << "\tEnergia: " << player1->iron <<  endl;
        cout <<  "Fundicoes: " << controlo->fund << "\tAco: " << player1->iron << "\tProducao: " << player1->ironprod << endl;
        cout <<  "Edificios X (Armazem): " << controlo->edx << endl;

        flag=1;
        cout << "Prima ENTER para voltar..." << endl;
        cin.get();
    }
    else{
        int x = stoi(p1);
        int y = stoi(p2);
        vector<Building>::iterator ptr2;
        for(ptr2 = build->begin(); ptr2 < build->end(); ptr2++){
            if(ptr2->x == x && ptr2->y == y){
                break;
            }
        }
        if(ptr2->power==1){
            onoff = "On";
        }else{
            onoff = "Off";
        }
        for (ptr = arr->begin(); ptr < arr->end(); ptr++){
            if(ptr->x == x && ptr->y == y){
                cout << "Zona: " << ptr->zona << endl;
                cout << "Edificio: " << ptr->edif << "\t" << onoff << endl;
                cout << "Trabalhadores: ";
                for (int n=0; n<sizeof(ptr->trab); n++) {
                    if (ptr->trab[n] == ' ') {
                        break;
                    }
                    cout << " " << ptr->trab[n];
                }
                cout << endl;
                cout << "Numero de trabalhadores: " << ptr->num_trab << endl;
                cout << "Prima ENTER para voltar..." << endl;
                cin.get();
                flag=1;
                break;
            }
        }
    }
    return flag;
    
    
    //cout << "Jogada 8" << endl;

}
//void Jogada::joga9(string comm, vector<Ilha> *arr){
//    cout << "Jogada 9" << endl;
//
//}
void Jogada::joga10(string comm, string p1, vector<Ilha> *arr){
    cout << "Jogada 10" << endl;

}
void Jogada::joga11(string comm, string p1, vector<Ilha> *arr){
    cout << "Jogada 11" << endl;
}
void Jogada::joga12(string comm, string p1, vector<Ilha> *arr){
    cout << "Jogada 12" << endl;

}
void Jogada::joga13(string comm, string p1, vector<Ilha> *arr){
    cout << "Jogada 13" << endl;

}
void Jogada::joga14(string comm, string p1, Player *player1){
    int value = stoi(p1);
    player1->money += value;
    cout << player1->money << endl;

    //cout << "Jogada 14" << endl;

}
void Jogada::joga15(string comm, string p1, string p2, string p3, vector<Ilha> *arr, vector<Building> *build,struct controlo *controlo ){
    string play;
    int cost=0;
    int flag=0, aux;
    int x = stoi(p2);
    int y = stoi(p3);
    string dummy;

    vector<Ilha>::iterator ptr;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if(ptr->x == x && ptr->y == y) {
            break;
        }
    }

    if(p1 == "minaf"){
        play = "MnF ";
        build->push_back(minaf(x,y, ptr->trab, cost)); // add edif to array
        controlo->minaf++;

    }
    else if(p1 == "minc"){
        play = "MnC ";
        build->push_back(minc(x,y, ptr->trab, cost)); // add edif to array
        controlo->minc++;
    }
    else if(p1 == "central"){
        play = "elec";
        build->push_back(central(x,y, ptr->trab, cost)); // add edif to array
        controlo->central++;
    }
    else if(p1 == "bat"){
        play = "bat ";
        build->push_back(bat(x,y, ptr->trab, cost)); // add edif to array
        controlo->bat++;
    }
    else if(p1 == "fund"){
        play = "fund";
        build->push_back(fund(x,y, ptr->trab, cost)); // add edif to array
        controlo->fund++;
    }
    else if(p1 == "edx"){
        play = "ext ";
        build->push_back(edx(x,y, ptr->trab, cost)); // add edif to array
        controlo->edx++;
    }
    else{
        flag=1;
        cout << "Edificio nao existe" << endl;
    }


    //vector<ilha>::iterator ptr2;
    for (ptr = arr->begin(); ptr < arr->end(); ptr++){
        if(ptr->x == x && ptr->y == y){
            if (ptr->edif != "    ") {
                flag=1;
                cout << "Nao e possivel construir nesta zona" << endl;
            }
            else
                ptr->edif = play;
        }
    }




    //cout << "Jogada 15" << endl;

}
void Jogada::joga16(string comm, string p1, vector<Ilha> *arr, vector<Worker> *work, vector<Building> *build){
    int i, x,y;
    string id = p1;
    vector<Worker>::iterator ptr;
    vector<Ilha>::iterator ptr2;
    for(ptr = work->begin(); ptr < work->end(); ptr++){
        if(ptr->id == id){
            x= ptr->x; y= ptr->y;
            work->erase(ptr);
            for(ptr2 = arr->begin(); ptr2 < arr->end(); ptr2++){
                if(ptr2->x == ptr->x && ptr2->y == ptr->y){
                    for(i=0; i<sizeof(ptr2->trab);i++){ // apagar do array de trabalhadores da celula
                        if(ptr2->trab[i] = ptr->c){
                            ptr2->trab[i]=' ';
                            break;
                        }
                    }
                    for(i;i<sizeof(ptr2->trab);i++){    // ajustar valores imprimidos
                        ptr2->trab[i] = ptr2->trab[i+1];
                    }
                    ptr2->num_trab--;
                }
            }

            break;
        }
    }

    vector<Building>::iterator ptr3;

    for (ptr3 = build->begin(); ptr3 < build->end(); ptr3++){
        if(ptr3->x == x && ptr3->y == y){
            for(int i=0; i<50; i++){
                ptr3->trab[i] = ptr2->trab[i];
            }
            break;
        }

    }
    //cout << "Jogada 16" << endl;

}


int Jogada::valida(string comm){
    int jog=0;
    if(comm == "const"){
        jog = 1;
        return jog;
    }
    else if(comm == "exec"){
        jog = 2;
        return jog;
    }
    else if(comm == "liga"){
        jog = 3;
        return jog;
    }
    else if(comm == "des"){
        jog = 4;
        return jog;
    }
    else if(comm == "move"){
        jog = 5;
        return jog;
    }
    else if(comm == "vende"){
        jog = 6;
        return jog;
    }
    else if(comm == "cont"){
        jog = 7;
        return jog;
    }
    else if(comm == "list"){
        jog = 8;
        return jog;
    }
    else if(comm == "next"){
        jog = 9;
        return jog;
    }
    else if(comm == "save"){
        jog = 10;
        return jog;
    }
    else if(comm == "load"){
        jog = 11;
        return jog;
    }
    else if(comm == "apaga"){
        jog = 12;
        return jog;
    }
    else if(comm == "config"){
        jog = 13;
        return jog;
    }
    else if(comm == "debcash"){
        jog = 14;
        return jog;
    }
    else if(comm == "debed"){
        jog = 15;
        return jog;
    }
    else if(comm == "debkill"){
        jog = 16;
        return jog;
    }
    else if(comm == "sair"){
        jog = 17;
        return jog;
    }
    else
        return jog;
}


bool isNumber(string str)
{
    for (char c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}