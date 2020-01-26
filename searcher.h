//
// Created by Laliv on 15/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "iSearcher.h"
#include <queue>

template <typename T, typename S>
/**
 * a kind of searcher.
 * @tparam T state
 * @tparam S solution
 */
class Searcher : public ISearcher<T,S> {
private:
    class Compare {
    public:
        bool operator() (State<T>* s1, State<T>* s2)
        {
            return (s1->getCostOfBestPathToMe() > s2->getCostOfBestPathToMe());
        }
    };
    int evaluatedNodes;
protected:
    std::priority_queue<State<T>*, std::vector<State<T>*>, Compare> openList;
    void addToOpenList(State<T>* s)  {
        openList.push(s);
    };
    /**
    * pop open list and add one to nodes we evaluated.
   * @tparam T template.
   * @return first element in open list.
   * if list is empty, return null pointer.
   */
    State<T>* popOpenList() {
        if(openList.empty()) {
            return nullptr;
        } else {
            evaluatedNodes++;
            State<T>* state = openList.top();
            openList.pop();
            return state;
        }
    };

    /**
     * for poping in order to take a state out of the queue (and not
     * passing on it in the algorithm).
     * @return the top state.
     */
    State<T>* popOpenListWithoutCount() {
        if(openList.empty()) {
            return nullptr;
        } else {
            State<T>* state = openList.top();
            openList.pop();
            return state;
        }
    };

public:
    Searcher() {
        evaluatedNodes = 0;
    };
    int openListSize() {
        return openList.size();
    };
    int getNumberOfNodesEvaluated() override {
        return evaluatedNodes;
    };

    /**
     * only check if a state is in the open list.
     * @param s state to check
     * @return true if exist, false otherwise.
     */
    bool isOpenContains(State<T>* s)  {
        std::list<State<T>*> popedStates;
        State<T>* temp = popOpenListWithoutCount();
        bool isEqual = false;
        while(temp != NULL) {
            popedStates.push_back(temp);
            if(s->isEqual(temp)) {
                isEqual = true;
                break;
            }
            temp = popOpenListWithoutCount();
        }

        for(auto state : popedStates) {
            addToOpenList(state);
        }
        return isEqual;
    };

    void zeroEvaluatedNodes() {
        evaluatedNodes = 0;
    }

};

#endif //EX4_SEARCHER_H




