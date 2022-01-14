//
// Created by Manuel Julião on 09/01/2022.
//

#include "Worker.h"
#include <string>
#include <iostream>


Worker::Worker() {

}


miner::miner(int n, int d, int x, int y) : Worker() {
    this->x = x;
    this->y = y;
    this->name = "miner";
    this->id= to_string(n) + "." + to_string(d);
    this->perc = 0.15;
    this->c='M';
    //cout << this->name << " " << this->id << " " << this->perc << endl;
}

operario::operario(int n, int d, int x, int y) : Worker() {
    this->x = x;
    this->y = y;
    this->name = "oper";
    this->id= to_string(n) + "." + to_string(d);
    this->perc = 0.05;
    this->c='O';


}

lenhador::lenhador(int n, int d, int x, int y) : Worker() {
    this->x = x;
    this->y = y;
    this->name = "len";
    this->id= to_string(n) + "." + to_string(d);
    this->perc = 0;
    this->c='L';


}

Worker::~Worker(){

}

miner::~miner(){

}

operario::~operario(){

}

lenhador::~lenhador(){

}
