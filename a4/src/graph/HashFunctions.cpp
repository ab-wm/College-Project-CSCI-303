//
// Created by ojcch on 3/23/2020.
//

#include "graph/HashFunctions.h"

long long HashFunctions::universalHashInt(int k, int a, int b, int p, int M) {
    int y = a * k + b;
    long long r = y % p;
    return r % M;
}

long long HashFunctions::universalHashIntEfficient(int k, int a, int b, int M, int i) {
    int p = (1 << i) - 1;
    int y = a * k + b;

    int quotient = y >> i;
    int reminder = y & p;
    int r = quotient + reminder;
    if (r >= p) r -= p; //this scaling is required
    return r % M;
}

long HashFunctions::hashString(const string &s) {
    long hash = 0;
    for (char w : s) {
        hash = (R * hash + w) % M;
    }
    return hash;
}

long HashFunctions::hashInt(int i) {
    return i % M;
}
