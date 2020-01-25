
#include "ObjectAdapter.h"

string ObjectAdapter::solve(Matrix *problem) {
    // use winning algorithm
    Searcher<vector<int>> *bestFs = new BestFS<vector<int>>();
    vector<State<vector<int>> *> s = bestFs->search(problem);
    return updateBackTrace(s);
    /*
    // check all algorithm and choose the best one
    Searcher<vector<int>> *bestFs = new BestFS<vector<int>>();
    vector<State<vector<int>> *> s1 = bestFs->search(problem);
    Searcher<vector<int>> *dfs = new DFS<vector<int>>();
    vector<State<vector<int>> *> s2 = dfs->search(problem);
    Searcher<vector<int>> *bfs = new BFS<vector<int>>();
    vector<State<vector<int>> *> s3 = bfs->search(problem);
    Searcher<vector<int>>* astar = new AStar<vector<int>>();
    vector<State<vector<int>>*> s4 = astar->search(problem);
    string a1 = updateBackTrace(s1);
    string a2 = updateBackTrace(s2);
    string a3 = updateBackTrace(s3);
    string a4 = updateBackTrace(s4);
    cout << a1 << "\n bestFS num of nodes: " << bestFs->getNumberOfNodesEvaluated() << endl;
    cout << a2 << "\n DFS num of nodes: " << dfs->getNumberOfNodesEvaluated() << endl;
    cout << a3 << "\n BFS num of nodes: " << bfs->getNumberOfNodesEvaluated() << endl;
    cout << a4 << "\n Astar num of nodes: " << astar->getNumberOfNodesEvaluated() << endl;
    // get the vector<Cell*> solution from the search method in the chosen algorithm
    int sum1 = costOfAll(s1);
    int sum2 = costOfAll(s2);
    int sum3 = costOfAll(s3);
    int sum4 = costOfAll(s4);
    if (sum1 <= sum2 && sum1 <= sum3 && sum1 <= sum4) {
        return a1;
    } else if (sum2 <= sum1 && sum2 <= sum3 && sum2 <= sum4) {
        return a2;
    } else if (sum3 <= sum2 && sum3 <= sum1 && sum3 <= sum4) {
        return a3;
    } else {
        return a4;
    }
     */
}

int ObjectAdapter::costOfAll(vector<State<vector<int>> *> nodes) {
    int sum, size = nodes.size();
    for (int i = 0; i < size; i++) {
        sum += nodes[i]->getCost();
    }
    return sum;
}

string ObjectAdapter::updateBackTrace(vector<State<vector<int>> *> path) {
    string trace = "";
    int cost = path[0]->getCost();
    int size = path.size();
    for (int i = 1; i < size; i++) {
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
        // if it's not the last one
        if (i < size -1) {
            trace += ", ";
        }
    }
    return trace;
}

ObjectAdapter* ObjectAdapter::clone(){
    return new ObjectAdapter();
}

