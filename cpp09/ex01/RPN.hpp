#pragma once

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> _stack;
    bool isOperator(char c);

public:
    RPN() = default;
    RPN(const RPN &other) = default;
    RPN &operator=(const RPN &other) = default;
    ~RPN() = default;

    int calculate(const std::string &input);
};