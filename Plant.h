//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_PLANT_H
#define PO_WILDLIFESIMULATOR_PLANT_H

#include "Organism.h"

class World;

class Plant: virtual public Organism {
public:
    void setPos(int y, int x);
    void action(); // szansa na rozsianie się obok
    void collision(Animal& attacker);
};


#endif //PO_WILDLIFESIMULATOR_PLANT_H
