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