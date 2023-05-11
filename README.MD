## FoxEnv
its just dos but for the web
### How Programs Work
1. User drags file onto window to create a file
2. User runs file
3. The file contains raw wasm
- FoxEnv runs js that ataches that [imports the wasm](https://developer.mozilla.org/en-US/docs/WebAssembly/JavaScript_interface/Module/imports)
- The Env then runs program functions based on the context(terminal, gui... ect)
- The program uses [js memory](https://emscripten.org/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html#interacting-with-code-call-javascript-from-native) to give user feedback (slow??)
- Env interprets memory and renders it