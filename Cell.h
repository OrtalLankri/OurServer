
#ifndef OURSERVER_CELL_H
#define OURSERVER_CELL_H

#include <string>
#include <vector>
#include "State.h"
using namespace std;

class Cell : public State<vector<int>> {
    vector<int> state;
    double cost;
    Cell* cameFrom;
public:
    Cell(vector<int> state) {
        this->state = state;
    }
    vector<int> getState() override {
        return this->state;
    }
    double getCost() override {
        return this->cost;
    }
    void setCost(double c) override {
        this->cost = c;
    }
    Cell* getCameFrom() override {
        return this->cameFrom;
    }
    void setCameFrom(State<vector<int>>* s) override {
        this->cameFrom = (Cell*) s;
    }
    bool equals(State<vector<int>>* s) override;
};

#endif //OURSERVER_CELL_H
