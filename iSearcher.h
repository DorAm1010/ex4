//
// Created by Laliv on 15/01/2020.
//


#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H
#endif //EX4_SEARCHER_H
#include "iSearchable.h"


template <typename T>
class ISearcher {
public:
    virtual Solution search(ISearchable<T>) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};