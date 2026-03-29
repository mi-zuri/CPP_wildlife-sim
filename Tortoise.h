//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_TORTOISE_H
#define PO_WILDLIFESIMULATOR_TORTOISE_H

#include "Animal.h"

class Tortoise : public Animal {
public:
    Tortoise(World& world) : Organism(world, 2, 1) {}
    void print(Terminal& terminal);
};


#endif //PO_WILDLIFESIMULATOR_TORTOISE_H
