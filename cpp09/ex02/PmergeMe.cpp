#include "PmergeMe.hpp"

#include <chrono>
#include <cctype>
#include <iostream>
#include <stdexcept>

// Check that one argument is a valid positive integer.
int PmergeMe::parseNumber(const std::string& value)
{
    if (value.empty())
        throw std::runtime_error("Error");

    for (std::size_t i = 0; i < value.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(value[i])))
            throw std::runtime_error("Error");
    }

    unsigned long long number;
    try
    {
        number = std::stoull(value);
    }
    catch (...)
    {
        throw std::runtime_error("Error");
    }

    if (number == 0 || number > 2147483647ULL)
        throw std::runtime_error("Error");
    return static_cast<int>(number);
}

// Read every argument into the two sorting containers.
void PmergeMe::loadInput(char** argv, int argc)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    // Store each unique number in both containers.
    for (int i = 1; i < argc; ++i)
    {
        int number = parseNumber(argv[i]);
        for (std::size_t j = 0; j < _vector.size(); ++j)
        {
            if (_vector[j] == number)
                throw std::runtime_error("Error");
        }
        _vector.push_back(number);
        _deque.push_back(number);
    }
}

// Build the insertion order used by merge-insert sort.
std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t size)
{
    std::vector<std::size_t> order;
    if (size == 0)
        return order;

    order.push_back(0);
    std::size_t lower = 1;
    std::size_t previous = 1;
    std::size_t current = 3;

    // Insert the pending numbers in Jacobsthal-sized groups.
    while (lower < size)
    {
        std::size_t upper = current < size ? current : size;
        for (std::size_t index = upper; index > lower; --index)
            order.push_back(index - 1);
        lower = current;
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

// Sort a vector with the merge-insert steps.
std::vector<int> PmergeMe::sortVector(const std::vector<int>& values)
{
    if (values.size() <= 1)
        return values;

    std::vector<int> highs;
    std::vector<int> lows;
    bool hasOddValue = values.size() % 2 != 0;
    int oddValue = 0;

    // Keep the larger value in the main chain.
    for (std::size_t i = 0; i + 1 < values.size(); i += 2)
    {
        int first = values[i];
        int second = values[i + 1];
        if (first < second)
        {
            lows.push_back(first);
            highs.push_back(second);
        }
        else
        {
            lows.push_back(second);
            highs.push_back(first);
        }
    }
    if (hasOddValue)
        oddValue = values.back();

    std::vector<int> chain = sortVector(highs);
    std::vector<std::size_t> order = jacobsthalOrder(lows.size());

    // Insert each low number before its matching high number.
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        int value = lows[order[i]];
        int partner = highs[order[i]];
        std::size_t limit = 0;
        while (chain[limit] != partner)
            ++limit;

        std::size_t left = 0;
        std::size_t right = limit;
        while (left < right)
        {
            std::size_t middle = left + (right - left) / 2;
            if (chain[middle] < value)
                left = middle + 1;
            else
                right = middle;
        }
        chain.insert(chain.begin() + left, value);
    }

    if (hasOddValue)
    {
        std::size_t left = 0;
        std::size_t right = chain.size();
        while (left < right)
        {
            std::size_t middle = left + (right - left) / 2;
            if (chain[middle] < oddValue)
                left = middle + 1;
            else
                right = middle;
        }
        chain.insert(chain.begin() + left, oddValue);
    }
    return chain;
}

// Sort a deque with the same merge-insert steps.
std::deque<int> PmergeMe::sortDeque(const std::deque<int>& values)
{
    if (values.size() <= 1)
        return values;

    std::deque<int> highs;
    std::deque<int> lows;
    bool hasOddValue = values.size() % 2 != 0;
    int oddValue = 0;

    // Keep the larger value in the main chain.
    for (std::size_t i = 0; i + 1 < values.size(); i += 2)
    {
        int first = values[i];
        int second = values[i + 1];
        if (first < second)
        {
            lows.push_back(first);
            highs.push_back(second);
        }
        else
        {
            lows.push_back(second);
            highs.push_back(first);
        }
    }
    if (hasOddValue)
        oddValue = values.back();

    std::deque<int> chain = sortDeque(highs);
    std::vector<std::size_t> order = jacobsthalOrder(lows.size());

    // Insert each low number before its matching high number.
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        int value = lows[order[i]];
        int partner = highs[order[i]];
        std::size_t limit = 0;
        while (chain[limit] != partner)
            ++limit;

        std::size_t left = 0;
        std::size_t right = limit;
        while (left < right)
        {
            std::size_t middle = left + (right - left) / 2;
            if (chain[middle] < value)
                left = middle + 1;
            else
                right = middle;
        }
        chain.insert(chain.begin() + left, value);
    }

    if (hasOddValue)
    {
        std::size_t left = 0;
        std::size_t right = chain.size();
        while (left < right)
        {
            std::size_t middle = left + (right - left) / 2;
            if (chain[middle] < oddValue)
                left = middle + 1;
            else
                right = middle;
        }
        chain.insert(chain.begin() + left, oddValue);
    }
    return chain;
}

// Print the original input sequence.
void PmergeMe::printSequence(const std::vector<int>& values)
{
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        if (i != 0)
            std::cout << " ";
        std::cout << values[i];
    }
    std::cout << std::endl;
}

// Print the sorted sequence.
void PmergeMe::printVectorResult(const std::vector<int>& values)
{
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        if (i != 0)
            std::cout << " ";
        std::cout << values[i];
    }
    std::cout << std::endl;
}

// Sort both containers, then display the result and timings.
void PmergeMe::sortAndDisplay()
{
    std::cout << "Before: ";
    printSequence(_vector);

    std::chrono::steady_clock::time_point vectorStart = std::chrono::steady_clock::now();
    std::vector<int> sortedVector = sortVector(_vector);
    std::chrono::steady_clock::time_point vectorEnd = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point dequeStart = std::chrono::steady_clock::now();
    std::deque<int> sortedDeque = sortDeque(_deque);
    std::chrono::steady_clock::time_point dequeEnd = std::chrono::steady_clock::now();

    // Both containers must return the same result.
    if (sortedVector.size() != sortedDeque.size())
        throw std::runtime_error("Error");
    for (std::size_t i = 0; i < sortedVector.size(); ++i)
    {
        if (sortedVector[i] != sortedDeque[i])
            throw std::runtime_error("Error");
    }

    std::cout << "After: ";
    printVectorResult(sortedVector);

    std::chrono::duration<double, std::micro> vectorTime = vectorEnd - vectorStart;
    std::chrono::duration<double, std::micro> dequeTime = dequeEnd - dequeStart;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << vectorTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << dequeTime.count() << " us" << std::endl;
}
