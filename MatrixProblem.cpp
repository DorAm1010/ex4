//
// Created by dor on 1/15/20.
//


#include "MatrixProblem.h"

MatrixProblem::MatrixProblem(const Matrix& m, Point s, Point e) {
    rowNum = m.getRows();
    colNum = m.getColumns();
    int r = 0;
    int c = 0;
    std::vector<int> row;
    for(; r < rowNum; r++){
        row = m.getRow(r);
        for(; c < colNum; c++) {
            Point p(r,c);
            State<Point>* s = new State<Point>(p, row.at(c));
            statesMatrix[r][c] = s;
        }
    }
    startPoint = Point(s.getX(), s.getY());
    end_point = Point(e.getX(), e.getY());
    string_representation = m.getStringRepresentaion() +
            std::to_string(s.getX()) + ", " + std::to_string(s.getY()) + "\n" +
            std::to_string(e.getX()) + ", " + std::to_string(e.getY()) + "\n";
}

const std::string &MatrixProblem::toString() const {
    return string_representation;
}

State<Point>* MatrixProblem::getInitialState() {
    return statesMatrix[startPoint.getX()][startPoint.getY()];
}

bool MatrixProblem::isGoalState(State<Point> * state) {
    if(state == statesMatrix[end_point.getX()][end_point.getY()]) {

    }
}

std::list<std::pair<int, State<Point>*>> MatrixProblem::getAllPossibleStates(State<Point> s) {
    std::list<std::pair<int, State<Point>*>> list;
    int cost = s.getMyCost();
    if(cost == -1) {
        return list;
    }
    int i = s.getSate().getX();
    int j = s.getSate().getY();

    int row;
    int col;
    State<Point>* state;
    int costTillNow = s.getCostOfBestPathToMe();
    int newNeighborCost;
    for(row = -1; row < 2; row++) {
        for(col = -1; col < 2; col++) {
            if(row > -1 && row < rowNum - 1, col > -1 && col < colNum - 1 && !(col == j && row == i)) {
                state = statesMatrix[row][col];
                list.insert(std::pair<costTillNow + state->getMyCost(), state>);
            }
        }
    }


}
