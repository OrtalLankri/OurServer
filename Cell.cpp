
#include "Cell.h"

bool Cell::equals(State<vector<int>>* s) {
    return ((s->getState()[0] == this->state[0]) && (s->getState()[1] == this->state[1]));
}
