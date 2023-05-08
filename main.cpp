#include "raylib.h"
#include "desktop.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

const int screenWidth = 900;
const int screenHeight = 900;

void UpdateDrawFrame(void);

Desktop defaultDesktop = Desktop(screenWidth, screenHeight);

int main(void)
{
    // Init
    InitWindow(screenWidth, screenHeight, "[FOX ENV]");
    DisableCursor();


#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 30, 1);
#else
    SetTargetFPS(30);
    while (!WindowShouldClose()){UpdateDrawFrame();}
#endif

    // UnInit (TM)
    CloseWindow();

    return 0;
}

void UpdateDrawFrame(void)
{

    BeginDrawing();

    ClearBackground(BLACK);

    DrawFPS(10, 10);

    EndDrawing();
}
