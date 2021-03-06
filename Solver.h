
#ifndef OURSERVER_SOLVER_H
#define OURSERVER_SOLVER_H

template <class P, class S> class Solver {
public:
    virtual S solve(P problem) = 0;
    virtual Solver* clone() = 0;
    virtual ~Solver(){}
};

#endif //OURSERVER_SOLVER_H
