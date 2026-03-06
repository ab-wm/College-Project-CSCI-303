#include <utility>

//
// Created by ojcch on 4/19/2020.
//

#ifndef GRAPHS_NODE_H
#define GRAPHS_NODE_H

#include "entity/Object.h"

/*
 * A generic class for an element that stores a string
 */
class StringElement : public Object {
private:
    string data;
public:

    //constructor
    explicit StringElement(string elem);

    //returns the string in format [string]
    string toString() override ;

    //checks if this StringElement is equals to obj
    bool equals(Object *obj) override;

    //returns a hash for this string
    long hash() override;

};


#endif //GRAPHS_NODE_H
