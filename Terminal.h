//
// Created by Michał on 2023-04-19.
//

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#ifndef PO_WILDLIFESIMULATOR_TERMINAL_H
#define PO_WILDLIFESIMULATOR_TERMINAL_H

#define ESC "\033"
#define ITALIC ESC "[3m"
#define ITALIC_OFF ESC "[23m"
#define WHITE 254
#define DIRTY_WHITE 249
#define DEVIOUS_GREY 239
#define DISCO_PURPLE 57
#define DARK_BLUE 23
#define SHY_RED 88
#define RED 130
#define SUNNY_YELLOW 178
#define DULL_BROWN 94
#define SWAMP_GREEN 100
#define VIBRANT_GREEN 28

class Terminal {
private:
    short columns;
    short rows;
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
#endif
    void updateInfo();
public:
    Terminal();
    short getColumns() const;
    short getRows() const;
    void setColor(int color);
    void resetColor();
    void printCC(char character, int color);
    void gotoxy(short y, short x);
    void clear();
};

#endif //PO_WILDLIFESIMULATOR_TERMINAL_H