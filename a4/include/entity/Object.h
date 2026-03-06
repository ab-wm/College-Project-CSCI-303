//
// Created by ojcch on 4/18/2020.
//

#ifndef GRAPHS_OBJECT_H
#define GRAPHS_OBJECT_H

#include <string>

using namespace std;

//a function for checking if the pointer prt, of type T, points to an instance of type Base
template<typename Base, typename T>
inline bool instanceOf(const T *ptr) {
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

/*
 * Abstract class Object, which is the base class of all the other data classes stored in a Graph
 */
class Object {
public:

    //returns a string representation of the object
    virtual string toString() = 0;

    //returns a hash for the current object
    virtual long hash() = 0;

    //returns if this Object is equals to obj (the parameter)
    virtual bool equals(Object *obj) = 0;

    //virtual destructor
    virtual ~Object() = 0;
};

#endif //GRAPHS_OBJECT_H
