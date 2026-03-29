//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_WOLF_H
#define PO_WILDLIFESIMULATOR_WOLF_H

#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(World& world) : Organism(world, 9, 5) {}
    void print(Terminal& terminal) {
        terminal.printCC('W', DEVIOUS_GREY);
    };
};


#endif //PO_WILDLIFESIMULATOR_WOLF_H
