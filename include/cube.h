#ifndef CUBE_H
#define CUBE_H

#include <vector>
using namespace std;

class Cube {
private:
    vector<vector<int>> faces;

public:
    Cube();        // constructor
    void display(); // show cube
};

#endif