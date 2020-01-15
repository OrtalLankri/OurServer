//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_OBJECTADAPTER_H
#define OURSERVER_OBJECTADAPTER_H

#include "Solver.h"
#include "State.h"
#include "Cell.h"
#include <string>
#include <vector>

using namespace std;

class ObjectAdapter : public Solver<string, vector<Cell*>> {
    string updateBackTrace(vector<Cell*> s){
        string trace="";
        int cost=0;
    for(int i=0;i<s.size();i++){
        Cell* father = s[i]->getCameFrom();
        int x1 = father->getState()[0];
        int y1 = father->getState()[1];
        int x2 = s[i]->getState()[0];
        int y2 = s[i]->getState()[1];
        cost += s[i]->getCost();
        if(y1>y2 && x1 == x2){
            trace+="Right(";
        } else if(y1<y2 && x1==x2) {
            trace+="Left(";
        } else if(y1==y2 && x1<x2){
            trace+="Up(";
        }else if(y1==y2 && x1>x2){
            trace+="Down(";
        }
        trace += to_string(cost) + ") ";
    }
        return trace;
    }

};


#endif //OURSERVER_OBJECTADAPTER_H
