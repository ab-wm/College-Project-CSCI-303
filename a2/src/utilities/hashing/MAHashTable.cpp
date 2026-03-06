#include "utilities/hashing/MAHashTable.h"

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*****
// Constructor
*****/
// Constructor that sets up the hash table. Resizes table to appropriate length
// Elements are vectors of mailing address type, and are empty
MAHashTable::MAHashTable(const int &tableSize) {
    // Assigning value of M
    M = tableSize;
    // Initializing the hash table with set size    for (int i = 0; i < M; i++)
    table.resize(M);
}

/*****
// Hashing methods
*****/
// Function to return the hash value of a provided integer
long MAHashTable::hashInt(const int &i) {
    return i % M;
}
// Function to return the hash value of a provided string.
long MAHashTable::hashString(const string &s) {
    long stringHash = 0;
    for (int i = s.size()-1; i >= 0; i--)
        stringHash = (R * stringHash + s[i]) % M;
    return stringHash;
}
// Function to return the hash value of an object of type Mailing address
// Convert each attribute of the objects into hash values, and hash all values together
long MAHashTable::hashAddress(const MailingAddress &addr) {
    return (((((hashString(addr.street) * R
                + hashString(addr.city)) % M) * R
                    + hashString(addr.state)) % M) * R
                        + hashInt(addr.zipcode)) % M;
}

/*****
// Public methods
*****/
// Inserts MailingAddress objects into a hash table
// Get hash value, increase count of elements and insert into table
void MAHashTable::insert(const MailingAddress &addr) {
    const long hashIndex = hashAddress(addr);
    eleCount++;
    table[hashIndex].emplace_back(addr);
    sort (table[hashIndex].begin(), table[hashIndex].end(), compAddress);
}

// Checks if the hash table contains an address using the equals method
// Create hash value of provided address, and search at index
string MAHashTable::contains(const MailingAddress &addr) {
    const long hashIndex = hashAddress(addr);
    for (const MailingAddress &searchAddr : table[hashIndex]) {
        if (searchAddr.equals(addr))
            return "true";
    }
    return "false"; // Mo match is found
}

// Returns load factor of a table from eleCount
float MAHashTable::getLoadFactor() {
    return static_cast<float>(eleCount) / static_cast<float>(M);
}

// Prints the hashtable
// Loop through the vector adjust for three cases
// 1: Empty vectors
// 2: Single entry in a slot
// 3: Multiple entries, seperated by semicolon
void MAHashTable::print() {
    for (int hashIndex = 0; hashIndex < M; hashIndex++) {
        cout << hashIndex << "->";
        if (table[hashIndex].empty()) // No elements
            cout << "[]" << endl;
        else
        {
            // Adjust for semicolon separators. Print last element separately. In the case
            // of just one element, the last element is the first element.
            cout << "[";
            for (int i = 0; i < table[hashIndex].size() - 1; i++)
                cout << table[hashIndex][i].toString() << "; ";
            cout << table[hashIndex][table[hashIndex].size() - 1].toString();
            cout << "]" << endl;
        }
    }
}

// Function for the comparison of two MailingAddress objects
bool MAHashTable::compAddress (const MailingAddress &addr1, const MailingAddress &addr2) {
    // Check for equality, then compare if it fails
    if (addr1.state == addr2.state) {
        if (addr1.city == addr2.city) {
            if (addr1.zipcode == addr2.zipcode)
            {
                return addr1.street < addr2.street;
            }
            else { return addr1.zipcode < addr2.zipcode; }
        }
        else { return addr1.city < addr2.city; }
    }
    else { return addr1.state < addr2.state; }
}