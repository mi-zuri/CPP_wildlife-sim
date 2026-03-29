//
// Created by Michał on 2023-04-23.
//

#include <iostream>

#ifndef PO_WILDLIFESIMULATOR_ORGANISM_H
#define PO_WILDLIFESIMULATOR_ORGANISM_H

#include "Terminal.h"
#include "RandomNumberGenerator.h"

class Animal;
class World;

class Organism {
protected:
    int strength;
    int initiative;
    struct Position {
        int y;
        int x;
    } position;

    Organism(World& world) : world(world), strength(0), initiative(0) {};
    Organism(World& world, int strength) : world(world), strength(strength), initiative(0) {}
    Organism(World& world, int strength, int initiative) : world(world), strength(strength), initiative(initiative) {}
public:
    World& world;
    int getStrength() const {
        return strength;
    }
    virtual void setPos(int y, int x) = 0;
    virtual void action() = 0;
    virtual void collision(Animal& attacker) = 0;
    virtual void print(Terminal& terminal) = 0;
};

#endif //PO_WILDLIFESIMULATOR_ORGANISM_H