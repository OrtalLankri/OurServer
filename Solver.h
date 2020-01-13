//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_SOLVER_H
#define OURSERVER_SOLVER_H


template <class P, class S> class Solver {
public:
    virtual S solve(P problem);
};


#endif //OURSERVER_SOLVER_H
