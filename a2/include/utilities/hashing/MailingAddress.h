#ifndef MAILINGADDRESS_H
#define MAILINGADDRESS_H
#include <string>

using namespace std;

class MailingAddress {
  public:
    // Attributes
    string street;
    string city;
    string state;
    int zipcode;
    // Constructors
    MailingAddress(); // Default constructor
    MailingAddress(const std::string &street, const std::string &city,
        const std::string &state, const int &zipcode); // Custom constructor
    // Methods
    string toString() const; // Returns string representation of address
    bool equals(const MailingAddress &addr) const; // Checks if two addresses (objects) are the same
};

#endif //MAILINGADDRESS_H
