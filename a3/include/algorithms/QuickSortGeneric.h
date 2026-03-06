
#ifndef SORTING_QUICKSORTGENERIC_H
#define SORTING_QUICKSORTGENERIC_H

#include <vector>
using namespace std;

template <class Comparable>
class QuickSortGeneric {
    private:
      // Array of objects
      vector<Comparable> array;
      // Algorithm for sorting
      void quicksort(int left, int right);
      // Method for checking for equality between values
      bool equals(Comparable a, Comparable b);
      // Method to find the median
      int findMedian(const int& left, const int& right);

    public:
      // Constructor
      explicit QuickSortGeneric(vector<Comparable> inputArray);
      // Method for sorting
      vector<Comparable> sort();
};


#endif //SORTING_QUICKSORTGENERIC_H
