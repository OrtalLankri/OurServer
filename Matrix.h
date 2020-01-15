//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_MATRIX_H
#define OURSERVER_MATRIX_H


#include <string>
#include "Searchable.h"
#include "Cell.h"
#include <vector>

using namespace std;

class Matrix : public Searchable<vector<int>> {
    vector<vector<Cell*>> matrix;
    Cell* intialState;
    Cell* goalState;
    vector<State<vector<int>>*> allStates;
    int matrixSize;
public:
    void setStates(State<vector<int>>* initial, State<vector<int>>* goal) {
        this->intialState = (Cell*) initial;
        this->goalState = (Cell*) goal;
    }
    State<vector<int>>* getInitialState();
    bool isGoalState(State<vector<int>>* s);
    vector<State<vector<int>>*> getAllStates(State<vector<int>>* s);
};


#endif //OURSERVER_MATRIX_H