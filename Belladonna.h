//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_BELLADONNA_H
#define PO_WILDLIFESIMULATOR_BELLADONNA_H

#include "Plant.h"

class Belladonna : public Plant {
public:
    Belladonna(World& world) : Organism(world, 99) {}
    void print(Terminal &terminal) {
        terminal.printCC('b', DARK_BLUE);
    }
};


#endif //PO_WILDLIFESIMULATOR_BELLADONNA_H
