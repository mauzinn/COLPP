#include "../include/colpp.hpp"
#include "../include/square.hpp"
#include "../include/time.hpp"
#include "../include/vector2.hpp"
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    //Declarations
    Colpp engine;
    Time frameLoop(5); // Lower FPS to see better the position Y of the square -- Default FPS is 60
    Square square1(Vector2(50, 50), true);
    square1.setPosition(Vector2(100, 0));
    int id_square_1 = engine.addSquare(square1);

    Square ground1(Vector2(300, 100), false);
    ground1.setPosition(Vector2(0, 100));
    int id_ground_1 = engine.addSquare(ground1);

    //Loop
    while(true) {
        if (frameLoop.canUpdate()) { // Verify the elapsed time of frames
            engine.update();

            //Examples of use
                std::cout << (engine.getSquare(id_square_1).colliding ? "Is colliding!" : "is not colliding!") << '\n';
                engine.getSquare(id_square_1).print();
        }
    }

    return 0;
}