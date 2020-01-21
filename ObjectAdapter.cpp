//
// Created by ortal on 14/01/2020.
//

#include "ObjectAdapter.h"
#include "BestFS.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"

string ObjectAdapter::solve(Matrix *problem) {

    // check all algorithm and choose the best one
    Searcher<vector<int>> *bestFs = new BestFS<vector<int>>();
    vector<State<vector<int>> *> s1 = bestFs->search(problem);
    Searcher<vector<int>> *dfs = new DFS<vector<int>>();
    vector<State<vector<int>> *> s2 = dfs->search(problem);
    Searcher<vector<int>> *bfs = new BFS<vector<int>>();
    vector<State<vector<int>> *> s3 = bfs->search(problem);
    Searcher<vector<int>>* astar = new AStar<vector<int>>();
    vector<State<vector<int>>*> s4 = astar->search(problem);
    cout << updateBackTrace(s1) << endl;
    cout << updateBackTrace(s2) << endl;
    cout << updateBackTrace(s3) << endl;
    cout << updateBackTrace(s4) << endl;
    // get the vector<Cell*> solution from the search method in the chosen algorithm
    int sum1 = costOfAll(s1);
    int sum2 = costOfAll(s1);
    int sum3 = costOfAll(s1);
    int sum4 = costOfAll(s1);
    if (sum1 <= sum2 && sum1 <= sum3 && sum1 <= sum4) {
        return updateBackTrace(s1);
    } else if (sum2 <= sum1 && sum2 <= sum3 && sum2 <= sum4) {
        return updateBackTrace(s2);
    } else if (sum3 <= sum2 && sum3 <= sum1 && sum3 <= sum4) {
        return updateBackTrace(s3);
    } else {
//        return updateBackTrace(s4);
    }
    //return this->updateBackTrace(solution);
}

int ObjectAdapter::costOfAll(vector<State<vector<int>> *> nodes) {
    int sum;
    for (int i = 0; i < nodes.size(); i++) {
        sum += nodes[i]->getCost();
    }
    return sum;
}

string ObjectAdapter::updateBackTrace(vector<State<vector<int>> *> path) {
    string trace = "";
    int cost = path[0]->getCost();
//    for (State<vector<int>>* cell : path) {
//        State<vector<int>>* father = cell->getCameFrom();
    for (int i = 1; i < path.size(); i++) {
        cost += path[i]->getCost();
        int x1 = path[i]->getState()[0];
        int y1 = path[i]->getState()[1];
        int x2 = path[i-1]->getState()[0];
        int y2 = path[i-1]->getState()[1];
        if (y1 > y2 && x1 == x2) {
            trace += "Right (";
        } else if (y1 < y2 && x1 == x2) {
            trace += "Left (";
        } else if (y1 == y2 && x1 < x2) {
            trace += "Up (";
        } else if (y1 == y2 && x1 > x2) {
            trace += "Down (";
        }
        trace += to_string(cost) + ")";
        if (i < path.size() -1) {
            trace += ", ";
        }
    }
    return trace;
}

//    string trace = "";
//    vector<State<vector<int>>*> path;
//    //int cost = 0;
//    while(goal->getCameFrom()!= nullptr) {
//        path.push_back(goal->getCameFrom());
//        goal=goal->getCameFrom();
//    }
//    for(State<vector<int>>* goal : path) {
//        State<vector<int>>* father = goal->getCameFrom();
//        //cost += goal->getCost();
//        if (father != nullptr) {
//            int x1 = father->getState()[0];
//            int y1 = father->getState()[1];
//            int x2 = goal->getState()[0];
//            int y2 = goal->getState()[1];
//            if (y1 > y2 && x1 == x2) {
//                trace += "Right (";
//            } else if (y1 < y2 && x1 == x2) {
//                trace += "Left (";
//            } else if (y1 == y2 && x1 < x2) {
//                trace += "Up (";
//            } else if (y1 == y2 && x1 > x2) {
//                trace += "Down (";
//            }
//            trace += to_string(goal->getCost()) + "), ";
//        }
//    }
//    //return the path]!
//    return trace;