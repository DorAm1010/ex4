//
// Created by dor on 1/17/20.
//

#ifndef EX4_SOLVESEARCHADAPTER_H
#define EX4_SOLVESEARCHADAPTER_H

#include "Solver.h"
#include "iSearcher.h"
#include "matrixSolutionMaker.h"

template <typename P, typename S, typename T>
/**
 * adapt a searcher, in order of keeping the right
 * class hierarchy.
 */
class SolveSearchAdapter : public Solver<P,S> {
    ISearcher<T,S>* searcher;
public:
    explicit SolveSearchAdapter(ISearcher<T,S>* _searcher) {
        searcher = _searcher;
    }
    S solve(P p) override {
        MatrixSolutionMaker solutionMaker;
        return searcher->search(&p, &solutionMaker);
    }
    SolveSearchAdapter<P,S,T>* clone() override {
        return new SolveSearchAdapter<P,S,T>(this->searcher->clone());
    }
};
#endif //EX4_SOLVESEARCHADAPTER_H
