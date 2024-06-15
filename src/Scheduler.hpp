#pragma once

class Scheduler
{
public:
    Scheduler() = default;
    Scheduler(const Scheduler &) = delete;
    Scheduler &operator=(const Scheduler &) = delete;

    static Scheduler &getInstance();

    void getMessage();

    ~Scheduler() = default;
};