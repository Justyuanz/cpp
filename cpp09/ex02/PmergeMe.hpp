#pragma once

#include <cstddef>
#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    int parseNumber(const std::string& value);
    std::vector<std::size_t> jacobsthalOrder(std::size_t size);

    std::vector<int> sortVector(const std::vector<int>& values);
    std::deque<int> sortDeque(const std::deque<int>& values);

    void printSequence(const std::vector<int>& values);
    void printVectorResult(const std::vector<int>& values);

public:
    PmergeMe() = default;
    PmergeMe(const PmergeMe& other) = default;
    PmergeMe& operator=(const PmergeMe& other) = default;
    ~PmergeMe() = default;

    void loadInput(char** argv, int argc);
    void sortAndDisplay();
};
