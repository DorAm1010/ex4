//
// Created by dor on 1/21/20.
//

#ifndef EX4_SOLUTIONMAKER_H
#define EX4_SOLUTIONMAKER_H

#include "iSearchable.h"

template <typename T>
class SolutionMaker {
    virtual Solution produceSolution(State<T>*) = 0;
};
#endif //EX4_SOLUTIONMAKER_H
