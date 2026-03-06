#include <string>
#include "utilities/hashing/MailingAddress.h"

using namespace std;
/*****
// Constructors
*****/
MailingAddress::MailingAddress(){
    street = "";
    city = "";
    state = "";
    zipcode = -1;
}
MailingAddress::MailingAddress(const std::string &street, const std::string &city,
    const std::string &state, const int &zipcode) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zipcode = zipcode;
}

/*****
// Methods
*****/
bool MailingAddress::equals(const MailingAddress &addr) const {
    if (street == addr.street && city == addr.city && state == addr.state && zipcode == addr.zipcode)
        return true;
    return false;
}
string MailingAddress::toString() const {
    return "{" + street + ", " + city + ", " + state + ", " + to_string(zipcode) + "}";
}
