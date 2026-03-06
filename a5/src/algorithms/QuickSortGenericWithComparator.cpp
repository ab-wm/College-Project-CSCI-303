//
// Created by ojcch on 4/7/2020.
//



#include <algorithms/QuickSortGenericWithComparator.h>
#include <entity/Coordinate.h>

template <class Comparable>
QuickSortGenericWithComparator<Comparable>::QuickSortGenericWithComparator(vector<Comparable> inputArray,
                                                         Comparator<Comparable>* comparator) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
    this->comparator = comparator;
}

template <class Comparable>
vector<Comparable> QuickSortGenericWithComparator<Comparable>::sort() {
    //we call quick sort on the array
    quicksort(0, array.size() - 1);
    //we return the array
    return array;
}

template <class Comparable>
void QuickSortGenericWithComparator<Comparable>::quicksort(int left, int right) {

    if (left >= right) return; //base case

    //-----------------------------------------
    //pivot selection

    //find the pivot
    int pivotIdx = medianOfThree(left, right);
    Comparable pivot = array[pivotIdx];

    //swap the pivot and right elements
    swap(array[pivotIdx], array[right]);

    //-----------------------------------------
    //partitioning

    int i = left; // start in left
    int j = right - 1; //start in the previous element to the right one

    while (true) {

        //move i right until it points to an element greater than or equal to the pivot
        while (comparator->lessThan(array[i], pivot)) {
            i++;
        }

        //move j left until it points to an element lower than or equal to the pivot
        while (comparator->lessThan(pivot, array[j])) {
            j--;
        }

        if (i < j) { //i and j haven't crossed
            swap(array[i], array[j]); //swap the elements
            if (comparator->equals(array[i], array[j])) j--; //if both elements are equal, move j, otherwise we may have an infinite loop
        } else break; //i and j crossed so we are done partitioning

    }

    //swap back the pivot
    swap(array[i], array[right]);

    //---------------------------------
    //apply quicksort on both partitions recursively

    quicksort(left, i - 1);
    quicksort(i + 1, right);
}

template <class Comparable>
int QuickSortGenericWithComparator<Comparable>::medianOfThree(int left, int right) {
    int center = (left + right) / 2;
    int pivotIdx = center;

    //six possibilities:
    //(1) center <= left <= right
    //(2) center <= right <= left
    //(3) left <= center <= right
    //(4) left <= right <= center
    //(5) right <= left <= center
    //(6) right <= center <= left

    if (comparator->lessThanOrEqualTo(array[left], array[right])) {
        //(1), (3), (4)
        if (comparator->lessThanOrEqualTo(array[center] , array[left])) {
            //(1) center <= left <= right
            pivotIdx = left;
        } else if (comparator->lessThanOrEqualTo(array[right] , array[center])) {
            // (4) left <= right <= center
            pivotIdx = right;
        }
        //else: (3) left <= center <= right
    } else {
        //(2), (5), (6)
        if (comparator->lessThanOrEqualTo(array[center] ,array[right])) {
            //(2) center <= right <= left
            pivotIdx = right;
        } else if (comparator->lessThanOrEqualTo(array[right] ,array[left])) {
            //(5) right <= left <= center
            pivotIdx = left;
        }
        //else: (6) right <= center <= left
    }

    return pivotIdx;
}


template class QuickSortGenericWithComparator<int>;
template class QuickSortGenericWithComparator<Coordinate>;