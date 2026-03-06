//
// Created by ojcch on 2/20/2020.
//

#include <entity/MailingAddress.h>

MailingAddress::MailingAddress(string street, string city, string state, int zipCode) {
    //move avoids making copies of the parameters
    this->street = std::move(street);
    this->city = std::move(city);
    this->state = std::move(state);
    this->zipCode = zipCode;
}

bool MailingAddress::equals(const MailingAddress &addr) {
    if (this->street != addr.street) return false;
    if (this->city != addr.city) return false;
    if (this->state != addr.state) return false;
    return zipCode == addr.zipCode;
}

string MailingAddress::toString() {
    string str = "{";
    str.append(street).append(", ").append(city).append(", ").append(state).append(", ").append(
            to_string(zipCode)).append("}");
    return str;
}


bool  MailingAddress::operator<(MailingAddress const &addr) {
    //CHANGE THIS METHOD to implement:
    //By-street order: first by street, then by city, then by state, and then by zip code.
    // At each step, account for equality
    if (this->street == addr.street) {
        if (this->city == addr.city) {
            if (this->state == addr.state) {
                return this->zipCode < addr.zipCode;
            }
            return this->state < addr.state;
        }
        return this->city < addr.city;
    }
    return this->street < addr.street;
    // Street
    // if (this->street < addr.street) return true;
    // if (this->street > addr.street) return false;
    // // City
    // if (this->city < addr.city) return true;
    // if (this->city > addr.city) return false;
    // // State
    // if (this->state < addr.state) return true;
    // if (this->state > addr.state) return false;
    // // Zipcode
    // return this->zipCode < addr.zipCode; // Equality will be managed by equals()
}

bool  MailingAddress::operator<=(MailingAddress const &addr) {
    return *this < addr || this->equals(addr);
}

string MailingAddress::getStreet() {
    return street;
}

string MailingAddress::getCity() {
    return city;
}

string MailingAddress::getState() {
    return state;
}

int MailingAddress::getZipCode() {
    return zipCode;
}
