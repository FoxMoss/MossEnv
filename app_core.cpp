
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#else
#include <stdio.h>
#endif


class FoxApp
{
private:
    char* code; 
public:
    FoxApp(/* args */);
    void Attach();
};

FoxApp::FoxApp(/* args */)
{
}
void FoxApp::Attach()
{

#if defined(PLATFORM_WEB)
    emscripten_run_script("alert('hi')");
#else
    printf("This application has minimal functionality outside a web browser");
#endif
}