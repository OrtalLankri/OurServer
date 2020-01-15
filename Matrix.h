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
    void setSize(int size) {
        this->matrixSize = size;
    }
    State<vector<int>>* getInitialState() override;
    bool isGoalState(State<vector<int>>* s) override;
    vector<State<vector<int>>*> getAllStates(State<vector<int>>* s) override;
};


#endif //OURSERVER_MATRIX_H
