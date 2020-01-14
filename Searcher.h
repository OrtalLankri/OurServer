//
// Created by adi on 1/13/20.
//

#ifndef OURSERVER_SEARCHER_H
#define OURSERVER_SEARCHER_H

#include "Searchable.h"

template <class T> class Searcher {
public:
    S Search(Searchable<T> s);
};

#endif //OURSERVER_SEARCHER_H
