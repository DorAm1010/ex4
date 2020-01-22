//
// Created by dor on 1/21/20.
//

#ifndef EX4_MATRIXSOLUTIONMAKER_H
#define EX4_MATRIXSOLUTIONMAKER_H

#include "SolutionMaker.h"
#include "MatrixProblem.h"

template <typename T, typename S>
class MatrixSolutionMaker : public SolutionMaker<T> {

    S produceSolution(State<T>* goalState) override {
        int fatherI, fatherJ, childI, childJ;
        S solution = "";
        State<T> *child = goalState, *father = goalState->getWhereICameFrom;

        if(child == nullptr) {
            solution = "No Solution Found!";
        } else if (father == nullptr) {
            solution = "Start Point is Solution";
        } else {
            while (father != nullptr) {
                // set father i, j coordinates
                fatherI = father->getState.getX;
                fatherJ = father->getState.getY;
                // set child i, j coordinates
                childI = child->getState.getX;
                childJ = child->getState.getY;

                if(fatherI == childI + 1) {
                  solution += "Left, ";
                } else if(fatherI == childI - 1) {
                  solution += "Right, ";
                } else if(fatherJ == childJ + 1) {
                  solution += "Up, ";
                } else if(fatherJ == childJ - 1) {
                  solution += "Down, ";
                } else {
                    throw "Error in solution building";
                }

                child = father;
                father = father->getWhereICameFrom;
            }
        }

        return solution;
    }
};
#endif //EX4_MATRIXSOLUTIONMAKER_H
