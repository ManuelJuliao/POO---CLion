//
//  main.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//

#include <iostream>
#include "Ilha.h"
#include "Interface.h"
#include "Player.h"
using namespace std;


int main() {
    Interface anInterface;
    //ilha newilha;
    //anInterface.print_ilha();
    //anInterface.init();
    anInterface.fill();
    anInterface.coor();
    anInterface.print();
    anInterface.menu();
    return 0;
}
