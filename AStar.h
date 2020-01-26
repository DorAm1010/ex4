//
// Created by dor on 1/23/20.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include "iSearcher.h"
#include <unordered_set>
#include <queue>
#include <stack>



/**
 * Searcher of aStar algorithm.
 * @tparam T state type that saved inside State.
 * @tparam S Solution type.
 */
template <typename T, typename S>
class AStarSearcher : public ISearcher<T,S> {
    class Compare {
    public:
        bool operator() (State<T>* point1, State<T>* point2) {
            // p1 > p2
            int totalCostOfP1 = point1->getCostOfBestPathToMe() + point1->getDistanceFromGoal();
            int totalCostOfP2 = point2->getCostOfBestPathToMe() + point2->getDistanceFromGoal();
            return totalCostOfP1 > totalCostOfP2;
        }
    };

    int evaluatedNodes = 0;

public:

    S search(ISearchable<T> *searchable, SolutionMaker<T,S>* solutionMaker) override {
        std::priority_queue<State<T>*, std::vector<State<T>*>, Compare> openQueue; //compare according to Compare above
        std::unordered_set<State<T>*> closedSet, openSet;
        std::stack<State<T>*> helperStack;
        evaluatedNodes = 0; //restart counting
        State<T> *current, *current_neighbor;
        openQueue.push(searchable->getInitialState());
        openSet.insert(searchable->getInitialState());
        bool notInOpenSet;
        int currentGScore;


        while (openQueue.size() > 0) {
            current = openQueue.top();
            evaluatedNodes++;

            //if goalState, stop and return solution
            if (searchable->isGoalState(current)) {
                return solutionMaker->produceSolution(current);
            }

            openQueue.pop();
            openSet.erase(openSet.find(current));

            //go on all neighbors
            for (std::pair<int, State<T>*> neighbor : searchable->getAllPossibleStates(current)) {

                current_neighbor = neighbor.second;
                currentGScore = current->getCostOfBestPathToMe() + current_neighbor->getMyCost();

                //neighbor don't need update
                if(closedSet.find(current_neighbor) != closedSet.end()
                   || currentGScore >= current_neighbor->getCostOfBestPathToMe()
                   || current_neighbor->getMyCost() < 0) {
                    continue;
                }

                //needs update
                if ((notInOpenSet = (openSet.find(current_neighbor) == openSet.end())) ||
                    currentGScore < current_neighbor->getCostOfBestPathToMe()) {
                    current_neighbor->setWhereICameFrom(current);
                    current_neighbor->setCostOfBestPathToMe(currentGScore);
                    if(notInOpenSet) {
                        openQueue.push(current_neighbor);
                        openSet.insert(current_neighbor);
                    } else {
                        // pop all nodes until current neighbor is reached
                        State<T>* helper = openQueue.top();

                        while (!current_neighbor->isEqual(helper)) {
                            openQueue.pop();
                            helperStack.push(helper);
                            helper = openQueue.top();
                        }
                        openQueue.pop();

                        while (!helperStack.empty()) {
                            openQueue.push(helperStack.top());
                            helperStack.pop();
                        }
                        openQueue.push(current_neighbor);
                    }
                }
            }
            closedSet.insert(current);
        }

        try { //probably there isn't a path to gaol state.
            return solutionMaker->produceSolution(searchable->getGoalState());
        } catch (std::exception e) {
            //throw exception if we didn't manage to produce solution
            throw "AStar Failed!";
        }
    }

    int getNumberOfNodesEvaluated() override {
        return evaluatedNodes;
    }

    AStarSearcher<T,S>* clone() {
        return new AStarSearcher<T,S>();
    }

};
#endif //EX4_ASTAR_H