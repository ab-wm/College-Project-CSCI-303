

#include <algorithms/QuickSortGeneric.h>
#include <entity/Coordinate.h>
#include <entity/MailingAddress.h>

using namespace std;

///// Constructor
template <class Comparable>
QuickSortGeneric<Comparable>::QuickSortGeneric(vector<Comparable> inputArray) {
  this->array = std::move(inputArray);
}

///// Public method for sorting
template <class Comparable>
vector<Comparable> QuickSortGeneric<Comparable>::sort() {
    // Sort the array
    quicksort(0, array.size() - 1);
    // Return the array
    return array;
}

///// Quicksort sorting algorithm
template <class Comparable>
void QuickSortGeneric<Comparable>::quicksort(int left, int right) {
    ///// Variables
    int pivotIndex;
    Comparable pivotValue;
    Comparable indiceSwap; // For the swapping of values between the indices
    int i = left;
    int j = right - 1;

    ///// Return on partitions too small
    if (left > right)
        return;

    ///// Find the median
    pivotIndex = findMedian(left, right);

    // Swap rightmost element with the median
    pivotValue = array[pivotIndex];
    array[pivotIndex] = array[right];
    array[right] = pivotValue;

    ///// Swap elements according to quicksort algortihm
    /// i always points to an element >= pivot
    /// j always points to an element <= pivot
    // Initial search for elements
    while (i < j && array[i] < pivotValue)
        i++;
    while (i < j && pivotValue < array[j])
        j--;
    // Perform the swapping and search for the next valid set of elements
    while (i < j) {
        indiceSwap = array[i];
        array[i] = array[j];
        array[j] = indiceSwap;
        while (i < j && array[i] < pivotValue) // If shifted values are not valid
            i++;
        while (i < j && pivotValue < array[j])
            j--;
    }
    // Swap the pivot with the location of i
    array[right] = array[i];
    array[i] = pivotValue;

    ///// Partitioning and recursive calls
    /// Partitions on the sides of i
    quicksort(left, i - 1);
    quicksort(i + 1, right);
}

// Method to check if two comparables are equal
template<class Comparable>
bool QuickSortGeneric<Comparable>::equals(Comparable a, Comparable b) {
    return !(a < b) && a <= b;
}

// Method to find the median
template<class Comparable>
int QuickSortGeneric<Comparable>::findMedian(const int& left, const int& right) {
    ///// Find the middle element
    int middleIndex = left + (right - left - 1)/2;

    ///// Find the median of the array
    if (equals(array[left],array[middleIndex]) && equals(array[middleIndex],array[right])) return middleIndex; // All equal

    if (equals(array[left],array[middleIndex]) && array[middleIndex] < array[right]) return middleIndex; // Left two are equal and smaller
    if (equals(array[left],array[middleIndex]) && array[right] < array[middleIndex] ) return right; // Left two are equal and bigger
    if (array[middleIndex] < array[left]  && equals(array[middleIndex],array[right])) return middleIndex; // Right two are equal and smaller
    if (array[left] < array[middleIndex] && equals(array[middleIndex],array[right])) return left; // Right two are equal and greater
    if (equals(array[left],array[right]) && array[middleIndex] < array[left]) return middleIndex; // Sides are equal, a = c, > b
    if (equals(array[left],array[right]) && array[left] < array[middleIndex]) return left; // a = c, < b

    if (array[left] < array[middleIndex] && array[middleIndex] < array[right]) return middleIndex; // Middle is the median, a < b < c
    if (array[right] < array[middleIndex] && array[middleIndex] < array[left]) return middleIndex; // a > b > c
    if (array[middleIndex] < array[left] && array[left] < array[right]) return left; // Left is the median, b < a < c
    if (array[left] < array[middleIndex] && array[right] < array[left]) return left; // b > a > c
    return right; // Right is the median
}



template class QuickSortGeneric<int>;
template class QuickSortGeneric<Coordinate>;
template class QuickSortGeneric<MailingAddress>;
