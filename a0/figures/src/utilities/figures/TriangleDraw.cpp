#include <iostream>
#include "utilities/figures/TriangleDraw.h"
#include "utilities/exception/ExceptionCheck.h"
using namespace std;
void TriangleDraw::Draw(const short int &n) {
    if(ExceptionCheck().signTest(n)) {
        cout << "The triangle:" << endl;
        /***Drawing the top row***/
        cout << string(n,'*') << endl;

        /***Drawing the bottom tip***/
        // Variables
        short int spaceCount = 1;
        short int starCount = n-2;
        // Loop to create the lower tip of the diamond. Starts one below the thickest
        // Note n values 1 and 2 will not trigger the loop due to starCount initialization
        for (; starCount >= 1; starCount -= 2) {
            cout << string(spaceCount,' ');
            cout << string(starCount,'*') << endl;
            spaceCount++; //Increase space by one for each layer
        }
    }
}