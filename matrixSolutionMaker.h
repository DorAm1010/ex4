//
// Created by dor on 1/21/20.
//

#ifndef EX4_MATRIXSOLUTIONMAKER_H
#define EX4_MATRIXSOLUTIONMAKER_H

#include "MatrixProblem.h"


/**
 * produce a solution for a MatrixProblem,
 * after it has been searched. (!)
 */
class MatrixSolutionMaker : public SolutionMaker<Point, std::string> {

    std::string produceSolution(State<Point>* goalState) override {
        int fatherI, fatherJ, childI, childJ;
        std::string solution = "";
        std::string temp;
        State<Point> *child = goalState, *father = goalState->getWhereICameFrom();

        if(child == nullptr) {
            solution = "No Solution Found!";
        } else if (father == nullptr) {
            solution = "Start Point is Solution";
        } else {
            while (father != nullptr) {
                // set father i, j coordinates
                fatherI = father->getState().getX();
                fatherJ = father->getState().getY();
                // set child i, j coordinates
                childI = child->getState().getX();
                childJ = child->getState().getY();

                if(fatherJ == childJ + 1 && fatherI == childI) {
                    solution = "Left (" + std::to_string(child->getCostOfBestPathToMe()) + ") ,"+ solution;
                } else if(fatherJ == childJ - 1 && fatherI == childI) {
                    solution = "Right (" + std::to_string(child->getCostOfBestPathToMe()) + ") ," + solution;
                } else if(fatherI == childI + 1 && fatherJ == childJ) {
                    solution = "Up (" + std::to_string(child->getCostOfBestPathToMe()) + ") ," + solution;
                } else if(fatherI == childI - 1 && fatherJ == childJ) {
                    solution = "Down (" + std::to_string(child->getCostOfBestPathToMe()) + ") ," +  solution;
                } else {
                    throw "Error in solution building";
                }

                child = father;
                father = father->getWhereICameFrom();
            }
        }

        solution.pop_back();
        solution.pop_back();
        solution += "\n";

        return solution;
    }
};
#endif //EX4_MATRIXSOLUTIONMAKER_H