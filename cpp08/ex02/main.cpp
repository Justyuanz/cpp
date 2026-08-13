#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

int main()
{
    std::cout << "--- Stack<int> test ---" << std::endl;

    MutantStack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(20);

    std::cout << "top: " << stack.top() << std::endl;
    std::cout << "size: " << stack.size() << std::endl;

    stack.pop();

    std::cout << "top after pop: " << stack.top() << std::endl;

    stack.push(20);

    std::cout << "--- Iterator test ---" << std::endl;

    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator end = stack.end();

    while (it != end)
    {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << "--- String test ---" << std::endl;

    MutantStack<std::string> words;

    words.push("hello");
    words.push("cpp");
    words.push("world");

    std::cout << "top: " << words.top() << std::endl;

    MutantStack<std::string>::iterator strIt = words.begin();
    MutantStack<std::string>::iterator strEnd = words.end();

    while (strIt != strEnd)
    {
        std::cout << *strIt << std::endl;
        ++strIt;
    }


    std::cout << "--- List comparison test ---" << std::endl;

    MutantStack<int> mutant;
    std::list<int> list;

    mutant.push(5);
    mutant.push(17);
    mutant.push(3);

    list.push_back(5);
    list.push_back(17);
    list.push_back(3);

    std::cout << "MutantStack:" << std::endl;

    MutantStack<int>::iterator mit = mutant.begin();
    while (mit != mutant.end())
    {
        std::cout << *mit << std::endl;
        ++mit;
    }

    std::cout << "List:" << std::endl;

    std::list<int>::iterator lit = list.begin();
    while (lit != list.end())
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "--- Copy test ---" << std::endl;

    MutantStack<int> copy(stack);

    std::cout << "copy top: " << copy.top() << std::endl;
    std::cout << "copy size: " << copy.size() << std::endl;

    std::cout << "--- Const iterator test ---" << std::endl;

    const MutantStack<int> constStack(stack);

    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cend = constStack.end();

    while (cit != cend)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }


    std::cout << "--- ++ and -- iterator test ---" << std::endl;

    MutantStack<int>::iterator test = stack.begin();

    std::cout << "start: " << *test << std::endl;

    ++test;
    std::cout << "after ++: " << *test << std::endl;

    --test;
    std::cout << "after --: " << *test << std::endl;

    return 0;
}
