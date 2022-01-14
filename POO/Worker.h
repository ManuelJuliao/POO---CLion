//
// Created by Manuel Julião on 09/01/2022.
//
#include <string>

#ifndef POO_WORKER_H
#define POO_WORKER_H


using namespace std;


class Worker {
    public:
    int x,y;
    string id;
    int n, d; // id e dia
    float perc; // probabilidade de se despedir
    string name;
    char c;

    Worker();
    ~Worker();


};

class miner : public Worker {

public:
    miner(int n, int d, int x, int y);

    ~miner();
};

class operario : public Worker {

public:
    operario(int n, int d, int x, int y);

    ~operario();
};

class lenhador : public Worker {

public:
    lenhador(int n, int d, int x, int y);

    ~lenhador();
};

#endif //POO_WORKER_H
