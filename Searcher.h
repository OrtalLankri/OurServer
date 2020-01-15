//
// Created by adi on 1/13/20.
//

#ifndef OURSERVER_SEARCHER_H
#define OURSERVER_SEARCHER_H

#include "Searchable.h"

template <class S,class T> class Searcher {
public:
    virtual S Search(Searchable<T> s)=0;
    void updateBackTrace(State<T>* s);
};

#endif //OURSERVER_SEARCHER_H
