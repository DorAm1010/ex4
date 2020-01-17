//
// Created by Laliv on 16/01/2020.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "searcher.h"

template <typename T>

class BestFirstSearch : public Searcher<T> {
public:
    Solution search(ISearchable<T> searchable) override;
};


#endif //EX4_BESTFIRSTSEARCH_H
