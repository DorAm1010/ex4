//
// Created by לליב on 16/01/2020.
//

//#include <functional>
#include "bestFirstSearch.h"
#include <unordered_set>
#include <list>

template <typename T>

Solution BestFirstSearch<T>::search(ISearchable<T> searchable) {
    addToOpenList(searchable.getInitialState());
    std::unordered_set<State<T>> hashMapClosed;
    std::list<State<T>*> list;
    while(Searcher<T>::openListSize() > 0) {
        State<T>* node = Searcher<T>::popOpenList();
        hashMapClosed.insert(node);
        if(isGaolState(node)) {
            return searchable.produceSolution(node);
        }
        std::list<std::pair<int, State<T>>> successors = searchable.getAllPossibleStates();
        for(std::pair<int, State<T>> pair : successors) {
            if(!hashMapClosed.contains(pair.second) && !isOpenContains(pair.second)) {
                pair.second.setCost(pair.first);
                addToOpenList(pair.second);
            } else if(pair.first > pair.second.getCost()){ //if this cost is better then old one.
                if(isOpenContains(pair.second)) {
                    State<T>* s = Searcher<T>::popOpenList();
                    while(!s->isEqual(pair.second)) {
                        list.insert(s);
                        s = Searcher<T>::popOpenList();
                    }
                    pair.second.setCost(pair.first);
                    addToOpenList(s);

                    for(auto t : list) {
                        addToOpenList(t);
                        list.erase(t);
                    }

                }
            }
        }
    }
}