//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_MATRIX_H
#define OURSERVER_MATRIX_H


#include <string>
#include "Searchable.h"

using namespace std;

class Matrix : public Searchable<string> {
public:
    // State<string???> type T
    State<string> getInitialState();
    bool isGoalState(State<string> s);
    vector<State<string>> getAllStates(State<string> s);

};


#endif //OURSERVER_MATRIX_H
