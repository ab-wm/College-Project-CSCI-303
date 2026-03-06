#ifndef MERGESORTGENERICWITHCOMPARATOR_H
#define MERGESORTGENERICWITHCOMPARATOR_H

#include <vector>
#include <comparator/Comparator.h>

using namespace std;

template<class Comparable>
class MergeSortGenericWithComparator {

private:
    vector<Comparable> array;

    void mergeSort(vector<Comparable> &temp, int left, int right, Comparator<Comparable> *comparator) ;
public:

    explicit MergeSortGenericWithComparator(vector<Comparable> inputArray) ;

    vector<Comparable> sort(Comparator<Comparable> *comparator) ;

};



#endif //MERGESORTGENERICWITHCOMPARATOR_H
