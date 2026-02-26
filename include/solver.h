#ifndef SOLVER_H
#define SOLVER_H

#include "cube.h"
#include <string>

using namespace std;

class Solver {
public:
    string bfsSolve(Cube start);
    string idaSolve(Cube start);
};

#endif