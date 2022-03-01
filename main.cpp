#include <iostream>
#include "Calculator.hpp"

int main(int argc, char const *argv[])
{
    Calculator calc = Calculator();
    std::string expression;

    while (true)
    {
        std::cout << "Enter an expression: ";
        std::getline(std::cin, expression);
        calc.setInput(expression);
        expression = "";
        std::cout << calc.expressionWrapper() << "\n";
    }    
    return 0;
}
