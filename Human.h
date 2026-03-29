//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_HUMAN_H
#define PO_WILDLIFESIMULATOR_HUMAN_H

#include "Animal.h"



class Human : public Animal {
    int range = 1;
public:
    Human(World& world) : Organism(world, 5, 4) {}
    void action(int move);  // sterowanie
    void collision();
    void print(Terminal& terminal);
};


#endif //PO_WILDLIFESIMULATOR_HUMAN_H
