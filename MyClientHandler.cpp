
#include "MyClientHandler.h"

void MyClientHandler::handleClient(int client_socket) {
    int valRead = 0;
    string  data = "";
    while (valRead != -1) {
        char buffer[1024] = {0};
        valRead = read(client_socket, buffer, 1024);
        string s = buffer;
        s = s.substr(0,valRead);
        data += s + "\n";
        if(!s.find("end")){
            break;
        }
    }
    deque<string> lines;
    char *line = strtok(strdup(data.c_str()), "\n");
    while(line != nullptr){
        lines.push_back(line);
        line = strtok(NULL, "\n");
    }
    hash<string> key_hash;
    string key = to_string(key_hash(data));
    // remove "end"
    lines.pop_back();
    string solution = "";
    if (this->cm->inCache(key)){
        solution = this->cm->get(key);
    } else {
        Matrix* matrix = this->createMatrix(lines);
        solution = this->solver->solve(matrix);
        this->cm->insert(key, solution);
    }
    int sent = send(client_socket, solution.c_str(), strlen(solution.c_str()),0);
    if (sent == -1) {
        cout<< "Error sending" <<endl;
    }
}

Matrix *MyClientHandler::createMatrix(deque<string> lines) {
    // goal
    string goal = lines.back();
    lines.pop_back();
    char *goalI = strtok(strdup(goal.c_str()), ", ");
    char *goalJ = strtok(NULL, ", ");
    // initial
    string initial = lines.back();
    lines.pop_back();
    char *initialI = strtok(strdup(initial.c_str()), ", ");
    char *initialJ = strtok(NULL, ", ");
    int matrixSize = lines.size();
    Matrix *matrix = new Matrix(matrixSize);
    // states
    int i, j;
    vector<vector<Cell *>> rows;
    for (i = 0; i < matrixSize; i++) {
        string row = lines[i];
        char *cost = strtok(strdup(row.c_str()), ", ");
        vector<Cell *> column;
        for (j = 0; j < matrixSize; j++) {
            vector<int> state;
            state.push_back(i);
            state.push_back(j);
            Cell *cell = new Cell(state);
            cell->setCost(atoi(cost));
            column.push_back(cell);
            // if its's initial state
            if (atoi(initialI) == i && atoi(initialJ) == j) {
                cell->setCameFrom(nullptr);
                matrix->setInitial(cell);
            }
            // if its's goal state
            if (atoi(goalI) == i && atoi(goalJ) == j) {
                matrix->setGoal(cell);
            }
            cost = strtok(NULL, ", ");
        }
        rows.push_back(column);
    }
    matrix->setMatrix(rows);
    return matrix;
}

MyClientHandler* MyClientHandler::clone(){
    return new MyClientHandler(this->solver->clone(), this->cm);
}