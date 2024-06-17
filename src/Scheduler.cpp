#include "Scheduler.hpp"

#include <iostream>

Scheduler &Scheduler::getInstance()
{
    static Scheduler instance;
    return instance;
}

Scheduler::ScheduledTask Scheduler::schedule(std::chrono::milliseconds delay, std::function<void()> task)
{
    auto it = tasks.emplace(std::chrono::steady_clock::now() + delay, std::move(task));
    return it;
}

void Scheduler::tick()
{
    auto currentTime = std::chrono::steady_clock::now();
    auto begin = tasks.begin();
    auto end = tasks.upper_bound(currentTime);

    for (auto it = begin; it != end;)
    {
        std::cout << it->first.time_since_epoch() << std::endl;
        it->second();
        it = tasks.erase(it);
    }
}

void Scheduler::getMessage()
{
    std::cout << "Hello World" << std::endl;
}
