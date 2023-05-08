#ifndef DESKTOP_H
#define DESKTOP_H
#include "raylib.h"

class Desktop
{
private:
    Vector2 mouse;
    int screenSizeX;
    int screenSizeY;
public:
    Desktop(int sizeX, int sizeY);
};

#endif