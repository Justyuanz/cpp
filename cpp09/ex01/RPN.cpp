#include "RPN.hpp"
#include <cctype>
#include <limits>

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}


int RPN::calculate(const std::string &input)
{
    // Read one space-separated token at a time.
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
            // Operators consume the two top values.
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
                    // Check the result bounds before signed addition.
                    if ((right > 0 && left > std::numeric_limits<int>::max() - right) ||
                        (right < 0 && left < std::numeric_limits<int>::min() - right))
                        throw std::runtime_error("Error");
                    result = left + right;
                    break;
                case '-':
                    // Check the result bounds before signed subtraction.
                    if ((right < 0 && left > std::numeric_limits<int>::max() + right) ||
                        (right > 0 && left < std::numeric_limits<int>::min() + right))
                        throw std::runtime_error("Error");
                    result = left - right;
                    break;
                case '*':
                    {
                        // Use a wider type so the range check is itself safe.
                        long long product = static_cast<long long>(left) * right;
                        if (product > std::numeric_limits<int>::max() ||
                            product < std::numeric_limits<int>::min())
                            throw std::runtime_error("Error");
                        result = static_cast<int>(product);
                    }
                    break;
                case '/':
                    if (right == 0)
                        throw std::runtime_error("Error");
                    // This is the only signed-int division result out of range.
                    if (left == std::numeric_limits<int>::min() && right == -1)
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
