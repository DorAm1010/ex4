//
// Created by laliv on 24/01/2020.
//

#ifndef EX4_BREADTHFIRSTSEARCH_H
#define EX4_BREADTHFIRSTSEARCH_H
#include <stack>
#include <unordered_set>
#include "iSearcher.h"
#include <queue>

template <typename T,typename S>
/**
 * Searcher of BFS algorithm.
 * @tparam T state type that saved inside State.
 * @tparam S Solution type.
 */
class BFS : public ISearcher<T,S> {
    std::queue<State<T>*>queue;
    int evaluatedNodes = 0;
    bool isQueueContains(State<T>* s)  {
        std::queue<State<T>*> popedStates;
        State<T>* temp;
        bool isEqual = false;
        while(queue.size() > 0) {
            temp = queue.front();
            queue.pop();
            popedStates.push(temp);
            if(s->isEqual(temp)) {
                isEqual = true;
            }
        }
        queue = popedStates;
        return isEqual;
    };

public:
    S search(ISearchable<T> *searchable, SolutionMaker<T, S> *maker) override {
        std::queue<State<T>*> newQueue;
        queue = newQueue;
        std::unordered_set<State<T>*> discovered;
        std::unordered_set<State<T>*> inQueue;
        evaluatedNodes = 0;
        State<T> *current = searchable->getInitialState(), *current_neighbour;
       queue.push(current);

        while (queue.size() > 0) {
            current = queue.front();
            evaluatedNodes++;
            if(searchable->isGoalState(current)) {
                return maker->produceSolution(current);
            }
           queue.pop();
            if (discovered.find(current) == discovered.end()) {
                discovered.insert(current);
                for(std::pair<int,State<T>*> neighbour : searchable->getAllPossibleStates(current)) {
                    current_neighbour = neighbour.second;
                    // current_neighbor cost is -1, aka no pass
                    if(current_neighbour->getMyCost() < 0) {
                        continue;
                    }
                    //current_neighbor not in end list
                    if (discovered.find(current_neighbour) == discovered.end()) {
                        queue.push(current_neighbour);
                        inQueue.insert(current_neighbour);
                        current_neighbour->setCostOfBestPathToMe(neighbour.first);
                        current_neighbour->setWhereICameFrom(current);
                    }
                }
            }
        }
        try { //probably there isn't a path to gaol state.
            return maker->produceSolution(searchable->getGoalState());
        } catch (std::exception e) {
            //throw exception if we didn't manage to produce solution
            throw "Error in DFS!";
        }
    }

    int getNumberOfNodesEvaluated() override {
        return evaluatedNodes;
    }

    BFS<T, S> *clone() override {
        return new BFS<T,S>();
    }
};
#endif //EX4_BREADTHFIRSTSEARCH_H
