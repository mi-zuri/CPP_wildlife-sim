//
// Created by Michał on 2023-04-23.
//

#include "VisualInterface.h"

#define SEPARATOR_POS (terminal.getColumns()/2 + 1)
#define SEPARATOR_H_POS (3*terminal.getRows()/4)
#define ALIVE_LIST_H (terminal.getRows() - SEPARATOR_H_POS)
#define ALIVE_LIST_W (terminal.getColumns() - SEPARATOR_POS)
#define MARGIN (ALIVE_LIST_W/10)
#define ALIVE_LIST_ROWS 6
#define ALIVE_LIST_COLUMNS 2
#define TURN_COUNT_POS 5

// PRIVATE

void VisualInterface::printSeparator(Terminal &terminal) {
    for (int i = 1; i <= terminal.getRows(); ++i) {
        terminal.gotoxy((short) i, (short) SEPARATOR_POS);
        if (i != SEPARATOR_H_POS) putchar(179);
        else putchar(195);
    }
}

void VisualInterface::printSeparatorH(Terminal &terminal, int turn) {
    // CALCULATING TURN LENGTH (in digits)
    int temp_turn = turn;
    int turn_length = 1;
    while (temp_turn / 10 > 0) {
        turn_length++;
        temp_turn /= 10;
    }
    for (int i = 1; i <= terminal.getColumns() / 2; ++i) {
        terminal.gotoxy((short) SEPARATOR_H_POS, (short) (SEPARATOR_POS + i));
        if (i < TURN_COUNT_POS - 1 || i > TURN_COUNT_POS + 5 + turn_length) putchar(196);             // turn digits
        else if (i == TURN_COUNT_POS) std::cout << "Turn " << turn;
    }
}

void VisualInterface::printEvents(Terminal &terminal, World &world) {
    printf(ITALIC);
    for (int i = 0; i < SEPARATOR_H_POS - 3; ++i) {
        terminal.gotoxy((short) (SEPARATOR_H_POS - 2 - i), (short) (SEPARATOR_POS + MARGIN));
        std::cout << "Fox moves to area 13-57. Kills a sheep.";
    }
    printf(ITALIC_OFF);
}

void VisualInterface::printOrganismsData(Terminal &terminal, World &world) {
    printf(ITALIC);
    for (int j = 0; j < ALIVE_LIST_COLUMNS; ++j) {
        for (int i = 0; i < ALIVE_LIST_ROWS; ++i) {
            terminal.gotoxy((short) (SEPARATOR_H_POS + (ALIVE_LIST_H - ALIVE_LIST_ROWS) / 2 + i + 1),
                            (short) (SEPARATOR_POS + MARGIN + j * ALIVE_LIST_W / 2));
            std::cout << "(F) Fox x6";
        }
    }
    printf(ITALIC_OFF);
}

// PUBLIC

void VisualInterface::print(Terminal &terminal, int turn) {
    printSeparator(terminal);
    printSeparatorH(terminal, turn);
}

void VisualInterface::printWorld(Terminal &terminal, World &world) {
    for (int i = -1; i <= H; ++i) {
        for (int j = -2; j <= W + 1; ++j) {
            terminal.gotoxy((short) (terminal.getRows() / 2 - H / 2 + 1 + i),
                            (short) (terminal.getColumns() / 4 - W / 2 + 1 + j));
            // TOP-LEFT CORNER
            if (i == -1 && j == -2) putchar(218);
                // TOP-RIGHT CORNER
            else if (i == -1 && j == W + 1) putchar(191);
                // BOTTOM-LEFT CORNER
            else if (i == H && j == -2) putchar(192);
                // BOTTOM-RIGHT CORNER
            else if (i == H && j == W + 1) putchar(217);
                // TOP AND BOTTOM
            else if (i == -1 || i == H) putchar(196);
                // SIDES
            else if (j == -2 || j == W + 1) putchar(179);
                // SIDE PADDING
            else if (j == -1 || j == W) putchar(' ');
                // WORLD
            else if (world.getOrganisms()[i][j] != nullptr) world.getOrganisms()[i][j]->print(terminal);
        }
    }
}

void VisualInterface::printWorldData(Terminal &terminal, World &world) {
    printEvents(terminal, world);
    printOrganismsData(terminal, world);
}

void VisualInterface::printInfo(Terminal &terminal) {
    std::string parchment[] = {"   _____________________________",
                               " / \\                            \\",
                               "|   |                            |",
                               " \\_ |                            |",
                               "    |                            |",
                               "    |           " ITALIC "michal" ITALIC_OFF "           |",
                               "    |          " ITALIC "zurawski" ITALIC_OFF "          |",
                               "    |           " ITALIC "193287" ITALIC_OFF "           |",
                               "    |                            |",
                               "    |                            |",
                               "    |        " ITALIC "- WILDLIFE -" ITALIC_OFF "        |",
                               "    |       " ITALIC "- SIMULATION -" ITALIC_OFF "       |",
                               "    |            " ITALIC "v0.8" ITALIC_OFF "            |",
                               "    |                            |",
                               "    |                            |",
                               "    |   _________________________|___.",
                               "    |  /                            /",
                               "    \\_/____________________________/"};

    int parchmentSize = sizeof(parchment) / sizeof(parchment[0]);
    for (int i = 0; i < parchmentSize; ++i) {
        terminal.gotoxy((short) ((terminal.getRows() - parchmentSize) / 2 + i + 1),
                        (short) ((terminal.getColumns() - parchment[8].size()) / 2));
        std::cout << parchment[i];
    }
}

void VisualInterface::printCenteredText(Terminal &terminal, const std::string &text) {
    if (terminal.getColumns() > text.size()) {
        // Aligning the text to the center
        terminal.gotoxy((short) (terminal.getRows() / 2), (short) ((terminal.getColumns() - text.size()) / 2));
    }
    std::cout << text;
}