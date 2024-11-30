#ifndef COLPP_HPP
#define COLPP_HPP

#include <vector>
#include "./square.hpp"
#include "./vector2.hpp"

class Colpp {
    private:
    std::vector<Square> squares;

    public:
    int addSquare(Square);
    Square getSquare(int);
    void update();
};

#endif