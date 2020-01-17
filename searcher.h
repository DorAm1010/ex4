//
// Created by Laliv on 15/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#endif //EX4_SEARCHER_H
#include "iSearcher.h"
#include <queue>

template <typename T>
class Searcher : public ISearcher<T> {
private:
    std::queue<State<T>*> openList; //TODO: need to change to min priority queue?
    int evaluatedNodes;
protected:
    void addToOpenList(State<T>*);
    State<T>* popOpenList();
public:
    Searcher();
    int openListSize();
    int getNumberOfNodesEvaluated() override;
    bool isOpenContains(State<T>*);



};



