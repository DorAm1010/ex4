//
// Created by לליב on 15/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <class T>
class State {
private:
    T state;
    int myCost;
    int costOfBestPathToMe;
    State<T>* cameFrom;
public:
    State(T s, int c){
        state = s;
        myCost = c;
        cameFrom = nullptr;

    };

    virtual bool isEqual(State<T>* other) {
        if(state == other->getSate()) {
            return true;
        }

        return false;
    };

    int getMyCost(){
        return myCost;
    };

    void setMyCost(int newCost){
        myCost = newCost;
    };

    T getSate() {
        return state;
    };

    int getCostOfBestPathToMe() {
        return costOfBestPathToMe;
    }

    void setCostOfBestPathToMe(int newCost) {
        costOfBestPathToMe = newCost;
    };

    State<T> getWhereICameFrom() {
        return cameFrom;
    }


};


#endif //EX4_STATE_H
