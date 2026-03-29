//
// Created by Michał on 2023-04-20.
//

#include <algorithm>
#include "World.h"
#include "RandomNumberGenerator.h"
#include "Human.h"
#include "Tortoise.h"
#include "Sheep.h"
#include "Antelope.h"
#include "Fox.h"
#include "Wolf.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskysHogweed.h"

#define CREATION_CHANCE 36
#define ANIMAL_CHANCE 11
#define SHEEP_CHANCE 6
#define FOX_CHANCE 2
#define FOX_CHANCE_X (SHEEP_CHANCE + FOX_CHANCE)
#define WOLF_CHANCE 1
#define WOLF_CHANCE_X (FOX_CHANCE_X + WOLF_CHANCE)
#define ANTELOPE_CHANCE 1
#define ANTELOPE_CHANCE_X (WOLF_CHANCE_X + ANTELOPE_CHANCE)
// TORTOISE_CHANCE (ANIMAL_CHANCE - ANTELOPE_CHANCE_X) = 1
#define GRASS_CHANCE 15
#define GRASS_CHANCE_X (ANIMAL_CHANCE + GRASS_CHANCE)
#define DANDELION_CHANCE 6
#define DANDELION_CHANCE_X (GRASS_CHANCE_X + DANDELION_CHANCE)
#define GUARANA_CHANCE 2
#define GUARANA_CHANCE_X (DANDELION_CHANCE_X + GUARANA_CHANCE)
#define BELLADONNA_CHANCE 1
#define BELLADONNA_CHANCE_X (GUARANA_CHANCE_X + BELLADONNA_CHANCE)
// HOGWEED_CHANCE (CREATION_CHANCE - BELLADONNA_CHANCE_X) = 1

template<typename T>
std::shared_ptr<Organism> World::createAnimal(int i, int j) {
    animals.push_back(std::make_shared<T>(*this));
    animals.back()->setPos(i, j);
    return animals.back();
}

template<typename T>
std::shared_ptr<Organism> World::createPlant(int i, int j) {
    std::shared_ptr<Organism> temp = std::make_shared<T>(*this);
    temp->setPos(i, j);
    return temp;
}

void World::createHuman() {
    int y = rng::integer(0, H - 1);
    int x = rng::integer(0, W - 1);
    humanY = y;
    humanX = x;
    organisms[y][x] = createAnimal<Human>(y, x);
}

bool World::priority(const std::shared_ptr<Animal> &a, const std::shared_ptr<Animal> &b) {
    if (a->getInitiative() == b->getInitiative()) return (a->getAge() > b->getAge());
    else return (a->getInitiative() > b->getInitiative());
}

void World::sortAnimals() {
    // SORTING ANIMALS BASED ON ORDER OF THEIR ACTION
    // IF TWO ANIMALS HAVE THE SAME INITIATIVE AND ARE OF THE SAME AGE THEIR ORDER IS RANDOM
    std::sort(animals.begin(), animals.end(), priority);
}

World::World() {
    // INITIALIZING ORGANISMS VECTOR
    organisms.resize(H);
    for (auto& i : organisms) {
        i.resize(W);
    }

    createHuman();

    // CREATING ALL THE WILDLIFE
    int rng;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            // IF THERE IS NO HUMAN
            if (organisms[i][j] == nullptr) {
                rng = rng::integer(1,100);
                if (rng <= CREATION_CHANCE) {
                    if (rng <= ANIMAL_CHANCE) {
                        if (rng <= SHEEP_CHANCE) organisms[i][j] = createAnimal<Sheep>(i, j);
                        else if (rng <= FOX_CHANCE_X) organisms[i][j] = createAnimal<Fox>(i, j);
                        else if (rng <= WOLF_CHANCE_X) organisms[i][j] = createAnimal<Wolf>(i, j);
                        else if (rng <= ANTELOPE_CHANCE_X) organisms[i][j] = createAnimal<Antelope>(i, j);
                        else organisms[i][j] = createAnimal<Tortoise>(i, j);
                    } else {
                        if (rng <= GRASS_CHANCE_X) organisms[i][j] = createPlant<Grass>(i, j);
                        else if (rng <= DANDELION_CHANCE_X) organisms[i][j] = createPlant<Dandelion>(i, j);
                        else if (rng <= GUARANA_CHANCE_X) organisms[i][j] = createPlant<Guarana>(i, j);
                        else if (rng <= BELLADONNA_CHANCE_X) organisms[i][j] = createPlant<Belladonna>(i, j);
                        else organisms[i][j] = createPlant<SosnowskysHogweed>(i, j);
                    }
                }
            }
        }
    }
    sortAnimals();
}

int World::getTurn() const {
    return turn;
}

const std::vector<std::vector<std::shared_ptr<Organism>>> &World::getOrganisms() const {
    return organisms;
}

void World::killOrganism(int y, int x) {
    organisms[y][x] = nullptr;
}

void World::swapOrganisms(int y1, int x1, int y2, int x2) {
    std::swap(organisms[y1][x1], organisms[y2][x2]);
    if (organisms[y2][x2] != nullptr) organisms[y2][x2]->setPos(y2, x2);
    if (organisms[y1][x1] != nullptr) organisms[y1][x1]->setPos(y1, x1);
}

void World::nextTurn() {
    turn++;
    // INCREMENTING AGE OF ALL ANIMALS AND EXECUTING THEIR ACTIONS
    for (auto & animal : animals) {
        animal->setAge(animal->getAge() + 1);
        animal->action();
    }
    sortAnimals();
}

void World::moveHuman(int move) {
    (dynamic_cast<Human&>(*organisms[humanY][humanX]).action(move));
}
