#include <string>
#include "utilities/figures/TriangleDraw.h"
#include "utilities/figures/DiamondDraw.h"
#include "utilities/figures/ShearTriangleDraw.h"
using namespace std;
int main(int argc, char *argv[]) {

    //Variable n, char to integer
    short int n = stoi(argv[1]);

    //Draw the Figures
    TriangleDraw().Draw(n);
    DiamondDraw().Draw(n);;
    ShearTriangleDraw().Draw(n);

    return 0;
}

