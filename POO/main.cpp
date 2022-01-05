//
//  main.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//

#include <iostream>
#include "ilha.h"
#include "interface.h"
#include "player.h"
using namespace std;


int main() {
    interface anInterface;
    //ilha newilha;
    //anInterface.print_ilha();
    anInterface.init();
    anInterface.fill();
    anInterface.coor();
    anInterface.print();
    anInterface.menu();
    return 0;
}
