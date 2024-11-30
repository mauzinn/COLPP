#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>

struct Time {
    std::chrono::milliseconds targetTime;
    std::chrono::high_resolution_clock::time_point lastTime;

    Time(int = 60);
    void updateTargetTime(int);
    bool canUpdate();
};

#endif