
#include "app_core.h"
MossApp::MossApp(/* args */)
{
    unsigned int dataSize = 0;
    char *path = "resources/fart.menv";
    this->code = LoadFileData(path, &dataSize);

    if (this->code != NULL)
    {
        TraceLog(LOG_INFO, "FILEIO: [%s] Loaded storage value", path);
    }
    else
    {
        TraceLog(LOG_INFO, "FILEIO: [%s] Is null", path);
    }
}

#if defined(PLATFORM_WEB)
EM_JS(void, loadWasm, (), {
    var info = {
    'env': wasmImports,
    'wasi_snapshot_preview1': wasmImports,
  };
    WebAssembly.instantiateStreaming(fetch(locateFile(appData), { credentials: 'same-origin' }), info).then((obj) => {
        obj.instance.exports.cli();
    });
});
// The locateFile is needed so the program thinks we're doing fetch.
#endif

void MossApp::Attach()
{

#if defined(PLATFORM_WEB)
    emscripten::val global = emscripten::val::global("window");
    emscripten::val embeddedCode = emscripten::val::u8string((char *)this->code);
    global.set("appData", embeddedCode);
    loadWasm();

#endif
}
