//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_ANTELOPE_H
#define PO_WILDLIFESIMULATOR_ANTELOPE_H

#include "Animal.h"

class Antelope : public Animal {
public:
    Antelope(World& world) : Organism(world, 4, 4) {}
    void print(Terminal& terminal);
};


#endif //PO_WILDLIFESIMULATOR_ANTELOPE_H
