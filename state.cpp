//
// Created by לליב on 15/01/2020.
//

#include "state.h"


template <typename T>

State<T>::State(T s, int c) {
    state = s;
    myCost = c;
    costOfBestPathToMe = -1;
    cameFrom = nullptr;

}

template <typename T>

int State<T>::getCost() {
    return cost;
}

template <typename T>

void State<T>::setCost(int newCost) {
    cost = newCost;
}
template <typename T>

bool State<T>::isEqual(State<T> * other) {
    if(state == other->getSate()) {
        return true;
    }

    return false;
}

template <typename T>

T State<T>::getSate() {
    return state;
}