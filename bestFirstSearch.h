//
// Created by Laliv on 16/01/2020.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "searcher.h"
#include <algorithm>
#include <iterator>

template <typename T, typename S>
/**
 * searcher of type BestFirstSearch.
 * @tparam T state type that saved inside State.
 * @tparam S Solution type.
 */
class BestFirstSearch : public Searcher<T,S> {
public:


    S search(ISearchable<T>* searchable, SolutionMaker<T,S>* solutionMaker) override {

        Searcher<T,S>::zeroEvaluatedNodes(); //restart counting
        Searcher<T,S>::addToOpenList(searchable->getInitialState());
        std::list<State<T>*> listClosed;
        std::list<State<T>*> list;
        bool inListClosed;
        while(Searcher<T,S>::openListSize() > 0) {
            State<T>* father = Searcher<T,S>::popOpenList();
            listClosed.push_back(father);
            if(searchable->isGoalState(father)) {
                return solutionMaker->produceSolution(father);
            }
            //go on all neighbors
            std::list<std::pair<int, State<T>*>> successors = searchable->getAllPossibleStates(father);
            for(std::pair<int, State<T>*> pair : successors) {
                inListClosed = (std::find(listClosed.begin(),listClosed.end(),pair.second) != listClosed.end());
                //new node
                if(!inListClosed && !Searcher<T,S>::isOpenContains(pair.second)) {
                    pair.second->setCostOfBestPathToMe(pair.first);
                    pair.second->setWhereICameFrom(father);
                    Searcher<T,S>::addToOpenList(pair.second);
                } else if(!inListClosed && pair.first < pair.second->getCostOfBestPathToMe()){ //if this cost is better then old one.
                    //if this cost is better then old one
                    if(Searcher<T,S>::isOpenContains(pair.second)) {
                        //take out and in of openQueue
                        State<T>* s = Searcher<T,S>::popOpenListWithoutCount();
                        while(!s->isEqual(pair.second)) {
                            list.push_back(s);
                            s = Searcher<T,S>::popOpenListWithoutCount();
                        }

                        State<T>* t;
                        int ind = 0;
                        int listSize = list.size();
                        while(ind < listSize) {
                            t = list.front();
                            Searcher<T,S>::addToOpenList(t);
                            list.pop_front();
                            ind++;
                        }
                    }

                    pair.second->setCostOfBestPathToMe(pair.first);
                    pair.second->setWhereICameFrom(father);
                    Searcher<T,S>::addToOpenList(pair.second);


                }
            }

        }
    }

    BestFirstSearch<T,S>* clone() {
        return new BestFirstSearch<T,S>();
    }

};


#endif //EX4_BESTFIRSTSEARCH_H