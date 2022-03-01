#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>

#define NO_OPERATOR '`'

class Calculator
{
    public:
    Calculator();
    ~Calculator();
    std::string getResult();
    void setInput(std::string &input);
    double expressionWrapper();
    double expressionWrapper(std::string &input);
    double arithmetic(double val1, double val2, char operation);
    void findParenthesis(std::string &input);
    double solveExpression(std::string &input);

    private:
    std::string previousAnswer { "0" };
    std::string inputExpression { "" };
    std::map <char, int> priority { {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-',1}, {NO_OPERATOR, 0} };
    std::vector <char> operationList;
    std::vector <double> valueList;
};

#endif
