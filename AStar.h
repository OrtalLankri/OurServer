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

template<class T>
class AStar :public Searcher<T> {
    int nodesEvaluated=0;
    class Compare {
        T goal;
    public:
        Compare(T g){
            this->goal=g;
        }
        using Point = std::pair<int,int>;
        double distance(Point cur, Point goal){
            int x = abs(cur.first - goal.first);
            int y = abs(cur.second - goal.second);
            return x+y;
        }

        bool operator()(State<T> *left, State<T> *right) {
            return left->getCost() + distance(left->getState(),
                    this->goal) < right->getCost() + distance(right->getState(), this->goal);
        }
    };
public:
    vector<State<T>*> search(Searchable<T>* s) override {
        vector<State<T> *> openList;
        vector<State<T> *> closed;
        openList.push_back(s->getInitialState());
        this->nodesEvaluated ++;
        while (openList.size() > 0) {
            auto t = (min_element(openList.begin(), openList.end(), Compare()));
//            State<T> *top = *(min_element(openList.begin(), openList.end(), Compare()));
            State<T> *top = *t;
            openList.erase(t);
            closed.push_back(top);
            if (top->getState() == s->getGoalNode()) {
                return {top};
            }
            vector<State<T>*> successors = s->getAllStates(top);

            for (State<T> *&successor : successors) {
                successor->setCameFrom(top);
                successor->setCost(successor->getCost() + top->getCost());


                if (find_if(closed.begin(), closed.end(),
                            [successor](decltype(*begin(closed)) ptr )  {
                                return ptr->getState() == successor->getState();
                            }) != closed.end()) {
                    continue;
                }

                auto itr = find_if(openList.begin(), openList.end(),
                                   [successor](decltype(*begin(openList)) ptr)    {
                                       return ptr->getState() == successor->getState();
                                   });

                if (itr != openList.end())  {
                    (*itr)->setCost(min((*itr)->getCost(), top->getCost() + (*itr)->getCost()));
                } else{
                    openList.push_back(successor);
                    this->nodesEvaluated++;
                }
            }
        }
        return {};
    }
};


#endif //OURSERVER_ASTAR_H
