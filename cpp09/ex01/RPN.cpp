#include "RPN.hpp"
#include <cctype>

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}


int RPN::calculate(const std::string &input)
{
    for (std::size_t i = 0; i < input.size(); i++)
    {
        char c = input[i];

        if (c == ' ')
            continue;
        if (i > 0 && input[i - 1] != ' ')
            throw std::runtime_error("Error");
        if (i + 1 < input.size() && input[i + 1] != ' ')
            throw std::runtime_error("Error");
        if (std::isdigit(c))
           _stack.push(c - '0');
        else if (isOperator(c))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int right = _stack.top();
            _stack.pop();

            int left = _stack.top();
            _stack.pop();

            int result;

            switch (c)
            {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    if (right == 0)
                        throw std::runtime_error("Error");
                    result = left / right;
                    break;
            }

            _stack.push(result);
        }
        else
            throw std::runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
