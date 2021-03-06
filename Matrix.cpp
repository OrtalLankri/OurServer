
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
    vector<State<vector<int>>*> allStates;
    int i = s->getState()[0];
    int j = s->getState()[1];
    // left
    if (i != 0 && matrix[i - 1][j]->getCost() != -1) {
        allStates.push_back(matrix[i - 1][j]);
    }
    // up
    if (j != 0 && matrix[i][j - 1]->getCost() != -1) {
        allStates.push_back(matrix[i][j - 1]);
    }
    // down
    if (j != this->matrixSize - 1 && matrix[i][j + 1]->getCost() != -1) {
        allStates.push_back(matrix[i][j + 1]);
    }
    // right
    if (i != this->matrixSize - 1 && matrix[i + 1][j]->getCost() != -1) {
        allStates.push_back(matrix[i + 1][j]);
    }
    return allStates;
}

void Matrix::initialTempCosts() {
    for (vector<Cell*> row : this->matrix) {
        for (Cell* cell : row) {
            cell->setTempCost(10000);
        }
    }
    // set the initial to its cost
    double initial_cost = this->matrix[0][0]->getCost();
    this->matrix[0][0]->setTempCost(initial_cost);
}