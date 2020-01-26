//
// Created by לליב on 15/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <values.h>
#include <vector>

template <typename T>
class State {
private:
    T state;
    State<T>* cameFrom;
    int myCost;
    int distanceFromGoal;
    int costOfBestPathToMe;
public:
    State(T s, int c, int distance) {
        state = s;
        myCost = c;
        cameFrom = nullptr;
        distanceFromGoal = distance;
        costOfBestPathToMe = MAXINT;
    }

    bool isEqual(State<T>* other) {
        return state == other->getState();

    };

    int getMyCost(){
        return myCost;
    };

    T getState() const {
        return state;
    }

    int getCostOfBestPathToMe() {
        return costOfBestPathToMe;
    }

    void setCostOfBestPathToMe(int newCost) {
        costOfBestPathToMe = newCost;
    };

    State<T>* getWhereICameFrom() {
        return cameFrom;
    }

    void setWhereICameFrom(State<T>* father) {
        cameFrom = father;
    }

    int getDistanceFromGoal() const {
        return distanceFromGoal;
    }

};


#endif //EX4_STATE_H