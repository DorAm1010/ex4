//
// Created by dor on 1/16/20.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
template <typename P, typename S>
class Solver {
public:
    virtual S solve(P) = 0;
    virtual Solver* clone() = 0;
};
#endif //EX4_SOLVER_H
