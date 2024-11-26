#include "../include/colpp.hpp"
#include "../include/square.hpp"
#include "../include/vector2.hpp"

int Colpp::addSquare(Square _square) {
    int id = Colpp::squares.size();
    Colpp::squares.push_back(_square);
    return id;
}

Square Colpp::getSquare(int _id) {
    return Colpp::squares[_id];
}

void Colpp::update() {
    for (int i = 0; i < Colpp::squares.size(); i++) {
        Colpp::squares[i].update(Colpp::squares);
    }
}