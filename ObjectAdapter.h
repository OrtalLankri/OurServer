//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_OBJECTADAPTER_H
#define OURSERVER_OBJECTADAPTER_H

#include "Solver.h"
#include "State.h"
#include "Cell.h"
#include "Matrix.h"
#include <string>
#include <vector>

using namespace std;

class ObjectAdapter : public Solver<Matrix*, string> {
public:
    string solve(Matrix* problem) override;
    string updateBackTrace(State<vector<int>>* s);
};


#endif //OURSERVER_OBJECTADAPTER_H
