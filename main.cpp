
#ifndef OURSERVER_MAIN1_H
#define OURSERVER_MAIN1_H

#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#include "Main.h"

bool time_out = false;

using namespace boot;
void createMatrix(deque<string> lines);

int main(int argc, char *argv[])
{
    Main main1;
//    main1.main(argc,argv);
    // not needed
    cout<<"ok"<<endl;
    deque<string> lines;
    lines.push_back("8,2,8,6,5");
    lines.push_back("8,3 ,8, 6,-1");
    lines.push_back(" 18,3 ,4, -1, -1");
    lines.push_back("2, 13, 8, 4, -1");
    lines.push_back(" 12 , 31 , 0 , 6 , -1 ");
    lines.push_back("0, 0");
    lines.push_back("36,36");
    createMatrix(lines);
    return 0;
}

void createMatrix(deque<string> lines) {
    // goal
    string goal = lines.back();
    lines.pop_back();
    char* goalI = strtok(strdup(goal.c_str()), ", ");
    char* goalJ = strtok(NULL, ", ");
    vector<int> goals;
    goals.push_back(atoi(goalI));
    goals.push_back(atoi(goalJ));
    // initial
    string initial = lines.back();
    lines.pop_back();
    char* initialI = strtok(strdup(initial.c_str()), ", ");
    char* initialJ = strtok(NULL, ", ");
    vector<int> initials;
    initials.push_back(atoi(initialI));
    initials.push_back(atoi(initialJ));
    int matrixSize = lines.size();
    int i;
    int j;
    for (i = 0; i < matrixSize; i++) {
        string row = lines[i];
        char* token = strtok(strdup(row.c_str()), ", ");
        for (j = 0; j < matrixSize; j++) {
            vector<int> state;
            state.push_back(i);
            state.push_back(j);
            cout<<token<<" ";
            token = strtok(NULL, ", ");
        }
    }
    j;
}

#endif //OURSERVER_MAIN1_H

