#include <iostream>
#include "utilities/figures/ShearTriangleDraw.h"
#include "utilities/exception/ExceptionCheck.h"
using namespace std;
// Function to create the sheared triangle
// Created by Increasing indent and number of stars on each new line, n times
void ShearTriangleDraw::Draw(const short int &n) {
    if(ExceptionCheck().signTest(n)) {
        cout << "The sheared triangle:" << endl;
        for (short int count = 0; count < n; count ++) {
            cout << string(count,' ');
            cout << string(count+1,'*') << endl;
        }
    }
}
