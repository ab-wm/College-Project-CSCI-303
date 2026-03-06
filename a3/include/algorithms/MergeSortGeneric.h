
#ifndef MERGESORTGENERIC_H
#define MERGESORTGENERIC_H

#include <vector>

using namespace std;

template<class Comparable>
class MergeSortGeneric {

private:
    vector<Comparable> array;

    void mergeSort(vector<Comparable> &temp, int left, int right) ;
public:

    explicit MergeSortGeneric(vector<Comparable> inputArray) ;

    vector<Comparable> sort() ;

};


#endif //MERGESORTGENERIC_H
