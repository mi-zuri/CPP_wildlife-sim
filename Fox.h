//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_FOX_H
#define PO_WILDLIFESIMULATOR_FOX_H

#include "Animal.h"

class Fox : public Animal {
public:
    Fox(World& world) : Organism(world, 3, 7) {}
    void print(Terminal& terminal);
};


#endif //PO_WILDLIFESIMULATOR_FOX_H
