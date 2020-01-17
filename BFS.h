
#ifndef OURSERVER_BFS_H
#define OURSERVER_BFS_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include <vector>
#include <map>
#include <queue>

template <class T>
class BFS : public Searcher<T> {
    int nodesEvaluated;
public:
    vector<State<T>*> search(Searchable<T>* s) override {
        map<State<T>*, vector<State<T>*>> paths;
        queue<State<T>*> openList;
        vector<State<T>*> visited;
        // initialize
        State<T>* initial = s->getInitialState();
        this->nodesEvaluated = 1;
        openList.push(initial);
        visited.push_back(initial);
        vector<State<T>*> path;
        paths[initial] = path;
        // get path to goal
        while (!openList.empty()) {
            State<T>* v = openList.front();
            openList.pop();
            // if v is goal state, return its path
            if (s->isGoalState(v)) {
                vector<State<T>*> p = paths[v];
                p.push_back(v);
                return p;
            }
            // for each adjacent of v
            for (State<T>* adj : s->getAllStates(v)) {
                // if adjacent has not been visited before
                if (find(visited.begin(), visited.end(), adj) != visited.end()) {
                    visited.push_back(adj);
                    openList.push(adj);
                    adj->setCameFrom(v);
                    this->nodesEvaluated++;
                    // add path
                    vector<State<T>*> p = paths[v];
                    p.push_back(v);
                    paths[adj] = p;
                }
            }
        }
    }
    int getNumberOfNodesEvaluated() override {
        return this->nodesEvaluated;
    }
};

#endif //OURSERVER_BFS_H
