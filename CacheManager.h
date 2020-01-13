//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_CACHEMANAGER_H
#define OURSERVER_CACHEMANAGER_H

#include <functional>
//template <typename T>;
using namespace std;

template <class T> class CacheManager {
public:
    void insert(string  key, T object);
    T get(string key);
    bool inCache(string key);

};

#endif //OURSERVER_CACHEMANAGER_H
