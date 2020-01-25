
#ifndef OURSERVER_MATRIX_H
#define OURSERVER_MATRIX_H

#include <string>
#include "Searchable.h"
#include "Cell.h"
#include <vector>
#include <array>

using namespace std;

class Matrix : public Searchable<vector<int>> {
    vector<vector<Cell*>> matrix;
    Cell* intialState;
    Cell* goalState;
    int matrixSize;
public:
    Matrix(int size) {
        this->matrixSize = size;
    }
    void setInitial(Cell *c) {
        this->intialState = c;
    }
    void setGoal(Cell *c) {
        this->goalState = c;
    }
    void setMatrix(vector<vector<Cell*>> m) {
        this->matrix = m;
    }
    int getSize() override {
        return this->matrixSize * this->matrixSize;
    }
    State<vector<int>>* getGoalState() override;
    State<vector<int>>* getInitialState() override;
    bool isGoalState(State<vector<int>>* s) override;
    vector<State<vector<int>>*> getAllStates(State<vector<int>>* s) override;
    void initialTempCosts() override;
};

#endif //OURSERVER_MATRIX_H
