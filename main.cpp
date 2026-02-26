#include <iostream>
#include "include/cube.h"

using namespace std;

int main() {

    Cube cube;

    cout<< "Before Move:\n";
    cube.display();

    cube.moveR();

    cout << "\nAfter R Move:\n";
    cube.display();

    return 0;
}