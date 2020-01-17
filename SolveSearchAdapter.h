//
// Created by dor on 1/17/20.
//

#ifndef EX4_SOLVESEARCHADAPTER_H
#define EX4_SOLVESEARCHADAPTER_H

#include "Solver.h"
template <typename P, typename S>
class SolveSearchAdapter : public Solver<P,S> {
public:
    S solve(P p) override {
        return nullptr;
    }
};
#endif //EX4_SOLVESEARCHADAPTER_H
