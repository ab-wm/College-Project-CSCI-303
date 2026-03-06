
#ifndef MAHASHTABLE_H
#define MAHASHTABLE_H
#include <vector>
#include "utilities/hashing/MailingAddress.h"


// Setting up global static variable
static int R = 31;


class MAHashTable {
  public:
    // Constructor and hash table
    MAHashTable(const int &tableSize);
    std::vector<std::vector<MailingAddress>> table;
    // Public methods
    float getLoadFactor(); // Returns the current load factor of the hash table
    void print(); // Prints the hash table, including empty locations
    void insert(const MailingAddress &addr); // Inserts an address into a hash table.
    string contains(const MailingAddress &addr); // Check if value is found in the hash table

  private:
    // Variables. Static variable R are implemented in implementation file
    // Changed to non-static to play well with the non-static M
    long hashInt(const int &i); // Create hash values for an integer
    long hashString(const std::string &s); // Create hash values for a string
    long hashAddress(const MailingAddress &addr);
    int M; // Non-Static M for use in the constructor
    int eleCount = 0;

    // Comparator function for sorting
    static bool compAddress(const MailingAddress &addr1, const MailingAddress &addr2);
};



#endif //MAHASHTABLE_H
