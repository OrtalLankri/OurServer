//
// Created by ortal on 14/01/2020.
//

#include "MyClientHandler.h"

void MyClientHandler::handleClient(int client_socket) {
    int valRead = 0;
    while (valRead != -1){
        char line[100000] = {0};
        valRead = read(client_socket, line, 100000);
        deque<string> lines;
        string key = "";
        while(line != "end") {
            lines.push_back(line);
            key += line;
        }
        string solution;
        if (this->cm->inCache(key)){
            solution = this->cm->get(key);
        } else {
            Matrix* matrix = this->createMatrix(lines);
            solution = this->solver->solve(matrix);
            this->cm->insert(key, solution);
        }
        send(client_socket, solution.c_str(), strlen(solution.c_str()),0);
    }
}

Matrix* MyClientHandler::createMatrix(deque<string> lines) {
    Matrix matrix;
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
    matrix.setStates(new Cell(initials), new Cell(goals));
    // states
    int matrixSize = lines.size();
    matrix.setSize(matrixSize);
    int i;
    int j;
    for (i = 0; i < matrixSize; i++) {
        string row = lines[i];
        char* token = strtok(strdup(row.c_str()), ", ");
        for (j = 0; j < matrixSize; j++) {
            vector<int> state;
            state.push_back(i);
            state.push_back(j);
            Cell* cell = new Cell(state);
            cell->setCost(atoi(token));
            token = strtok(NULL, ", ");
        }
    }
    return &matrix;
}
