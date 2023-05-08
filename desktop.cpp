#include "desktop.h"

Desktop::Desktop(int sizeX, int sizeY)
{
    this->screenSizeX = sizeX;
    this->screenSizeY = sizeY;
    this->mouse = {(float)sizeX/2, (float)sizeY/2};
}

