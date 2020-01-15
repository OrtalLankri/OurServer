//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_BESTFS_H
#define OURSERVER_BESTFS_H

#include <string>
#include "Searcher.h"
#include "Matrix.h"
#include "State.h"
#include <deque>

using namespace std;

template <class T, class S>
class BestFS :public Searcher<S,T>{
    class Compare {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return left->getCost() < right->getCost();
        }
    };
public:
    S search(Searchable<T>* s) {
        vector<State<T> *> openList;
        vector<State<T> *> closed;
        openList.push_back(s->getInitialState());
        while (openList.size() > 0) {
            State<T> *top = *(min_element(openList.begin(), openList.end(), Compare()));
            openList.erase(top);
            closed.push_back(top);
            updateBackTrace(top);
            if (isGoalState(top->getState())) {
                //path
                return closed;
            }
            vector<State<T> *> successors = s->getAllStates(top);
            for (int i = 0; i < successors.size(); i++) {
                State<T> * itOpen=find(openList.begin(),openList.end(),successors[i]);
                State<T> * itClosed=find(closed.begin(),closed.end(),successors[i]);
                successors[i].setCameFrom(top);
                if(itOpen !=openList.end() && itClosed!=closed.end()){
                    openList.push_back(successors[i]);
                } else {
                    continue;
                }
            }
        }
    }
};


#endif //OURSERVER_BESTFS_H
