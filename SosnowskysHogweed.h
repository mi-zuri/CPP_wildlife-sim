//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_SOSNOWSKYSHOGWEED_H
#define PO_WILDLIFESIMULATOR_SOSNOWSKYSHOGWEED_H

#include "Plant.h"

class SosnowskysHogweed : public Plant {
public:
    SosnowskysHogweed(World& world) : Organism(world, 10) {}
    void print(Terminal &terminal);
};


#endif //PO_WILDLIFESIMULATOR_SOSNOWSKYSHOGWEED_H
