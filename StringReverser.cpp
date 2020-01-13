//
// Created by ortal on 12/01/2020.
//

#include "StringReverser.h"



string StringReverser::solve (string problem) {
    reverse(problem.begin(),problem.end());
    return problem;
}