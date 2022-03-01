#include "Calculator.hpp"

enum class DecimalStates { IN_FRONT, AFTER };

Calculator::Calculator()
{
    std::cout << "Calculator Intitialized\n";
}

Calculator::~Calculator()
{
    std::cout << "Calculator Deleted\n";
}

std::string Calculator::getResult()
{
    return previousAnswer;
}

void Calculator::setInput(std::string &input)
{
    inputExpression = input;
}

double Calculator::arithmetic(double val1, double val2, char operation)
{
    double result { 0.0 };
    switch (operation)
    {
        case '+':
            result = val1+val2;
            break;
        
        case '-':
            result = val1 - val2;
            break;
        
        case '*':
            result = val1 * val2;
            break;
        
        case '/':
            result = val1 / val2;
            break;

        case '^':
            result = std::pow(val1, val2);
            break;
        
        default:
            break;
    }

    return result;
}

void Calculator::findParenthesis(std::string &input)
{
    std::string subExp;
    std::string temp;

    for (int i { 0 }; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            subExp = input.substr(i + 1);
            findParenthesis(subExp);
            input = input.substr(0, i) + subExp;
        }

        else if (input[i] == ')')
        {
            subExp = input.substr(0, i);
            temp = std::to_string(solveExpression(subExp));
            subExp = input.substr(i + 1);
            input = temp + subExp;
            return;
        }
    }
}

double Calculator::solveExpression(std::string &input)
{
    findParenthesis(input);

    valueList.clear();
    operationList.clear();

    double val { 0 };
    int decimalPlaces { 1 };
    char currentChar { ' ' };
    DecimalStates state = DecimalStates::IN_FRONT;

    for (int i = { 0 }; input[i]; i++)
    {
        currentChar = input[i];
        if (isdigit(currentChar))
        {
            switch (state)
            {
            case DecimalStates::IN_FRONT:
                val = val * 10.0 + (double)(currentChar - '0');
                break;

            case DecimalStates::AFTER:
                val = val + (double)(currentChar - '0') / (double)(10 * decimalPlaces);
                decimalPlaces++;
                break;
            
            default:
                break;
            }

        }

        else if (currentChar == ' ') {/*Ignore spaces*/}

        else if (currentChar == '.')
        {
            state = DecimalStates::AFTER;
        }

        else 
        {
            decimalPlaces = 1;
            state = DecimalStates::IN_FRONT;
            valueList.push_back(val);
            operationList.push_back(currentChar);
            val = 0;
        }
    }
    valueList.push_back(val);

    while (!operationList.empty())
    {
        // for (double val : valueList)
        // {
        //     std::cout << val << ", ";
        // }
        // std::cout << "\n";

        // for (char op : operationList)
        // {
        //     std::cout << op << ", ";
        // }
        // std::cout << "\n";

        for (int i { 0 }; i < operationList.size(); i++)
        {
            char previousOperator;
            double val1, val2;

            if ((i - 1) < 0)
                previousOperator = NO_OPERATOR;
            else
                previousOperator = operationList[i - 1];

            if (priority[operationList[i]] <= priority[previousOperator])
            {
                val1 = valueList[i - 1];
                val2 = valueList[i];
                valueList.erase(valueList.begin() + i);                
                valueList[i - 1] = arithmetic(val1, val2, previousOperator);
                operationList.erase(operationList.begin() + i - 1);
            }

            else if (i == operationList.size() - 1)
            {
                val2 = valueList.back();
                valueList.pop_back();
                val1 = valueList.back();
                valueList.back() = arithmetic(val1, val2, operationList.back());
                operationList.pop_back();
            }

        }
    }

    return valueList.back();
}

double Calculator::expressionWrapper()
{
    return solveExpression(inputExpression);
}

double Calculator::expressionWrapper(std::string &input)
{
    return solveExpression(input);
}