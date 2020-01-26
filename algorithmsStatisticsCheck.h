//
// Created by Laliv on 25/01/2020.
//

#ifndef EX4_ALGORITHMSSTATISTICSCHECK_H
#define EX4_ALGORITHMSSTATISTICSCHECK_H

#include "MatrixProblem.h"

/**
 * this class runs a statistic check on our algorithms.
 */
class AlgorithmsStatisticsCheck {
private:
    Matrix produceMatrixProblem(int N);
public:
    void runCheck();
};

#endif //EX4_ALGORITHMSSTATISTICSCHECK_H
