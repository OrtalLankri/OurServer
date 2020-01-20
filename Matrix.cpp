//
// Created by ortal on 14/01/2020.
//

#include "Matrix.h"

State<vector<int>> *Matrix::getInitialState() {
    return this->intialState;
}

State<vector<int>> *Matrix::getGoalState() {
    return this->goalState;
}

bool Matrix::isGoalState(State<vector<int>> *s) {
    return this->goalState->equals(s);
}

vector<State<vector<int>> *> Matrix::getAllStates(State<vector<int>> *s) {
    vector<State<vector<int>> *> allStates;
    int i = s->getState()[0];
    int j = s->getState()[1];
    if (i != this->matrixSize - 1 && matrix[i + 1][j]->getCost() != -1) {
        allStates.push_back(matrix[i + 1][j]);
    }
    if (i != 0 && matrix[i - 1][j]->getCost() != -1) {
        allStates.push_back(matrix[i - 1][j]);
    }
    if (j != this->matrixSize - 1 && matrix[i][j + 1]->getCost() != -1) {
        allStates.push_back(matrix[i][j + 1]);
    }
    if (j != 0 && matrix[i][j - 1]->getCost() != -1) {
        allStates.push_back(matrix[i][j - 1]);
    }
    return allStates;
}
