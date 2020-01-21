//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_ASTAR_H
#define OURSERVER_ASTAR_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include "Matrix.h"
#include <deque>
#include <string>
#include <iostream>

using namespace std;
template<class T>
class AStar :public Searcher<T> {
    int nodesEvaluated=0;
    class Compare {
        State<T>* goal;
    public:
        Compare(State<T>* g){
            this->goal=g;
        }
        using Point = std::vector<int>;
        double distance(Point cur, Point goal){
            int x = abs(cur[0] - goal[0]);
            int y = abs(cur[1] - goal[1]);
            return x+y;
        }

        bool operator()(State<T> *left, State<T> *right) {
            return left->getCost() + distance(left->getState(),
                    this->goal->getState()) < right->getCost() + distance(right->getState(),
                            this->goal->getState());
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
            auto t = (min_element(openList.begin(), openList.end(), Compare(s->getGoalState())));
            State<T> *top = *t;
            openList.erase(t);
            closed.push_back(top);
            //
            if (s->isGoalState(top)) {
                //path
                return this->getPath(top);
            }
            vector<State<T>*> successors = s->getAllStates(top);
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
                    successors[i]->setCameFrom(top);
                    successors[i]->setTempCost(successors[i]->getCost() + top->getTempCost());
                }
            }
        }
    }

    /*
    vector<State<T>*> search(Searchable<T>* s) override {
        vector<State<T> *> openList;
        vector<State<T> *> closed;
        vector<State<T>*> path;
        openList.push_back(s->getInitialState());
        this->nodesEvaluated ++;
        while (openList.size() > 0) {
            auto t = (min_element(openList.begin(), openList.end(), Compare(s->getGoalState())));
            State<T> *top = *t;
            path.push_back(top);
            openList.erase(t);
            closed.push_back(top);
            if (s->isGoalState(top)) {
                cout<<"end";
//                return getPath(top);
                return path;
            }
            vector<State<T>*> successors = s->getAllStates(top);

            for (State<T> *&successor : successors) {
                successor->setCameFrom(top);
                cout<<"ssson: " << successor->getCost()<< ", father: " << successor->getCameFrom()->getCost()<<endl;
                successor->setTempCost(successor->getCost() + top->getTempCost());

                if (find_if(closed.begin(), closed.end(),[successor](decltype(*begin(closed)) ptr )  {
                                return ptr->getState() == successor->getState();
                            }) != closed.end()) {
                    continue;
                }

                auto itr = find_if(openList.begin(), openList.end(),[successor](decltype(*begin(openList)) ptr) {
                                       return ptr->getState() == successor->getState();
                                   });

                if (itr != openList.end()) {
                    (*itr)->setTempCost(min((*itr)->getTempCost(), top->getTempCost() + (*itr)->getCost()));
                    cout<<"son: " << successor->getCost()<< ", father: " << successor->getCameFrom()->getCost()<<endl;

                } else{
                    openList.push_back(successor);
                    this->nodesEvaluated++;
                }
            }
        }
        return {};
    }
     */
    int getNumberOfNodesEvaluated() override {
        return this->nodesEvaluated;
    }
};


#endif //OURSERVER_ASTAR_H
