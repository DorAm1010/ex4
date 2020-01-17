//
// Created by לליב on 15/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H
#include "state.h"
#include "solution.h"
#include <list>
#endif //EX4_SEARCHABLE_H


template <typename T>

class ISearchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>*) = 0;
    virtual std::list<std::pair<int, State<T>>> getAllPossibleStates() = 0;
    virtual Solution* produceSolution(State<T>*) = 0;
};
