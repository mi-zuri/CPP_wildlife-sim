//
// Created by Michał on 2023-04-19.
//

#include "Terminal.h"
#include "VisualInterface.h"
#include "World.h"
#include "Human.h"

#ifndef PO_WILDLIFESIMULATOR_SIMULATOR_H
#define PO_WILDLIFESIMULATOR_SIMULATOR_H

class Simulator {
private:
    Terminal terminal;
    VisualInterface visual_interface;
    World world;
    void nextTurn(int keycode);
    void generateFrame();
    void showInfo();
public:
    Simulator();
    void run();
};

#endif //PO_WILDLIFESIMULATOR_SIMULATOR_H
