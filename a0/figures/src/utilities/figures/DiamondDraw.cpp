#include <iostream>
#include <cmath>
#include "utilities/figures/DiamondDraw.h"
#include "utilities/exception/ExceptionCheck.h"
using namespace std;
// Function to create the diamond
void DiamondDraw::Draw (const short int &n) {
    if(ExceptionCheck().signTest(n)) {
        cout << "The diamond:" << endl;
        /***Draw upper half***/
        // Variables
        short int starCount = n % 2 == 0 ? 2 : 1; //Even = 2 stars : Odd = 1 star at the top
        short int spaceCount; //No space for 1 or 2 stars
        if (n > 2) {
            spaceCount = static_cast<short int>((round(n/2.0))-1.0);
        } else {
            spaceCount = 0;
        }
        //Loop to generate the shape. Stops when space becomes 0/before the complete star line
        for (; spaceCount >= 1; spaceCount-- ) {
            cout << string(spaceCount,' ');
            cout << string(starCount,'*') << endl;
            starCount+=2; //Increase stars by two in each level
        }

        /***Draw middle "base"***/
        cout << string(n,'*') << endl;

        /***Draw lower half***/
        // Variables reset
        spaceCount = 1;
        starCount = n-2;
        // Loop to create the lower tip of the diamond. Starts one below the thickest
        // Note: n values 1 and 2 will not trigger the loop due to starCount initialization
        for (; starCount >= 1; starCount -= 2) {
            cout << string(spaceCount,' ');
            cout << string(starCount,'*') << endl;
            spaceCount++; //Increase space by one for each layer
        }
    }
}
