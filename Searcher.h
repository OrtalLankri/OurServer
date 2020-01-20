
#ifndef OURSERVER_SEARCHER_H
#define OURSERVER_SEARCHER_H

#include "Searchable.h"
#include "State.h"
#include <vector>

template <class T> class Searcher {
public:
    virtual vector<State<T>*> search(Searchable<T>* s) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //OURSERVER_SEARCHER_H
