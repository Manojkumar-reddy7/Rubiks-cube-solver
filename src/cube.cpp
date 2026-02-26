#include "../include/cube.h"
#include <iostream>

using namespace std;

// Constructor
Cube::Cube() {
    faces.resize(6, vector<int>(9));

    // Create solved cube
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 9; j++) {
            faces[i][j] = i;
        }
    }
}

// Display cube
void Cube::display() {
    for(int i = 0; i < 6; i++) {
        cout << "Face " << i << ": ";
        for(int j = 0; j < 9; j++) {
            cout << faces[i][j] << " ";
        }
        cout << endl;
    }
}

void Cube::moveR() {

    // rotate right face clockwise
    vector<int> temp = faces[1];

    faces[1][0] = temp[6];
    faces[1][1] = temp[3];
    faces[1][2] = temp[0];
    faces[1][3] = temp[7];
    faces[1][4] = temp[4];
    faces[1][5] = temp[1];
    faces[1][6] = temp[8];
    faces[1][7] = temp[5];
    faces[1][8] = temp[2];

    cout << "R move executed\n";
}