//
// Created by ojcch on 4/18/2020.
//

#ifndef GRAPHS_CITY_H
#define GRAPHS_CITY_H

#include "Object.h"
#include <iostream>
#include <utility>
#include "graph/HashFunctions.h"

/*
 * A class that represents a City using a name and the country only.
 */
class City : public Object {
private:
    string *cityName = nullptr;
    string *country = nullptr;
public:

    //constructor that receives the city name; the country is USA
    explicit City(string cityName);

    //constructor that receives the city name and country
    City(string cityName, string country) ;

    //returns a string for this city in the format: {Riverside, USA}
    string toString() override ;

    //returns true if this City is equal to obj
    bool equals(Object *obj) override;

    //returns a hash for this City
    long hash() override ;

    //destructor
    ~City() override;

    //------------
    //getter methods

    string *getCityName() const ;

    string *getCountry() const ;


};


#endif //GRAPHS_CITY_H
