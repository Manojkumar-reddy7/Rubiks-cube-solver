#ifndef CUBE_H
#define CUBE_H


#include <vector>
#include <string>
using namespace std;

class Cube {
private:
    vector<vector<int>> faces;

public:
    Cube();        // constructor
    void display();  // show cube

    void moveR();
    void moveRPrime();
    
    void moveU();
    void moveUPrime();

    void applyMove(string move);
    void applyAlgorithm(string algorithm);
    void scramble(int moves);

    bool isSolved();
    bool operator==(const Cube& other) const;
    
    string getState() const;
    string lastScramble;

};

#endif