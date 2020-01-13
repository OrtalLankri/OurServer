//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_STRINGSOLVER_H
#define OURSERVER_STRINGSOLVER_H

#include <string>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string>{
public:
    string solve(string problem);
};


#endif //OURSERVER_STRINGSOLVER_H
