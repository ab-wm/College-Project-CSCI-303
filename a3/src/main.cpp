#include <iostream>
#include <vector>
#include <fstream>
#include <entity/Coordinate.h>
#include <algorithms/InsertionSortIntegers.h>
#include <algorithms/InsertionSortGeneric.h>
#include <algorithms/InsertionSortGenericWithComparator.h>
#include <comparator/CoordinateYXComparator.h>
#include "utilities/ArrayUtilities.h"
#include <entity/MailingAddress.h>
#include <algorithms/QuickSortIntegers.h>
#include <algorithms/QuickSortGeneric.h>
#include <algorithms/QuickSortGenericWithComparator.h>
#include <comparator/MailingAddressStateComparator.h>

#include <algorithms/MergeSortGenericWithComparator.h>
#include <comparator/IntegerDescendingComparator.h>

using namespace std;

void insertionSortExample(vector<int> unsortedIntArray, vector<Coordinate> unsortedCoordinates);

void insertionSortExampleFromFile();

// Function to open files
void openDataFile (fstream &fileVar, const string &pathName);
// Functions to read files and build vectors of appropriate objects
vector<int> buildVectorInteger (fstream &fileVar);
vector<MailingAddress> buildVectorAddress (fstream &fileVar);
vector<Coordinate> buildVectorCoordinate (fstream &fileVar);

int main() {

    //these are arrays (of integers and coordinates) used as examples
    vector<int> unsortedIntArray{42, 1, 6, 56, 54, 0, 7, 1};
    vector<Coordinate> unsortedCoordinates{Coordinate(3, 3), Coordinate(3, 1), Coordinate(2, 1),
                                           Coordinate(3, 0), Coordinate(2, 3)};

    //-------------------------------------

    //here we sort the arrays using insertion sort
    insertionSortExample(unsortedIntArray, unsortedCoordinates);

    //here we sort numbers read from an input file, using insertion sort
    insertionSortExampleFromFile();
    cout << endl << endl << endl << endl;


    //---------------------
    //MODIFY THIS FUNCTION ACCORDING TO THE ASSIGNMENT INSTRUCTIONS
    // Open desired files
    fstream integerFile;
    fstream addressFile;
    fstream coordinatesFile;
    openDataFile (integerFile, "../data/numbers.txt");
    openDataFile (addressFile, "../data/addresses.txt");
    openDataFile (coordinatesFile, "../data/coordinates.txt");
    // Create the unsorted arrays
    vector<int> unsortedIntegersFile = buildVectorInteger (integerFile);
    vector<MailingAddress> unsortedAddressFile = buildVectorAddress (addressFile);
    vector<Coordinate> unsortedCoordinatesFile = buildVectorCoordinate(coordinatesFile);
    // Close files
    integerFile.close();
    addressFile.close();
    coordinatesFile.close();

    ///// Part 1: Sorting numbers and coordinates (x, then by y) using quicksort
    // Sort numbers and coordinates, then print
    vector<int> sortedIntegersFile = QuickSortIntegers(unsortedIntegersFile).sort();
    vector<Coordinate> sortedCoordinatesFile = QuickSortGeneric<Coordinate>(unsortedCoordinatesFile).sort();
    // Print
    cout << "Sorting numbers by quicksort:" << endl;
    ArrayUtilities<int>::printArray(sortedIntegersFile);
    cout << endl;
    cout << "Sorting coordinates by quicksort (first by x, then by y):" << endl;
    ArrayUtilities<Coordinate>::printArray(sortedCoordinatesFile);
    cout << endl << endl;

    ///// Part 2: Sorting Mailing addresses by-street and by-city using quicksort
    // by-street using generic
    // by-city using comparator
    // Sort the numbers
    Comparator<MailingAddress> *comparatorMailingAddress = new MailingAddressStateComparator();
    vector<MailingAddress> sortedMailingAddressByStreet = QuickSortGeneric<MailingAddress>(unsortedAddressFile).sort();
    vector<MailingAddress> sortedMailingAddressByState = QuickSortGenericWithComparator<MailingAddress>(unsortedAddressFile).sort(comparatorMailingAddress);
    // Print
    cout << "Sorting mailing addresses by quicksort (by-street):" << endl;
    ArrayUtilities<MailingAddress>::printArray(sortedMailingAddressByStreet);
    cout << endl;
    cout << "Sorting coordinates by quicksort (by-state):" << endl;
    ArrayUtilities<MailingAddress>::printArray(sortedMailingAddressByState);
    cout << endl << endl;

    ///// Part 3: Sorting Coordinates by y and then by x using MergSort
    // Sort Coordinates with the appropriate comparator and print
    Comparator<Coordinate> *comparatorCoordinateYX = new CoordinateYXComparator();
    vector<Coordinate> sortedCoordinatesFileMergeComparator = MergeSortGenericWithComparator<Coordinate>(unsortedCoordinatesFile).sort(comparatorCoordinateYX);
    // Print
    cout << "Sorting coordinates by MergeSort (first by y, and then by x):" << endl;
    ArrayUtilities<Coordinate>::printArray(sortedCoordinatesFileMergeComparator);
    cout << endl;

    ///// Part 4: Sorting integers in decending order using MergeSort and a comparator
    // Sort Integers with the appropriate comparator for descending order and print
    Comparator<int> *comparatorIntegerDescending = new IntegerDescendingComparator();
    vector<int> sortedIntegersFileMergeDescending = MergeSortGenericWithComparator<int>(unsortedIntegersFile).sort(comparatorIntegerDescending);
    // Print
    cout << "Sorting integers in descending order using Mergesort:" << endl;
    ArrayUtilities<int>::printArray(sortedIntegersFileMergeDescending);
    cout << endl;
    return 0;
}






/*
 * Function that illustrates how to sort integers (read from a text file) using insertion sort.
 */
void insertionSortExampleFromFile() {

    string filePath = "../data/numbers.txt";

    fstream numbersFile;
    numbersFile.open(filePath, ios::in);

    //check if the file is open
    if (!numbersFile.is_open()) {
        cout << "Could not find/open input file" << endl;
        return;
    }

    //-------------------------------------

    vector<int> unsortedArray;

    //read the numbers line by line
    string line;
    while (getline(numbersFile, line)) {
        unsortedArray.push_back(stoi(line));
    }
    numbersFile.close();

    //-------------------------------------

    cout << "Size: " << unsortedArray.size() << endl;
    cout << "Unsorted array: " << endl;
    ArrayUtilities<int>::printArray(unsortedArray);

    //sort the numbers
    vector<int> sortedArray = InsertionSortIntegers(unsortedArray).sort();

    cout << "Sorted int array: " <<endl;
    ArrayUtilities<int>::printArray(sortedArray);
}

/*
 * Method that illustrates how to sort integers and coordinates with the different implementations of insertion sort.
 */
void insertionSortExample(vector<int> unsortedIntArray, vector<Coordinate> unsortedCoordinates) {

    //Sorting an integer array with insertion sort

    cout << "Unsorted int array: ";
    ArrayUtilities<int>::printArray(unsortedIntArray);

    vector<int> sortedIntArray = InsertionSortIntegers(unsortedIntArray).sort();

    cout << "Sorted int array: ";
    ArrayUtilities<int>::printArray(sortedIntArray);

    //--------------------------------------------------

    //Sorting an array of coordinates with in insertion sort.
    //The sorting is done first by the x component of the coordinates and then by the y component
    //In other words, (x1, y1) goes before (x2, y2) if (x1 < x2) or (x1 == x2 && y1 < y2)
    //This order is defined by the < operator, which is implemented in the Coordinate class

    cout << "Unsorted coordinates: ";
    ArrayUtilities<Coordinate>::printArray(unsortedCoordinates);

    vector<Coordinate> sortedCoordinates = InsertionSortGeneric<Coordinate>(unsortedCoordinates).sort();

    cout << "Sorted coordinates (first by x, and then by y): ";
    ArrayUtilities<Coordinate>::printArray(sortedCoordinates);


    //--------------------------------------------------

    //Sorting an array of coordinates with in insertion sort.
    //In this case, the order of coordinates is different:
    //The sorting is first by the y of the coordinates and then by the x part
    //(x1, y1) goes before (x2, y2) if (y1 < y2) or (y1 == y2 && x1 < x2)
    //This order is implemented in CoordinateYXComparator

    InsertionSortGenericWithComparator<Coordinate> algorithm = InsertionSortGenericWithComparator<Coordinate>(
            unsortedCoordinates);
    Comparator<Coordinate> *comparator2 = new CoordinateYXComparator();
    vector<Coordinate> sortedCoordinates2 = algorithm.sort(comparator2);

    cout << "Sorted coordinates (first by y, and then by x): ";
    ArrayUtilities<Coordinate>::printArray(sortedCoordinates2);
}

// Method to open files
void openDataFile (fstream &fileVar, const string &pathName) {
    fileVar.open(pathName, ios::in);
    if (!fileVar.is_open()) {
        cout << "Could not find/open input file" << endl;
    }
}

// Functions to read files and build vectors of appropriate objects
vector<int> buildVectorInteger (fstream &fileVar) {
    //read the numbers line by line
    string line;
    vector<int> unsortedArray;
    while (getline(fileVar, line)) {
        unsortedArray.push_back(stoi(line));
    }
    return unsortedArray;
}
vector<MailingAddress> buildVectorAddress (fstream &fileVar) {
    // Read from file till end is reached
    // Read each line in fragments to grab the individual elements like state and city information
    vector<MailingAddress> unsortedArray;
    string street;
    string city;
    string state;
    int zipcode;
    string throwAway; // Trailing new line character
    while (!fileVar.eof()) {
        // Extract each field
        getline(fileVar, street, ',');
        getline(fileVar, city, ',');
        getline(fileVar, state, ',');
        fileVar >> zipcode;
        getline(fileVar, throwAway, '\n');
        // Store in vector using emplace back to avoid unnecessary copies
        unsortedArray.emplace_back(street, city, state, zipcode);
    }
    return unsortedArray;
}
vector<Coordinate> buildVectorCoordinate (fstream &fileVar) {
    vector<Coordinate> unsortedArray;
    string linePart;
    while (!fileVar.eof()) {
        // Extract the coordinates, reading one half at a time
        getline(fileVar, linePart, ',');
        int coordinate_x = stoi(linePart);
        getline(fileVar, linePart);
        int coordinate_y = stoi(linePart);
        // Store in vector using emplace back to avoid unnecessary copies
        unsortedArray.emplace_back(coordinate_x, coordinate_y);
    }
    return unsortedArray;
}