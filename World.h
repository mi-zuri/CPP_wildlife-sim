//
// Created by Michał on 2023-04-20.
//

#include <memory>
#include <vector>
#include "Organism.h"
#include "Animal.h"

#ifndef PO_WILDLIFESIMULATOR_WORLD_H
#define PO_WILDLIFESIMULATOR_WORLD_H

#define WORLD_WIDTH 40
#define WORLD_HEIGHT 20
#define W WORLD_WIDTH
#define H WORLD_HEIGHT

class World {
private:
    int turn = 1;
    // 2D VECTOR OF POINTERS TO ORGANISMS REPRESENTING THE WORLD'S STATE
    std::vector<std::vector<std::shared_ptr<Organism>>> organisms;
    // VECTOR OF POINTERS TO ANIMALS SORTED BASED ON AN ORDER OF THEIR ACTIONS
    std::vector<std::shared_ptr<Animal>> animals;
    template<typename T>
    std::shared_ptr<Organism> createAnimal(int i, int j);
    template<typename T>
    std::shared_ptr<Organism> createPlant(int i, int j);
    void createHuman();
    static bool priority(const std::shared_ptr<Animal> &a, const std::shared_ptr<Animal> &b);
    void sortAnimals();
public:
    int humanY;
    int humanX;
    World();
    int getTurn() const;
    const std::vector<std::vector<std::shared_ptr<Organism>>> &getOrganisms() const;
    void killOrganism(int y, int x);
    void swapOrganisms(int y1, int x1, int y2, int x2);
    void nextTurn();
    void moveHuman(int move);
};


#endif //PO_WILDLIFESIMULATOR_WORLD_H