#include <chrono>
#include <thread>
#include <iostream>

#include "Scheduler.hpp"

int main(int argc, char **argv)
{
    using namespace std::chrono_literals;
    bool isRunning { true };
    auto &schedule = Scheduler::getInstance();

    schedule.schedule(5s, []() { std::cout << "Hello World" << std::endl; });
    schedule.schedule(10s, []() { std::cout << "This is after 10s" << std::endl; });
    schedule.schedule(15s, [&]() {
        std::cout << "Cleaning up" << std::endl;
        isRunning = false;
    });

    while (isRunning) {

        auto frameStart = std::chrono::steady_clock::now();
        Scheduler::getInstance().tick();

        auto frameEnd = std::chrono::steady_clock::now();
        auto frameTime =
                std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
        auto sleepTime = (1s / 60) - frameTime;
        std::this_thread::sleep_for(frameTime);
    }

    return 0;
}