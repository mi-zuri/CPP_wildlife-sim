//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_GUARANA_H
#define PO_WILDLIFESIMULATOR_GUARANA_H

#include "Plant.h"

class Guarana : public Plant {
public:
    Guarana(World& world) : Organism(world) {};
    void print(Terminal &terminal);
};


#endif //PO_WILDLIFESIMULATOR_GUARANA_H
