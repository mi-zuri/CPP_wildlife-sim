//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_SHEEP_H
#define PO_WILDLIFESIMULATOR_SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(World& world) : Organism(world, 4, 4) {}
    void print(Terminal& terminal) {
        terminal.printCC('S', DIRTY_WHITE);
    };
};


#endif //PO_WILDLIFESIMULATOR_SHEEP_H
