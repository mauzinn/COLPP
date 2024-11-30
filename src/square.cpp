#include "../include/square.hpp"
#include <vector>
#include <iostream>

Square::Square(Vector2 _size, bool _isHeavy) {
    Square::size = _size;
    Square::isHeavy = _isHeavy;
    Square::colliding = false;
}

bool Square::isColliding(Square _square) {
    return (
        Square::position.x < (_square.position.x + _square.size.x) && (Square::position.x + Square::size.x) > _square.position.x &&
        Square::position.y < (_square.position.y + _square.size.y) && (Square::position.y + Square::size.y) > _square.position.y
    );
}

void Square::update(std::vector<Square> _squares, double _gravity) {
    for (int i = 0; i < _squares.size(); i++) { //optimizate this in the future
        if (!(_squares[i].position.x == Square::position.x && _squares[i].position.y == Square::position.y)) {
            Square::colliding = Square::isColliding(_squares[i]);
        }
    }

    if (!Square::colliding && Square::isHeavy) {
        Square::position.y += Square::aceleration.y;
        if (Square::aceleration.y < 0.9) {
            Square::aceleration.y += _gravity;
        }
    } else {
        Square::aceleration.y = 0;
    }
}

void Square::setPosition(Vector2 _vector) {
    Square::position.x = _vector.x;
    Square::position.y = _vector.y;
}

void Square::print() {
    std::cout << "--> Square Data <--\n";
    std::cout << "Position: " << Square::position.x << ", " << Square::position.y << '\n';
    std::cout << "Aceleration: " << Square::aceleration.x << ", " << Square::aceleration.y << '\n';
    std::cout << "Colliding: " << Square::colliding << '\n';
    std::cout << "--> End <--\n";
}