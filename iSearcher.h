//
// Created by Laliv on 15/01/2020.
//


#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H
#include "iSearchable.h"
#include "SolutionMaker.h"




template <typename T, typename S>
/**
 * class that can search on a searcher.
 * returns a solution.
 * @tparam T state
 * @tparam S solution
 */
class ISearcher {
public:
    virtual S search(ISearchable<T>*, SolutionMaker<T,S>*) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual ISearcher<T,S>* clone()= 0;
};

#endif //EX4_SEARCHER_H