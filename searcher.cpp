//
// Created by Laliv on 15/01/2020.
//

#include "searcher.h"
template <typename T>

/**
 * pop open list and add one to nodes we evaluated.
 * @tparam T template.
 * @return first element in open list.
 * if list is empty, return null pointer.
 */
State<T>* Searcher<T> ::popOpenList() {
    if(openList.empty()) {
        return nullptr;
    } else {
        evaluatedNodes++;
        State<T> state = openList.front();
        openList.pop();
        return state;

    }
}

template <typename T>

void Searcher<T>::addToOpenList(State<T>* s) {
    openList.push(s);
}

template <typename T>

Searcher<T>::Searcher() {
    evaluatedNodes = 0;
}

template <typename T>

//needed???
int Searcher<T>::openListSize() {
    return openList.size();
}

template <typename T>

int Searcher<T>::getNumberOfNodesEvaluated() {
    return evaluatedNodes;
}

template <typename T>

bool Searcher<T>::isOpenContains(State<T>* s) {
    return openList.contain(s);
}