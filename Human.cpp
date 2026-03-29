//
// Created by Michał on 2023-04-23.
//

#include "Human.h"
#include "World.h"

void Human::action(int move) {
    int moveX = 0;
    int moveY = 0;
    switch (move) {
        case 1:
            moveY--;
            break;
        case 2:
            moveY++;
            break;
        case 3:
            moveX--;
            break;
        case 4:
            moveX++;
            break;
        default:    // do nothing
            break;
    }

    moveY *= range;
    moveX *= range;
    if (world.getOrganisms()[position.y + moveY][position.x + moveX] != nullptr) {
        world.getOrganisms()[position.y + moveY][position.x + moveX]->collision(*this);
    } else world.swapOrganisms(position.y, position.x, position.y + moveY, position.x + moveX);
    world.humanY = position.y;
    world.humanX = position.x;
}

void Human::collision() {

}

void Human::print(Terminal& terminal) {
    terminal.printCC('I', DISCO_PURPLE);
}