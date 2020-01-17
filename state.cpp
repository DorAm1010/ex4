//
// Created by לליב on 15/01/2020.
//

#include "state.h"


template <typename T>

State<T>::State(T s, double c, State<T>* st) {
    state = s;
    cost = c;
    cameFrom = st;

}

template <typename T>

int State<T>::getCost() {
    return cost;
}

template <typename T>

void State<T>::setCost(int newCost) {
    cost = newCost;
}