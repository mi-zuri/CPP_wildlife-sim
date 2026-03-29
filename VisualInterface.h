//
// Created by Michał on 2023-04-23.
//

#include <string>
#include "Terminal.h"
#include "World.h"

#ifndef PO_WILDLIFESIMULATOR_INTERFACE_H
#define PO_WILDLIFESIMULATOR_INTERFACE_H


class VisualInterface {
private:
    void printSeparator(Terminal &terminal);
    void printSeparatorH(Terminal &terminal, int turn);
    void printEvents(Terminal &terminal, World &world);
    void printOrganismsData(Terminal &terminal, World &world);

public:
    void print(Terminal &terminal, int turn);
    void printWorld(Terminal &terminal, World &world);
    void printWorldData(Terminal &terminal, World &world);
    void printInfo(Terminal &terminal);
    void printCenteredText(Terminal &terminal, const std::string &text);
};


#endif //PO_WILDLIFESIMULATOR_INTERFACE_H
