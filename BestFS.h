
#ifndef OURSERVER_BESTFS_H
#define OURSERVER_BESTFS_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
class BestFS : public Searcher<T> {
    int nodesEvaluated=0;
    class Compare {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return left->getCost() < right->getCost();
        }
    };
public:
    vector<State<T>*> search(Searchable<T>* s) override {
        vector<State<T>*> openList;
        vector<State<T>*> closed;
        openList.push_back(s->getInitialState());
        this->nodesEvaluated ++;
        while (openList.size() > 0) {
            auto t = (min_element(openList.begin(), openList.end(), Compare()));
//            State<T> *top = *(min_element(openList.begin(), openList.end(), Compare()));
            State<T> *top = *t;
            this->nodesEvaluated ++;
            openList.erase(t);
            closed.push_back(top);
            //
            if (s->isGoalState(top)) {
                //path
//                return updateBackTrace(top);
                return closed;
            }
            vector<State<T>*> successors = s->getAllStates(top);
            if(successors.size()==0){
                continue;
            }
            for (int i = 0; i < successors.size(); i++) {
                auto itOpen = find(openList.begin(),openList.end(),successors[i]);
                auto itClosed=find(closed.begin(),closed.end(),successors[i]);
                if(itOpen !=openList.end() && itClosed!=closed.end()){
                    openList.push_back(successors[i]);
                    successors[i]->setCameFrom(top);
                }
                //if this new path is better than previous one
                else {
                    if(successors[i]->getCost()+top->getCost()<successors[i]->getCost()){
                        if(itOpen !=openList.end()){
                            openList.push_back(successors[i]);
                            this->nodesEvaluated ++;
                        } else{
                            successors[i]->setCameFrom(top);
                            //update cost
                            successors[i]->setCost(successors[i]->getCost()+top->getCost());
                        }
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
