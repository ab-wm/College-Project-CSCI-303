#include <iostream>
#include <Lib.h>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Variables
    //double logN, logTimeA, logTimeB, logTimeC, timeA, timeB, timeC;
    auto t1 = chrono::steady_clock::now();
    auto t2 = chrono::steady_clock::now();
    // Prep console output
    cout << "n, TA(n), TB(n), TC(n), log(n), log(TA), log(TB), log(TC)" << endl;

    // Algorithm processing
    for (int n = 100; n <= 3000; n += 100) {
         // Calculate times
        t1 = chrono::steady_clock::now();
        Lib::algorithmA(n);
        t2 = chrono::steady_clock::now();
        const double timeA = chrono::duration<double, milli>(t2 - t1).count();
        t1 = chrono::steady_clock::now();
        Lib::algorithmB(n);
        t2 = chrono::steady_clock::now();
        const double timeB = chrono::duration<double, milli>(t2 - t1).count();
        t1 = chrono::steady_clock::now();
        Lib::algorithmC(n);
        t2 = chrono::steady_clock::now();
        const double timeC = chrono::duration<double, milli>(t2 - t1).count();

        // Perform log calculations
        const double logN = log2(n);
        const double logTimeA = log2(timeA);
        const double logTimeB = log2(timeB);
        const double logTimeC = log2(timeC);

        // Output values
        cout << n << ", " << timeA << ", " << timeB << ", " << timeC << ", " <<
            logN << ", " << logTimeA << ", " << logTimeB << ", " << logTimeC << endl;

    }

    return 0;
}
