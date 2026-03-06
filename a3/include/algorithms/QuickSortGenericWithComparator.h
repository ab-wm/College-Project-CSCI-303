#ifndef QUICKSORTGENERICWITHCOMPARATOR_H
#define QUICKSORTGENERICWITHCOMPARATOR_H

#include <vector>
#include <comparator/Comparator.h>

using namespace std;

template <class Comparable>
class QuickSortGenericWithComparator {
private:
    // Array of objects
    vector<Comparable> array;
    // Algorithm for sorting
    void quicksort(int left, int right, Comparator<Comparable> *comparator);
    // Method for checking for equality between values
    bool equals(Comparable a, Comparable b, Comparator<Comparable> *comparator);
    // Method to find the median
    int findMedian(const int& left, const int& right, Comparator<Comparable> *comparator);
public:
    // Constructor
    explicit QuickSortGenericWithComparator(vector<Comparable> inputArray);
    // Method for sorting
    vector<Comparable> sort(Comparator<Comparable> *comparator);
};



#endif //QUICKSORTGENERICWITHCOMPARATOR_H
