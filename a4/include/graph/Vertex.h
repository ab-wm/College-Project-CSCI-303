//
// Created by ojcch on 4/15/2020.
//

#ifndef GRAPHS_VERTEX_H
#define GRAPHS_VERTEX_H

#include <string>
#include "entity/Object.h"

/*
 * A vertex in a graph, which stores an instance of an Object's subclass as data.
 * The id of the vertex represents it uniquely in a graph.
 */
class Vertex {
private:
    int id; //id of the vertex
    Object *data; //data stored in the vertex
public:

    //constructor
    Vertex(int id, Object *data);

    //get a string of this vertex in the format: id-data
    std::string toString();

    //destructor
    ~Vertex();

    //------------
    //getter methods

    int getId() const;

    Object *getData() const ;
};


#endif //GRAPHS_VERTEX_H
