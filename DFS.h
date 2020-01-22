
#ifndef OURSERVER_DFS_H
#define OURSERVER_DFS_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

template <class T>
class DFS : public Searcher<T> {
    int nodesEvaluated;
public:
    vector<State<T>*> search(Searchable<T>* s) override {
        map<State<T>*, vector<State<T>*>> paths;
        stack<State<T>*> openList;
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
            State<T>* v = openList.top();
            openList.pop();
            // if v is goal state, return its path
            if (s->isGoalState(v)) {
                vector<State<T>*> p = paths[v];
                p.push_back(v);
                return p;
            }
            // for each adjacent of v
            vector<State<T>*> successors = s->getAllStates(v);
            for (State<T>* adj : successors) {
                // if adjacent has not been visited before
                if (find(visited.begin(), visited.end(), adj) == visited.end()) {
                    visited.push_back(adj);
                    openList.push(adj);
//                    adj->setCameFrom(v);
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

#endif //OURSERVER_DFS_H


//    S search(Searchable<T>* s) {
//        int V = s->getSize();
//        bool visited[V];
//        for (int i = 0; i < V; i++) {
//            visited[i] = false;
//        }
//        return Dfs(s, s->getInitialState(), visited);
//    }

//    S Dfs(Searchable<T>* s, State<T>* v, bool visited[]) {
//        visited[v] = true;
//        // mark
//        vector<State<T>*> adj = s->getAllStates(v);
//        for (State<T>* state : adj) {
//            if (!visited[state]) {
//                Dfs(state, visited);
//            }
//        }
//    }