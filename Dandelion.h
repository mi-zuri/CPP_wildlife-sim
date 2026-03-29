//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_DANDELION_H
#define PO_WILDLIFESIMULATOR_DANDELION_H

#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(World& world) : Organism(world) {};
    void print(Terminal &terminal);
};


#endif //PO_WILDLIFESIMULATOR_DANDELION_H
