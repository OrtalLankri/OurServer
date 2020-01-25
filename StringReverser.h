
#ifndef OURSERVER_STRINGSOLVER_H
#define OURSERVER_STRINGSOLVER_H

#include <string>
#include "Solver.h"
#include <algorithm>

using namespace std;

class StringReverser : public Solver<string, string>{
public:
    string solve(string problem);
    StringReverser* clone() override;
};

#endif //OURSERVER_STRINGSOLVER_H
