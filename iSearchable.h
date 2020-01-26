//
// Created by לליב on 15/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H
#include "state.h"
#include "Problem.h"
#include <list>



template <typename T>

/**
 * represent something that can be searched.
 * need to have different states and know to go from
 * one state to all the possible states from it.
 * need to have initial state and goal state.
 * @tparam T state.
 */
class ISearchable : public Problem {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>*) = 0;
    virtual std::list<std::pair<int, State<T>*>> getAllPossibleStates(State<T>*) = 0;
    virtual State<T>* getGoalState() = 0;
};

#endif //EX4_SEARCHABLE_H