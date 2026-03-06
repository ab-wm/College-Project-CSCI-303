//
// Created by ojcch on 3/23/2020.
//

#ifndef HASHING_HASHFUNCTIONS_H
#define HASHING_HASHFUNCTIONS_H

#include <string>

using namespace std;

/*
 * A set of hash functions for strings and integers
 */
class HashFunctions {
public:

    static const int M = 8191;
    static const int R = 31;

    static long long universalHashInt(int k, int a, int b, int p, int M);

    static long long universalHashIntEfficient(int k, int a, int b, int M, int i) ;

    static long hashString(const string &s) ;

    static long hashInt(int i);
};


#endif //HASHING_HASHFUNCTIONS_H
