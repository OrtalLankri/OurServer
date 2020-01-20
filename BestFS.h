
#ifndef OURSERVER_BESTFS_H
#define OURSERVER_BESTFS_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include <deque>
#include <string>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

template <class T>
class BestFS : public Searcher<T> {
    int nodesEvaluated;
    class Compare {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return left->getTempCost() < right->getTempCost();
        }
    };
    vector<State<T>*> getPath(State<T>* goal) {
        deque<State<T>*> q;
        State<T>* x = goal;
        while (x != nullptr) {
            q.push_front(x);
            x = x->getCameFrom();
        }
        vector<State<T>*> path;
        while (!q.empty()) {
            path.push_back(q.front());
            q.pop_front();
        }
        return path;
    }
public:
    vector<State<T>*> search(Searchable<T>* s) override {
        vector<State<T>*> openList;
        vector<State<T>*> closed;
        openList.push_back(s->getInitialState());
        this->nodesEvaluated = 1;
        while (openList.size() > 0) {
            auto t = (min_element(openList.begin(), openList.end(), Compare()));
//            State<T> *top = *(min_element(openList.begin(), openList.end(), Compare()));
            State<T> *top = *t;
            openList.erase(t);
            closed.push_back(top);
            //
            if (s->isGoalState(top)) {
                //path
//                return updateBackTrace(top);
                cout<<"end"<<endl;
                return this->getPath(top);
            }
            vector<State<T>*> successors = s->getAllStates(top);
//            if(successors.size()==0){
//                continue;
//            }
            for (int i = 0; i < successors.size(); i++) {
                this->nodesEvaluated++;
                auto itOpen = find(openList.begin(),openList.end(),successors[i]);
                auto itClosed=find(closed.begin(),closed.end(),successors[i]);
                // if successor is not in openList and not in closed list
                if(itOpen == openList.end() && itClosed == closed.end()) {
                    openList.push_back(successors[i]);
                    successors[i]->setCameFrom(top);
                    successors[i]->setTempCost(successors[i]->getCost() + top->getTempCost());
                }
                //if this new path is better than previous one
                else if(successors[i]->getCost() + top->getTempCost() < successors[i]->getTempCost()) {
                    // if successor is not in openList
                    if(itOpen == openList.end()){
                        cout<< "handle!!!" <<endl;
                        openList.push_back(successors[i]);
                    } else {
                        successors[i]->setCameFrom(top);
                        successors[i]->setTempCost(successors[i]->getCost() + top->getTempCost());
                    }
                }
            }
        }
    }
    int getNumberOfNodesEvaluated() override {
        return this->nodesEvaluated;
    }
};


#endif //OURSERVER_BESTFS_H
