#ifndef APP_CORE_H
#define APP_CORE_H
#include <fstream>
#include <stdlib.h>
#include "raylib.h"


#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#include <emscripten/val.h>
#endif
class MossApp
{
private:
    unsigned char *code;

public:
    MossApp(/* args */);
    void Attach();
};


#endif