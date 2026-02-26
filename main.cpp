#include <iostream>
#include "include/cube.h"
#include "include/solver.h"

using namespace std;


int main() {

    cout<<"=========================\n";
    cout<<" RUBIK'S CUBE SOLVER\n";
    cout<<"=========================\n\n";

    Cube cube;

    cube.scramble(3);

    Solver solver;

    string solution = solver.bfsSolve(cube);

    cout<<"\nSolution: "<<solution<<endl;

    cube.applyAlgorithm(solution);

    if(cube.isSolved())
        cout<<"\nStatus: SOLVED \n";
    else
        cout<<"\nStatus: FAILED \n";

    return 0;
}