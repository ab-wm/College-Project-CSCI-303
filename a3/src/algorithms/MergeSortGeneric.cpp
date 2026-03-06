#include <utility>
#include <vector>
#include <algorithms/MergeSortGeneric.h>
#include <entity/Coordinate.h>
#include <entity/MailingAddress.h>

template<class Comparable>
MergeSortGeneric<Comparable>::MergeSortGeneric(vector<Comparable> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

template<class Comparable>
vector<Comparable> MergeSortGeneric<Comparable>::sort() {
    //we create the temporary array for merging
    vector<Comparable> temp = vector<Comparable>(this->array.size());
    //we call merge sort on the entire array
    mergeSort(temp, 0, array.size() - 1);
    //return temp, which contains the sorted array
    return temp;
}

template<class Comparable>
void MergeSortGeneric<Comparable>::mergeSort(vector<Comparable> &temp, int left, int right) {
    //IMPLEMENT THE ALGORITHM HERE
    if (left < right) { //Stop when the indexes represent 1/0 cell vector
        const int middle = (left + right) / 2;
        mergeSort(temp, left, middle);
        mergeSort(temp, middle + 1, right);
        // Merge algorithm
        const int numElements = right - left + 1;
        const int rightIndexofFirst = middle;
        int leftIndexofLast = middle + 1;
        int tempPos = left;

        while (left <= rightIndexofFirst && leftIndexofLast <= right) {
            if (this->array[left] <= this->array[leftIndexofLast])
                temp[tempPos++] = this->array[left++];
            else
                temp[tempPos++] = this->array[leftIndexofLast++];
        }
        while (left <= rightIndexofFirst)
            temp[tempPos++] = this->array[left++];
        while (leftIndexofLast <= right)
            temp[tempPos++] = this->array[leftIndexofLast++];
        for (int i = 0; i < numElements; i++, --right)
            this->array[right] = temp[right];
    }
}

template class MergeSortGeneric<int>;
template class MergeSortGeneric<Coordinate>;
template class MergeSortGeneric<MailingAddress>;