//
// Created by ojcch on 4/18/2020.
//

#include "entity/City.h"

City::City(string cityName) {
    this->cityName = new string(std::move(cityName));
    this->country = new string("USA");
}

City::City(string cityName, string country) {
    this->cityName = new string(std::move(cityName));
    this->country = new string(std::move(country));
}

string City::toString() {
    return "{" + *cityName + ", " + *country + "}";
}


bool City::equals(Object *obj) {
    bool b = instanceOf<City>(obj); //is obj a pointer to a City?
    if (!b) return false; //if not, return false
    City *objCity = dynamic_cast<City *>(obj); //cast obj to City*
    return this->toString() == objCity->toString(); //check if their strings are the same
}

long City::hash() {
    //just use a simple approach, compute the hash based on its string
    return HashFunctions::hashString(toString());
}

City::~City() {
    delete cityName;
    delete country;
}



string *City::getCityName() const {
    return cityName;
}

string *City::getCountry() const {
    return country;
}