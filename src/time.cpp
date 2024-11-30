#include "../include/time.hpp"
#include <chrono>

void Time::updateTargetTime(int _fps) {
    Time::targetTime = std::chrono::milliseconds(1000 / _fps);
    Time::lastTime = std::chrono::high_resolution_clock::now();
}

Time::Time(int _fps) {
    Time::updateTargetTime(_fps);
}

bool Time::canUpdate() {
    std::chrono::high_resolution_clock::time_point _currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds _elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(_currentTime - Time::lastTime);
    if (_elapsedTime >= Time::targetTime) {
        Time::lastTime = _currentTime;
        return true;
    }
    return false;
}