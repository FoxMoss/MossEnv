
#include <fstream>
#include <emscripten/emscripten.h>
#include <emscripten/val.h>

class MossApp
{
private:
    char *code;

public:
    MossApp(/* args */);
    void Attach();
};

MossApp::MossApp(/* args */)
{
    std::ifstream file("resources/fart.wasm", std::ios::binary);
    if (file)
    {
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        this->code = new char[length];
        file.read(this->code, length);
    }
}
void MossApp::Attach()
{
    emscripten::val global = emscripten::val::global("window");
    global.set("appData", this->code);
}
EM_JS(void, loadWasm, (), {
    WebAssembly.instantiateStreaming(appData, importObject).then((obj) = > {
        obj.instance.exports.cli();
        const table = obj.instance.exports.table;
        console.log(table.get(0)());
    });
});