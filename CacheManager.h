
#ifndef OURSERVER_CACHEMANAGER_H
#define OURSERVER_CACHEMANAGER_H

#include <functional>

using namespace std;

template <class T,class P>
class CacheManager {
public:
    virtual void insert(string  key, T object) = 0;
    virtual T get(string key) = 0;
    virtual bool inCache(string key) = 0;

};

#endif //OURSERVER_CACHEMANAGER_H
