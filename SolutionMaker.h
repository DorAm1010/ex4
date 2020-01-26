//
// Created by dor on 1/21/20.
//

#ifndef EX4_SOLUTIONMAKER_H
#define EX4_SOLUTIONMAKER_H

#include "state.h"
template <typename T, typename S>
class SolutionMaker {
public:
    virtual S produceSolution(State<T>*) = 0;
};
#endif //EX4_SOLUTIONMAKER_H