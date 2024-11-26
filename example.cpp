#include "./include/colpp.hpp"
#include "./include/square.hpp"
#include "./include/vector2.hpp"
#include <chrono>
#include <thread>

int main() {
    Colpp engine;
    Square square_1(Vector2(100, 100), true);
    square_1.setPosition(Vector2(50, 50));
    Square square_2(Vector2(300, 100), false);
    square_2.setPosition(Vector2(0, 200));
    int id_1 = engine.addSquare(square_1);
    int id_2 = engine.addSquare(square_2);

    const double frames_per_second = 30;
    const std::chrono::duration<double> targetTimeToExec(1.0 / frames_per_second);
    std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();

    while(true) {
        std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = currentTime - lastTime;

        if (elapsedTime >= targetTimeToExec) {
            lastTime = currentTime;
            engine.update();
            engine.getSquare(id_1).print();
        }
    }

    return 0;
}