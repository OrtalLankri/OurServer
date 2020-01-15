//
// Created by adi on 1/15/20.
//

#ifndef OURSERVER_CELL_H
#define OURSERVER_CELL_H


#include <string>
#include <vector>
#include "State.h"
using namespace std;

class Cell : public State<vector<int>> {
    vector<int> state;
    double cost;
//   State<vector<int>> cameFrom;
public:
    Cell(vector<int> state) {
        this->state = state;
    }
    double getCost() {
        return this->cost;
    }
    void setCost(double c) {
        this->cost = c;
    }
    vector<int> getState() {
        return this->state;
    }
    bool equals(State<vector<int>> s);
};

#endif //OURSERVER_CELL_H
