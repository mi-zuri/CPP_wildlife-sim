//
// Created by Michał on 2023-04-19.
//

#include "Terminal.h"
#include <iostream>

void Terminal::updateInfo() {
    // UPDATING INFO ABOUT THE TERMINAL SCREEN
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;
    rows = (short)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}

Terminal::Terminal() {
    // MAKING CURSOR INVISIBLE
    printf(ESC "[?25l");
    // SETTING FOREGROUND COLOR
    resetColor();
    // ASSIGNING INFO ABOUT THE TERMINAL SCREEN
    updateInfo();
}

short Terminal::getColumns() const {
    return columns;
}

short Terminal::getRows() const {
    return rows;
}

void Terminal::setColor(int color) {
    printf(ESC "[38;5;%dm", color);
}

void Terminal::resetColor() {
    setColor(WHITE);
}

void Terminal::printCC(char character, int color) {
    setColor(color);
    putchar(character);
    resetColor();
}

void Terminal::gotoxy(short y, short x) {
    printf(ESC "[%d;%dH", y, x);
}

void Terminal::clear() {
    // 2J clears the visible window and 3J clears the scroll back.
    printf(ESC "[2J" ESC "[3J");
    updateInfo();
}