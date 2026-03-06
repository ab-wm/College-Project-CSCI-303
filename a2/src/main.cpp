//including other code
#include <iostream>
#include <fstream>
#include "utilities/hashing/MailingAddress.h"
#include "utilities/hashing/MAHashTable.h"

//including a namespace
using namespace std;

//the entry point of the program
int main(int argc, char** argv) {
    // Create hash tables of size 97 and 127
    MAHashTable addressHashTable_97(97);
    MAHashTable addressHashTable_127(127);

    // Ensure an argument is passed
    if (argc != 2) {
        cout << "Usage: ./hashing <absolute/file/path/file_name> (linux) "
                "or hashing.exe <absolute/file/path/file_name> (windows)" << endl;
        return 1;
    }

    // Open the file and check for error
    ifstream addressFile (argv[1]);
    if (!addressFile.is_open()) { //Fails to open
        cout << "Error opening file " << argv[1] << endl;
        return 1;
    }

    // Read from file till end is reached
    // Read each line in fragments to grab the individual elements like state and city information
    while (!addressFile.eof()) {
        // Static variables to prevent re-initialization
        static string street;
        static string city;
        static string state;
        static int zipcode;
        static string throwAway; // Trailing new line character
        // Extract each field, adjusting for extra white space characters
        getline(addressFile, street, ',');
        getline(addressFile, city, ',');
        getline(addressFile, state, ',');
        addressFile >> zipcode;
        getline(addressFile, throwAway, '\n');
        // Create a new MailingAddress object with the values, and insert into hash table
        const MailingAddress address = {street, city, state, zipcode};
        addressHashTable_97.insert(address);
        addressHashTable_127.insert(address);
    }

    // Print hash table and load factor
    cout << "Hashtable of size 97" << endl;
    cout << "Load factor: " << addressHashTable_97.getLoadFactor() << endl;
    cout << endl;
    addressHashTable_97.print();
    cout << endl;
    cout << endl;
    cout << "Hashtable of size 127" << endl;
    cout << "Load factor: " << addressHashTable_127.getLoadFactor() << endl;
    cout << endl;
    addressHashTable_127.print();
    cout << endl;
    cout << endl;

    return 0;
}
