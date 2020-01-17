
#ifndef OURSERVER_SEARCHABLE_H
#define OURSERVER_SEARCHABLE_H

#include "State.h"
#include <vector>

using namespace std;

template <class T> class Searchable {
public:
    virtual void setStates(State<T>* initial, State<T>* goal) = 0;
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* s) = 0;
    virtual vector<State<T>*> getAllStates(State<T>* s) = 0;
    virtual int getSize() = 0;
};

#endif //OURSERVER_SEARCHABLE_H
