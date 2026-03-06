# include <algorithms/QuickSortGenericWithComparator.h>
# include <entity/Coordinate.h>
# include <entity/MailingAddress.h>

using namespace std;

///// Constructor
template <class Comparable>
QuickSortGenericWithComparator<Comparable>::QuickSortGenericWithComparator(vector<Comparable> inputArray) {
  this->array = std::move(inputArray);
}

///// Public method for sorting
template <class Comparable>
vector<Comparable> QuickSortGenericWithComparator<Comparable>::sort(Comparator<Comparable> *comparator) {
    // Sort the array
    quicksort(0, array.size() - 1, comparator);
    // Return the array
    return array;
}

///// Quicksort sorting algorithm
template <class Comparable>
void QuickSortGenericWithComparator<Comparable>::quicksort(int left, int right, Comparator<Comparable> *comparator) {
    ///// Variables
    int pivotIndex;
    Comparable pivotValue;
    Comparable indiceSwap; // For the swapping of values between the indices
    int i = left;
    int j = right - 1;

    ///// Return on partitions too small
    if (right == left || left > right)
        return;

    ///// Find the median of the array
    pivotIndex = findMedian(left, right, comparator);
    // Swap
    pivotValue = array[pivotIndex];
    array[pivotIndex] = array[right];
    array[right] = pivotValue;

    ///// Swap elements according to quicksort algortihm
    /// i always points to an element >= pivot
    /// j always points to an element <= pivot
    // Initial search for elements
    while (comparator->lessThan(array[i],pivotValue))
        i++;
    while (!comparator->lessThanOrEqualTo(array[j],pivotValue))
        j--;
    // Perform the swapping and search for the next valid set of elements
    while (i < j) {
        indiceSwap = array[i];
        array[i] = array[j];
        array[j] = indiceSwap;
        while (comparator->lessThan(array[i],pivotValue)) // If shifted values are not valid
            i++;
        while (!comparator->lessThanOrEqualTo(array[j],pivotValue))
            j--;
    }
    // Swap the pivot with the location of i
    array[right] = array[i];
    array[i] = pivotValue;

    ///// Partitioning and recursive calls
    /// Partitions on the sides of i
    quicksort(left, i - 1, comparator);
    quicksort(i + 1, right, comparator);
}
// Method to check if two comparables are equal
template<class Comparable>
bool QuickSortGenericWithComparator<Comparable>::equals(Comparable a, Comparable b, Comparator<Comparable> *comparator) {
    return !comparator->lessThan(a, b) && comparator->lessThanOrEqualTo(a ,b);
}

// Method to find the median
template<class Comparable>
int QuickSortGenericWithComparator<Comparable>::findMedian(const int& left, const int& right, Comparator<Comparable> *comparator) {
    ///// Find the middle element
    int middleIndex = left + (right - left - 1)/2;

    ///// Find the median of the array
    if (equals(array[left],array[middleIndex],comparator) && equals(array[middleIndex],array[right],comparator)) return middleIndex; // All equal

    if (equals(array[left],array[middleIndex],comparator) && comparator->lessThan(array[middleIndex], array[right])) return middleIndex; // Left two are equal and smaller
    if (equals(array[left],array[middleIndex],comparator) && comparator->lessThan(array[right],array[middleIndex]) ) return right; // Left two are equal and bigger
    if (comparator->lessThan(array[middleIndex] ,array[left])  && equals(array[middleIndex],array[right],comparator)) return middleIndex; // Right two are equal and smaller
    if (comparator->lessThan(array[left] ,array[middleIndex]) && equals(array[middleIndex],array[right],comparator)) return left; // Right two are equal and greater
    if (equals(array[left],array[right],comparator) && comparator->lessThan(array[middleIndex],array[left])) return middleIndex; // Sides are equal, a = c, > b
    if (equals(array[left],array[right],comparator) && comparator->lessThan(array[left],array[middleIndex])) return left; // a = c, < b

    if (comparator->lessThan(array[left],array[middleIndex]) && comparator->lessThan(array[middleIndex],array[right])) return middleIndex; // Middle is the median, a < b < c
    if (comparator->lessThan(array[right],array[middleIndex]) && comparator->lessThan(array[middleIndex],array[left])) return middleIndex; // a > b > c
    if (comparator->lessThan(array[middleIndex],array[left]) && comparator->lessThan(array[left],array[right])) return left; // Left is the median, b < a < c
    if (comparator->lessThan(array[left],array[middleIndex]) && comparator->lessThan(array[right],array[left])) return left; // b > a > c
    return right; // Right is the median
}

template class QuickSortGenericWithComparator<int>;
template class QuickSortGenericWithComparator<Coordinate>;
template class QuickSortGenericWithComparator<MailingAddress>;

