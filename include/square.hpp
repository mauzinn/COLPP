#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "./vector2.hpp"
#include <vector>

class Square {
    private:
    Vector2 position, size;
    Vector2 aceleration;
    bool colliding, isHeavy;

    public:
    Square(Vector2, bool);
    bool isColliding(Square);
    void setPosition(Vector2);
    void print();
    void update(std::vector<Square>, double = 0.1);
};

#endif