//
// Created by dor on 1/15/20.
//
#include "MatrixProblem.h"
#include <iostream>
using namespace std;

/**
 * build a states matrix from a given matrix.
 * get a start state and end state.
 * @param m regular matrix
 * @param startP start point
 * @param endP end point
 */
MatrixProblem::MatrixProblem(const Matrix& m, Point startP, Point endP) {
    rowNum = m.getRows();
    colNum = m.getColumns();
    int r = 0;
    int c = 0;
    std::vector<int> row;
    start_Point = startP;
    end_point = endP;
    std::vector<int> rows;

    //make a states matrix
    for(; r < rowNum; r++){
        std::vector<State<Point>*> stateRow;
        row = m.getRow(r);
        for(; c < colNum; c++) {
            Point p(r,c);
            State<Point>* s = new State<Point>(p, row.at(c),
                                               abs(endP.getX() - r) + abs(endP.getY() - c));
            stateRow.push_back(s);
        }
        c = 0;
        statesMatrix.push_back(stateRow);
    }

    string_representation = m.getStringRepresentaion() +
                            std::to_string(startP.getX()) + ", " + std::to_string(startP.getY()) + "\n" +
                            std::to_string(endP.getX()) + ", " + std::to_string(endP.getY()) + "\n";
    //set the cost of the start state
    State<Point>* startState = statesMatrix[start_Point.getX()][start_Point.getY()];
    startState->setCostOfBestPathToMe(startState->getMyCost());
}

const std::string &MatrixProblem::toString() const {
    return string_representation;
}

State<Point>* MatrixProblem::getInitialState() {
    return statesMatrix[start_Point.getX()][start_Point.getY()];
}

bool MatrixProblem::isGoalState(State<Point> * state) {
    if(state->getState() == end_point) {

    }
}

/**
 * return all the possible states from this state (cell),
 * and the cost of the path to them.
 * @param s node we start from.
 * @return all possible states and costs.
 */
std::list<std::pair<int, State<Point>*>> MatrixProblem::getAllPossibleStates(State<Point>* s) {
    std::list<std::pair<int, State<Point>*>> list;
    int cost = s->getMyCost();
    if(cost == -1) {
        return list;
    }
    int i = s->getState().getX();
    int j = s->getState().getY();

    int row;
    int col;
    State<Point>* state;
    int costTillNow = s->getCostOfBestPathToMe();
    int newNeighborCost;
    //check if s is close to any side of the matrix
    if(i - 1 >= 0) {
        state = statesMatrix[i-1][j];
        newNeighborCost = costTillNow + state->getMyCost();
        list.push_back({newNeighborCost, state});
    }
    if(i + 1 < rowNum) {
        state = statesMatrix[i+1][j];
        newNeighborCost = costTillNow + state->getMyCost();
        list.push_back({newNeighborCost, state});
    }

    if(j - 1 >= 0) {
        state = statesMatrix[i][j - 1];
        newNeighborCost = costTillNow + state->getMyCost();
        list.push_back({newNeighborCost, state});
    }

    if(j + 1 < colNum) {
        state = statesMatrix[i][j + 1];
        newNeighborCost = costTillNow + state->getMyCost();
        list.push_back({newNeighborCost, state});
    }

    return list;


}

void MatrixProblem::printMatrixProblem() {
    int i,j;
    for(i = 0; i < rowNum; i++) {
        for(j = 0; j < colNum; j++) {
            std::cout<< statesMatrix[i][j]->getMyCost();
            std::cout<< " ";
        }
        cout<< "\n";
    }
}

int MatrixProblem::getCostOfPathToGoal() {
    return statesMatrix[end_point.getX()][end_point.getY()]->getCostOfBestPathToMe();
}

State<Point>* MatrixProblem::getGoalState() {
    return statesMatrix[end_point.getX()][end_point.getY()];
}
