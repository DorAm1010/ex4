//
// Created by dor on 1/16/20.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
template <typename P, typename S>
/**
 * solve a problem.
 */
class Solver {
public:
    /**
     * solve a problem P.
     */
    virtual S solve(P) = 0;
    /**
     * return a deep clone of solver object.
     */
    virtual Solver* clone() = 0;
};
#endif //EX4_SOLVER_H
