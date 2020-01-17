//
// Created by לליב on 15/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T>* cameFrom;
public:
    State(T s, double c, State<T>* st);
    virtual bool isEqual(State<T>*) = 0;
    int getCost();
    void setCost(int);
};


#endif //EX4_STATE_H
