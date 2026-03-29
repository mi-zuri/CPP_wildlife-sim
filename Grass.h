//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_GRASS_H
#define PO_WILDLIFESIMULATOR_GRASS_H

#include "Plant.h"

class Grass : public Plant {
public:
    Grass(World& world) : Organism(world) {};
    void print(Terminal &terminal) {
        terminal.printCC('w', VIBRANT_GREEN);
    };
};


#endif //PO_WILDLIFESIMULATOR_GRASS_H
