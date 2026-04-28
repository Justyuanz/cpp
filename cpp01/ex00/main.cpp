#include "Zombie.hpp"
#include<iostream>
int main(void)
{
    Zombie *heap = newZombie("HeapZombie");
    if (!heap)
    {
        std::cerr << "Allocation failed" << std::endl;
        return (1);
    }
    heap->announce();
    randomChump("StackZombie");
    delete heap;
    return (0);
}