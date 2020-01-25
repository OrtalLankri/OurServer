
#ifndef OURSERVER_OBJECTADAPTER_H
#define OURSERVER_OBJECTADAPTER_H

#include "Solver.h"
#include "State.h"
#include "Cell.h"
#include "Matrix.h"
#include "BestFS.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"
#include <string>
#include <vector>

using namespace std;

class ObjectAdapter : public Solver<Matrix*, string> {
    string updateBackTrace(vector<State<vector<int>>*> path);
public:
    string solve(Matrix* problem) override;
    int costOfAll(vector<State<vector<int>>*> nodes);
    ObjectAdapter* clone() override;
};

#endif //OURSERVER_OBJECTADAPTER_H
