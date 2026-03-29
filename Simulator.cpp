//
// Created by Michał on 2023-04-19.
//

#include <conio.h>
#include "Simulator.h"

void Simulator::nextTurn(int keycode) {
    if (keycode == 224) {
        // HUMAN ACTION
        keycode = getch();
        switch (keycode) {
            case 72:  // up arrow
                world.moveHuman(1);
                break;
            case 80:  // down arrow
                world.moveHuman(2);
                break;
            case 75:  // left arrow
                world.moveHuman(3);
                break;
            case 77:  // right arrow
                world.moveHuman(4);
                break;
            default:  // not valid input
                return;
        }
    }

    world.nextTurn();
    generateFrame();
//    for (auto i = world.animals.begin(); i !=  world.animals.end(); ++i) {
//        (*i)->print(terminal);
//    }
}

void Simulator::generateFrame() {
    terminal.clear();
    visual_interface.print(terminal, world.getTurn());
    visual_interface.printWorld(terminal, world);
    visual_interface.printWorldData(terminal, world);
}

void Simulator::showInfo() {
    terminal.clear();
    visual_interface.printInfo(terminal);
    // WAITING FOR AN INPUT ...
    getch();
    // GOING BACK TO DISPLAYING THE WORLD
    generateFrame();
}

Simulator::Simulator() {
    // START SCREEN
    visual_interface.printCenteredText(terminal, "PRESS ANY KEY TO BEGIN...");
    // WAITING FOR AN INPUT ...
    getch();
}

void Simulator::run() {
    // STARTING SIMULATION
    generateFrame();

    // SIMULATION LOOP
    int keycode = getch();
    while (keycode != 'q') {
        if (keycode == '\t') showInfo();
        else if (keycode == ' ' || keycode == 224) nextTurn(keycode); // && !alive ... && alive

        // WAITING FOR AN INPUT ...
        keycode = getch();
    }
    //world.delete();
}
