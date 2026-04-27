//
// Created by Michał on 2023-04-19.
//

#include "Simulator.h"

#ifdef _WIN32
#include <conio.h>
static int readKey() {
    return _getch();
}
#else
#include <termios.h>
#include <unistd.h>

static int readKey() {
    static int pendingKey = -1;
    if (pendingKey != -1) {
        int key = pendingKey;
        pendingKey = -1;
        return key;
    }

    termios oldSettings {};
    termios newSettings {};
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= static_cast<unsigned long>(~(ICANON | ECHO));
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    int key = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    if (key == '\x1b') {
        int second = getchar();
        int third = getchar();
        if (second == '[') {
            switch (third) {
                case 'A': pendingKey = 72; return 224;
                case 'B': pendingKey = 80; return 224;
                case 'C': pendingKey = 77; return 224;
                case 'D': pendingKey = 75; return 224;
                default: break;
            }
        }
    }

    return key;
}
#endif

void Simulator::nextTurn(int keycode) {
    if (keycode == 224) {
        // HUMAN ACTION
        keycode = readKey();
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
    readKey();
    // GOING BACK TO DISPLAYING THE WORLD
    generateFrame();
}

Simulator::Simulator() {
    // START SCREEN
    visual_interface.printCenteredText(terminal, "PRESS ANY KEY TO BEGIN...");
    // WAITING FOR AN INPUT ...
    readKey();
}

void Simulator::run() {
    // STARTING SIMULATION
    generateFrame();

    // SIMULATION LOOP
    int keycode = readKey();
    while (keycode != 'q') {
        if (keycode == '\t') showInfo();
        else if (keycode == ' ' || keycode == 224) nextTurn(keycode); // && !alive ... && alive

        // WAITING FOR AN INPUT ...
        keycode = readKey();
    }
    //world.delete();
}
