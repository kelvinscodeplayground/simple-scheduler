#pragma once
#include <map>
#include <chrono>
#include <functional>

class Scheduler
{
public:
    using Task = std::function<void()>;
    using ScheduledTasks = std::multimap<std::chrono::steady_clock::time_point, Task>;
    using ScheduledTask = ScheduledTasks::iterator;

public:
    Scheduler() = default;
    Scheduler(const Scheduler &) = delete;
    Scheduler &operator=(const Scheduler &) = delete;

    static Scheduler &getInstance();

    ScheduledTask schedule(std::chrono::milliseconds delay, std::function<void()> task);

    void tick();
    void getMessage();

    ~Scheduler() = default;

private:
    ScheduledTasks tasks;
};