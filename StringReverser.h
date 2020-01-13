//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_STRINGSOLVER_H
#define OURSERVER_STRINGSOLVER_H


#include "Solver.h"

class StringSolver : public Solver<class P, class S>{
public:
    S solve(P problem);
};


#endif //OURSERVER_STRINGSOLVER_H
