//
// Created by ojcch on 4/7/2020.
//



#include <algorithms/QuickSortIntegers.h>

QuickSortIntegers::QuickSortIntegers(vector<int> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

vector<int> QuickSortIntegers::sort() {
    //we call quick sort on the array
    quicksort(0, array.size() - 1);
    //we return the array
    return array;
}

void QuickSortIntegers::quicksort(int left, int right) {
    //IMPLEMENT THE ALGORITHM HERE
    ///// Variables
    int pivotIndex;
    int pivotValue;
    int indiceSwap; // For the swapping of values between the indices
    int i = left;
    int j = right - 1;

    ///// Return on partitions too small
    if (right == left || left > right)
        return;

    // Find the median
    pivotIndex = findMedian(left, right);
    // Swap
    pivotValue = array[pivotIndex];
    array[pivotIndex] = array[right];
    array[right] = pivotValue;

    ///// Swap elements according to quicksort algortihm
    /// i always points to an element >= pivot
    /// j always points to an element <= pivot
    // Initial search for elements
    while (array[i] < pivotValue)
        i++;
    while (array[j] > pivotValue)
        j--;
    // Perform the swapping and search for the next valid set of elements
    while (i < j) {
        indiceSwap = array[i];
        array[i] = array[j];
        array[j] = indiceSwap;
        while (array[i] < pivotValue) // If shifted values are not valid
            i++;
        while (array[j] > pivotValue)
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

// Method to find the median
int QuickSortIntegers::findMedian(const int& left, const int& right) {
    ///// Find the middle element
    int middleIndex = left + (right - left - 1)/2;

    ///// Find the median of the array
    if (array[left] == array[middleIndex] && array[middleIndex] == array[right]) return middleIndex; // All equal

    if (array[left] == array[middleIndex] && array[middleIndex] < array[right]) return middleIndex; // Left two are equal and smaller
    if (array[left] == array[middleIndex] && array[right] < array[middleIndex] ) return right; // Left two are equal and bigger
    if (array[middleIndex] < array[left]  && array[middleIndex] == array[right]) return middleIndex; // Right two are equal and smaller
    if (array[left] < array[middleIndex] && array[middleIndex] == array[right]) return left; // Right two are equal and greater
    if (array[left] == array[right] && array[middleIndex] < array[left]) return middleIndex; // Sides are equal, a = c, > b
    if (array[left] == array[right] && array[left] < array[middleIndex]) return left; // a = c, < b

    if (array[left] < array[middleIndex] && array[middleIndex] < array[right]) return middleIndex; // Middle is the median, a < b < c
    if (array[right] < array[middleIndex] && array[middleIndex] < array[left]) return middleIndex; // a > b > c
    if (array[middleIndex] < array[left] && array[left] < array[right]) return left; // Left is the median, b < a < c
    if (array[left] < array[middleIndex] && array[right] < array[left]) return left; // b > a > c
    return right; // Right is the median
}