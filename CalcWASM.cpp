#include <emscripten/bind.h>
#include "Calculator.hpp"

using namespace emscripten;

double calculate(std::string input) {
    Calculator c = Calculator();
    c.setInput(input);
    return c.expressionWrapper();
}

EMSCRIPTEN_BINDINGS(calculator) {
    function("calculate", &calculate);
}
