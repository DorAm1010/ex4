//
// Created by dor on 1/15/20.
//


#include "MatrixProblem.h"

MatrixProblem::MatrixProblem(const Matrix& m, Point s, Point e) {
    matrix = m;
    startPoint = Point(s.getX(), s.getY());
    end_point = Point(e.getX(), e.getY());
    string_representation = m.getStringRepresentaion() +
            std::to_string(s.getX()) + ", " + std::to_string(s.getY()) + "\n" +
            std::to_string(e.getX()) + ", " + std::to_string(e.getY()) + "\n";
}

const std::string &MatrixProblem::toString() const {
    return string_representation;
}
