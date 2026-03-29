//
// Created by Michał on 2023-04-23.
//

#include "Plant.h"
#include "Animal.h"
#include "World.h"

void Plant::setPos(int y, int x) {
    position.y = y;
    position.x = x;
}

void Plant::action() {

}

void Plant::collision(Animal& attacker) {
    if (strength > attacker.getStrength()) {
        attacker.world.killOrganism(attacker.getY(), attacker.getX());
    }
    else {
        world.swapOrganisms(position.y, position.x, attacker.getY(), attacker.getX());
    }
    world.killOrganism(position.y, position.x);
}