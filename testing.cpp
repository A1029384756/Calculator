#include "Calculator.hpp"
#include <iostream>
#include <tuple>

#define EPSILON 0.00001

bool compareDoubles(double a, double b) {
    double difference = a - b;
    return (difference < EPSILON) 
        && (difference > -EPSILON);
}

int main() {
    int NUM_ERRORS { 0 };

    Calculator calculator = Calculator();

    std::vector<std::tuple<std::string, std::string, double>> testList = {
        {"addition", "2+3", 5.0} , 
        {"subtraction", "2-3", -1.0}, 
        {"multiplication", "2*3", 6.0}, 
        {"division", "2/3", 0.66666666 },
        {"parentheses", "2*(3+4)", 14.0}
    };


    for (auto [testType, test, expectedResult] : testList) {
        calculator.setInput(test);
        double result = calculator.expressionWrapper();
        bool passed = compareDoubles(result, expectedResult);
        if (!passed) {
            std::cout << "Failed " << testType << ". Got " << result << ". Expected " << expectedResult << "\n";
            NUM_ERRORS++;
        }
    }

    if (NUM_ERRORS > 0)
        std::cout << NUM_ERRORS << " errors encountered.\n";
    
    else
        std::cout << "No errors encountered.\n";

    return 0;
}
