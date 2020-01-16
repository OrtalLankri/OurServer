//
// Created by ortal on 14/01/2020.
//

#include "ObjectAdapter.h"

string ObjectAdapter::solve(Matrix* problem){
    // check all algorithm and choose the best one
    // get the vector<Cell*> solution from the search method in the chosen algorithm
    //return this->updateBackTrace(solution);
}

string ObjectAdapter::updateBackTrace(vector<Cell*> path) {
    string trace = "";
    int cost = 0;
    for (Cell *cell : path) {
        Cell *father = cell->getCameFrom();
        cost += cell->getCost();
        if (father != nullptr) {
            int x1 = father->getState()[0];
            int y1 = father->getState()[1];
            int x2 = cell->getState()[0];
            int y2 = cell->getState()[1];
            if (y1 > y2 && x1 == x2) {
                trace += "Right (";
            } else if (y1 < y2 && x1 == x2) {
                trace += "Left (";
            } else if (y1 == y2 && x1 < x2) {
                trace += "Up (";
            } else if (y1 == y2 && x1 > x2) {
                trace += "Down (";
            }
            trace += to_string(cost) + "), ";
        }
    }
    return trace;
}
