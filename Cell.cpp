//
// Created by adi on 1/15/20.
//

#include "Cell.h"


bool Cell::equals(State<vector<int>>* s) {
    if (s->getState()[0] == this->state[0] && s->getState()[1] == this->state[1]) {
        return true;
    }
    return false;
}
