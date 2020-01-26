//
// Created by dor on 1/15/20.
//

#include "Point.h"
Point::Point() {}

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

bool Point::operator==(Point other) {
    return x == other.getX() && y == other. getY();
}