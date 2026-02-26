#include <iostream>
#include "include/cube.h"
#include "include/solver.h"
#include <windows.h>
#include <sstream>
#include <chrono>

using namespace std;

void animateSolution(Cube &cube, string solution)
{
    stringstream ss(solution);
    string move;

    while(ss >> move)
    {
        cout << "\nApplying move: " << move << endl;

        cube.applyMove(move);

        cube.display();

        Sleep(800);
    }
}

int main() {

    cout<<"=========================\n";
    cout<<" RUBIK'S CUBE SOLVER\n";
    cout<<"=========================\n";

    Cube cube;
    Solver solver;

    int choice;

    cout<<"\n1. Random Scramble\n";
    cout<<"2. Enter Algorithm\n";
    cout<<"Choice: ";
    cin>>choice;

    if(choice==1) {

        int moves;
        cout<<"Number of scramble moves: ";
        cin>>moves;

        cube.scramble(moves);
        cout<<"\nScrambled Cube:";
        cube.display();
    }
    else {

        string algo;
        cin.ignore();

        cout<<"Enter moves (example: R U R' U'):\n";
        getline(cin,algo);

        cube.applyAlgorithm(algo);
    }

    cout<<"\nSolving...\n";
    auto start = std::chrono::high_resolution_clock::now();
    string solution = solver.idaSolve(cube);
    auto end = std::chrono::high_resolution_clock::now();
    cout<<"\nTime taken: "
    <<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    <<" ms\n";
    cout<<"\nSolution: "<<solution<<endl;
    animateSolution(cube, solution);
    cout<<"\nSolved Cube:";
    cube.display();

    if(cube.isSolved())
        cout<<"\nStatus: SOLVED \n";
    else
        cout<<"\nStatus: FAILED \n";

    return 0;
}