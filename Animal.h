//
// Created by Michał on 2023-04-23.
//

#ifndef PO_WILDLIFESIMULATOR_ANIMAL_H
#define PO_WILDLIFESIMULATOR_ANIMAL_H

#include "Organism.h"

// Forward declaration used for world object reference
class World;

class Animal : virtual public Organism {
private:
    int strength;
    int initiative;
    int age = 0;
    int range = 1;
public:
    int getInitiative() const;
    int getAge() const;
    void setAge(int age);
    int getY() const;
    int getX() const;
    void setPos(int y, int x);
    void action();  // przemieszczenie na losowo wybrane pole obok
    void collision(Animal& attacker);   // rozmnożenie w razie natrafienia na drugie zwierze tego samego gatunku
};

#endif //PO_WILDLIFESIMULATOR_ANIMAL_H