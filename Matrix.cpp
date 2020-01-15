//
// Created by ortal on 14/01/2020.
//

#include "Matrix.h"

State<vector<int>>* Matrix::getInitialState() {
    return this->intialState;
}

bool Matrix::isGoalState(State<vector<int>>* s) {
    return this->goalState;
}

vector<State<vector<int>>*> Matrix::getAllStates(State<vector<int>>* s) {
    if (this->allStates.empty()) {
        int i = s->getState()[0];
        int j = s->getState()[1];
        if (i != this->matrixSize - 1 && matrix[i+1][j]->getCost() != -1) {
            this->allStates.push_back(matrix[i+1][j]);
        }
        if (i != 0 && matrix[i-1][j]->getCost() != -1) {
            this->allStates.push_back(matrix[i-1][j]);
        }
        if (j != this->matrixSize - 1 && matrix[i][j+1]->getCost() != -1) {
            this->allStates.push_back(matrix[i][j+1]);
        }
        if (j != 0 && matrix[i][j-1]->getCost() != -1) {
            this->allStates.push_back(matrix[i][j-1]);
        }
    }
    return this->allStates;
}
