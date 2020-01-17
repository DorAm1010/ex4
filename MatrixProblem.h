//
// Created by dor on 1/15/20.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H

#include "Problem.h"
#include "Matrix.h"
#include "Point.h"

class MatrixProblem : public Problem {
    std::string string_representation;
    Matrix matrix;
    Point startPoint;
    Point end_point;
public:
    MatrixProblem(const Matrix&, Point, Point);

    const std::string &toString() const override;

};


#endif //EX4_MATRIXPROBLEM_H
