//
// Created by dor on 1/15/20.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H

#include "Matrix.h"
#include "Point.h"
#include "iSearchable.h"

/**
 * a matrix that can be searched, meaning
 * each cell is a node that can go to the cells
 * next to him.
 */
class MatrixProblem : public ISearchable<Point> {
    std::string string_representation;
    std::vector<std::vector<State<Point>*>> statesMatrix;
    Point start_Point;
    Point end_point;
    int rowNum;
    int colNum;
public:
    MatrixProblem(const Matrix&, Point, Point);

    const std::string &toString() const override;

    State<Point>* getInitialState() override;

    bool isGoalState(State<Point>*) override;

    std::list<std::pair<int, State<Point>*>> getAllPossibleStates(State<Point>*) override;

    void printMatrixProblem();

    int getCostOfPathToGoal();

    State<Point>* getGoalState() override ;

};


#endif //EX4_MATRIXPROBLEM_H
