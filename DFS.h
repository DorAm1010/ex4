//
// Created by dor on 1/24/20.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include <stack>
#include <unordered_set>
#include "iSearcher.h"

template <typename T,typename S>
/**
 * Searcher of DFS algorithm.
 * @tparam T state type that saved inside State.
 * @tparam S Solution type.
 */
class DFS : public ISearcher<T,S> {

    int evaluatedNodes = 0;
public:
    S search(ISearchable<T> *searchable, SolutionMaker<T, S> *maker) override {
        std::stack<State<T>*> stack;
        std::unordered_set<State<T>*> discovered;
        std::unordered_set<State<T>*> inStack;
        evaluatedNodes = 0; //restart count
        State<T> *current = searchable->getInitialState(), *current_neighbour;
        stack.push(current);

        while (stack.size() > 0) {
            current = stack.top();
            evaluatedNodes++;
            if(searchable->isGoalState(current)) {
                return maker->produceSolution(current);
            }
            stack.pop();
            //current node is not in closed list
            if (discovered.find(current) == discovered.end()) {
                discovered.insert(current);
                for(std::pair<int,State<T>*> neighbour : searchable->getAllPossibleStates(current)) {
                    current_neighbour = neighbour.second;
                    if(current_neighbour->getMyCost() < 0) {
                        continue;
                    }
                    if (discovered.find(current_neighbour) == discovered.end()
                        && inStack.find(current_neighbour) == inStack.end()) {
                        stack.push(current_neighbour);
                        inStack.insert(current_neighbour);
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
            throw "DFS Failed!";
        }
    }


    int getNumberOfNodesEvaluated() override {
        return evaluatedNodes;
    }

    DFS<T,S>* clone() override {
        return new DFS<T,S>();
    }
};
#endif //EX4_DFS_H





////
//// Created by dor on 1/24/20.
////
//
//#ifndef EX4_DFS_H
//#define EX4_DFS_H
//
//#include <stack>
//#include <unordered_set>
//#include "searcher.h"
//
//template <typename T,typename S>
//class DFS : public ISearcher<T,S> {
//    std::stack<State<T>*> stack;
//    std::unordered_set<State<T>*> discovered;
//    int evaluatedNodes = 0;
//public:
//    S search(ISearchable<T> *searchable, SolutionMaker<T, S> *maker) override {
//        State<T> *current = searchable->getInitialState(), *current_neighbour;
//        stack.push(current);
//
//        while (stack.size() > 0) {
//            current = stack.top();
//            evaluatedNodes++;
//
//            if(searchable->isGoalState(current)) {
//                return maker->produceSolution(current);
//            }
//
//            stack.pop();
//            if (discovered.find(current) != discovered.end()) {
//                discovered.insert(discovered.find(current));
//                for(std::pair<int,State<T>*> neighbour : searchable->getAllPossibleStates(current)) {
//                    current_neighbour = neighbour.second;
//                    if(current_neighbour->getMyCost() < 0) {
//                        continue;
//                    }
//                    stack.push(current_neighbour);
//                    current_neighbour->setWhereICameFrom(current);
//                }
//            }
//        }
//        throw "Error in DFS!";
//    }
//
//    int getNumberOfNodesEvaluated() override {
//        return evaluatedNodes;
//    }
//

//};
//#endif //EX4_DFS_H
