//
// Created by Michał on 2023-04-23.
//

#include "Animal.h"
#include "World.h"

int Animal::getInitiative() const {
    return initiative;
}

int Animal::getAge() const {
    return age;
}

void Animal::setAge(int age) {
    Animal::age = age;
}

int Animal::getY() const {
    return position.y;
}

int Animal::getX() const {
    return position.x;
}

void Animal::setPos(int y, int x) {
    position.y = y;
    position.x = x;
}

void Animal::action() {
    // if human -> reset
    if (position.y == world.humanY && position.x == world.humanX) return;

    int direction = rng::integer(1, 4);
    int moveY = 0;
    int moveX = 0;
    // TOP-LEFT
    if (position.y - range < 0 && position.x - range < 0) {
        moveY = direction % 2;
        moveX = (direction + 1) % 2;
    }
    // TOP-RIGHT
    else if (position.y - range < 0 && position.x + range >= W) {
        moveY = direction % 2;
        moveX = -((direction + 1) % 2);
    }
    // BOTTOM-LEFT
    else if (position.y + range >= H && position.x - range < 0) {
        moveY = -(direction % 2);
        moveX = (direction + 1) % 2;
    }
    // BOTTOM-RIGHT
    else if (position.y + range >= H && position.x + range >= W) {
        moveY = -(direction % 2);
        moveX = -((direction + 1) % 2);
    }
    // TOP
    else if (position.y - range < 0) {
        if (direction == 2) moveX = 1;
        else if (direction == 4) moveX = -1;
        else moveY = 1;
    }
    // BOTTOM
    else if (position.y + range >= H) {
        if (direction == 2) moveX = 1;
        else if (direction == 4) moveX = -1;
        else moveY = -1;
    }
    // LEFT
    else if (position.x - range < 0) {
        if (direction == 1) moveY = 1;
        else if (direction == 3) moveY = -1;
        else moveX = 1;
    }
    // RIGHT
    else if (position.x + range >= W) {
        if (direction == 1) moveY = 1;
        else if (direction == 3) moveY = -1;
        else moveX = -1;
    }
    // MIDDLE
    else {
        if (direction == 1) moveY = 1;
        else if (direction == 2) moveX = 1;
        else if (direction == 3) moveY = -1;
        else if (direction == 4) moveX = -1;
    }

    moveY *= range;
    moveX *= range;
    if (world.getOrganisms()[position.y + moveY][position.x + moveX] != nullptr) {
        world.getOrganisms()[position.y + moveY][position.x + moveX]->collision(*this);
    } else world.swapOrganisms(position.y, position.x, position.y + moveY, position.x + moveX);
}

void Animal::collision(Animal& attacker) {
    if (strength > attacker.getStrength()) {
        world.killOrganism(attacker.getY(), attacker.getX());
    }
    else {
        world.killOrganism(position.y, position.x);
        world.swapOrganisms(position.y, position.x, attacker.getY(), attacker.getX());
    }
}
