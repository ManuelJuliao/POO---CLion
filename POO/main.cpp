//
//  main.cpp
//  POO
//
//  Created by Manuel Juliao on 22/11/2021.
//

#include <iostream>
#include "ilha.h"
#include "interface.h"
using namespace std;

float sum(float a, float b);
void introduceMe(string name, int age);
void celebrateBirthday(int* age2);

int main() {
    interface anInterface;
    //ilha newilha;
    //anInterface.print_ilha();
    anInterface.init();
    anInterface.fill();
    anInterface.coor();
    anInterface.print();
    anInterface.menu();
}
