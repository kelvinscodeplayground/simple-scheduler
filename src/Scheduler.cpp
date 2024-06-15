#include "Scheduler.hpp"

#include <iostream>

Scheduler &Scheduler::getInstance()
{
    static Scheduler instance;
    return instance;
}

void Scheduler::getMessage()
{
    std::cout << "Hello World" << std::endl;
}
