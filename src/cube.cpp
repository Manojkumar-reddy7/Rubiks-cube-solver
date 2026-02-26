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
    char colors[] = {'W','R','B','O','G','Y'};

    cout << "\n======== CUBE STATE ========\n";

    for(int i = 0; i < 6; i++) {

        cout << "Face " << i << ":\n";

        for(int j = 0; j < 9; j++) {

            cout << colors[faces[i][j]] << " ";

            if((j+1)%3==0)
                cout << endl;
        }

        cout << endl;
    }
}

void Cube::moveR() {

    vector<int> temp = faces[1];

    // rotate right face
    faces[1][0]=temp[6];
    faces[1][1]=temp[3];
    faces[1][2]=temp[0];
    faces[1][3]=temp[7];
    faces[1][4]=temp[4];
    faces[1][5]=temp[1];
    faces[1][6]=temp[8];
    faces[1][7]=temp[5];
    faces[1][8]=temp[2];

    // move adjacent columns
    int t1 = faces[0][2];
    int t2 = faces[0][5];
    int t3 = faces[0][8];

    faces[0][2] = faces[2][2];
    faces[0][5] = faces[2][5];
    faces[0][8] = faces[2][8];

    faces[2][2] = faces[5][2];
    faces[2][5] = faces[5][5];
    faces[2][8] = faces[5][8];

    faces[5][2] = faces[4][2];
    faces[5][5] = faces[4][5];
    faces[5][8] = faces[4][8];

    faces[4][2] = t1;
    faces[4][5] = t2;
    faces[4][8] = t3;

    //cout<<"R move executed\n";
}

void Cube::moveU() {

    // rotate Up face
    vector<int> temp = faces[0];

    faces[0][0]=temp[6];
    faces[0][1]=temp[3];
    faces[0][2]=temp[0];
    faces[0][3]=temp[7];
    faces[0][4]=temp[4];
    faces[0][5]=temp[1];
    faces[0][6]=temp[8];
    faces[0][7]=temp[5];
    faces[0][8]=temp[2];

    // move adjacent rows

    int t1 = faces[2][0];
    int t2 = faces[2][1];
    int t3 = faces[2][2];

    faces[2][0] = faces[1][0];
    faces[2][1] = faces[1][1];
    faces[2][2] = faces[1][2];

    faces[1][0] = faces[3][0];
    faces[1][1] = faces[3][1];
    faces[1][2] = faces[3][2];

    faces[3][0] = faces[4][0];
    faces[3][1] = faces[4][1];
    faces[3][2] = faces[4][2];

    faces[4][0] = t1;
    faces[4][1] = t2;
    faces[4][2] = t3;

    //cout<<"U move executed\n";
}

void Cube::applyMove(string move) {

     if(move == "R") moveR();
    else if(move == "R'") moveRPrime();

    else if(move == "U") moveU();
    else if(move == "U'") moveUPrime();

    else cout << "Unknown move\n";
}


#include <sstream>

void Cube::applyAlgorithm(string algorithm) {

    stringstream ss(algorithm);
    string move;

    while(ss >> move) {
        applyMove(move);
    }
}

#include <cstdlib>
#include <ctime>

void Cube::scramble(int moves) {

    string possibleMoves[] = {"R","R'","U","U'"};

    srand(time(0));
    lastScramble="";

    for(int i = 0; i < moves; i++) {

        string m=possibleMoves[rand()%4];
        applyMove(m);
        lastScramble += m+"";

    }

    cout <<"scrambled: "<<lastScramble<<endl;
}


bool Cube::isSolved() {

    for(int i = 0; i < 6; i++) {

        int color = faces[i][0];

        for(int j = 1; j < 9; j++) {
            if(faces[i][j] != color)
                return false;
        }
    }

    return true;
}


string Cube::getState() const {

    string state = "";

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 9; j++) {
            state += char('0' + faces[i][j]);
        }
    }

    return state;
}


void Cube::moveRPrime() {
    moveR();
    moveR();
    moveR();
}

void Cube::moveUPrime() {
    moveU();
    moveU();
    moveU();
}