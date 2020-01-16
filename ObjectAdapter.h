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
    string updateBackTrace(vector<Cell*> s);
public:
    string solve(Matrix* problem) override;
};


#endif //OURSERVER_OBJECTADAPTER_H
