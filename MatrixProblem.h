//
// Created by dor on 1/15/20.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H

#include "Problem.h"
#include "Matrix.h"
#include "Point.h"
#include "state.h"
#include "iSearchable.h"

class MatrixProblem : public ISearchable<Point> {
    std::string string_representation;
    std::vector<std::vector<State<Point>*>> statesMatrix;
    Point startPoint;
    Point end_point;
    int rowNum;
    int colNum;
public:
    MatrixProblem(const Matrix&, Point, Point);

    const std::string &toString() const override;

    State<Point>* getInitialState() override;

    bool isGoalState(State<Point>*) override;

    std::list<std::pair<int, State<Point>*>> getAllPossibleStates(State<Point>);

    Solution* produceSolution(State<Point>*);


};


#endif //EX4_MATRIXPROBLEM_H
