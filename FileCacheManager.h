
#ifndef EX2_EX2_H
#define EX2_EX2_H

#include <unordered_map>
#include <list>
#include <functional>
#include <fstream>
#include "CacheManager.h"

using namespace std;

template <class T> class FileCacheManager : public CacheManager<string,string>{
    unsigned int capacity;
    unordered_map<string, typename list<pair<string,T>>::iterator> cache;
    list<pair<string, T>> cacheList;
    void updateToMru(string key, T obj) {
        // update an object from the cache to be the most recently used
        auto item = cache.find(key)->second;
        cacheList.erase(item);
        cacheList.push_front({key, obj});
        cache.find(key)->second = cacheList.begin();
    }
    void deleteLru() {
        // delete the least recently used object from the cache
        auto lru = cacheList.end();
        --lru;
        string lruKey = lru->first;
        cacheList.erase(lru);
        cache.erase(cache.find(lruKey));
    }
public:
    FileCacheManager(int cacheCapacity) {
        capacity = cacheCapacity;
    }
    bool inCache(string key) {
        return cache.count(key);
    }
    void insert(string key, string obj) {
        // if key already exists in cache update it
        if (!cache.empty() && cache.count(key)) {
            updateToMru(key, obj);
        }
        else {
            if (cache.size() == capacity) {
                deleteLru();
            }
            // write the object to the cache
            cacheList.push_front({key, obj});
            typename list<pair<string,T>>::iterator itr = cacheList.begin();
            cache[key] = itr;
        }
        // write (or update) the object to the file system
        ofstream outFile;
        key += ".txt";
        outFile.open(key);
        char* objc = (char*) obj.c_str();
        if (outFile.is_open()) {
            outFile << (objc) << "\n";
            outFile.close();
        }
        else {
            throw "Error";
        }
    }
    T get(string key){
        // if the object exists in the cache
        if (!cache.empty() && cache.count(key)) {
            auto item = cache.find(key)->second;
            T obj = item->second;
            updateToMru(key, obj);
            return obj;
        }
        else {
            // check if the object exist in the file system
            ifstream inFile;
            key += ".txt";
            inFile.open(key);
            if (inFile.is_open()) {
                string obj;
                getline(inFile, obj);
                inFile.close();
                // update the object to be the most recently used in the cache
                deleteLru();
                cacheList.push_front({key, obj});
                typename list<pair<string,T>>::iterator itr = cacheList.begin();
                cache[key] = itr;
                return obj;
            }
            throw "Error: Object does not exist";
        }
    }
    void foreach(const function<void(T&)> func){
        for (pair<string, T> pair : cacheList) {
            func(pair.second);
        }
    }
};

#endif //EX2_EX2_H