//
// Created by ojcch on 4/15/2020.
//

#ifndef GRAPHS_EDGE_H
#define GRAPHS_EDGE_H


#include "Vertex.h"
#include <string>
#include <sstream>

using namespace std;

/*
 * A weighted, directed edge in a graph
 */
class Edge {
private:
    Vertex *src; //source vertex
    Vertex *target; //target vertex
    double weight = -1.0; //edge weight
public:

    //default constructor
    Edge(Vertex *src, Vertex *target, double weight);

    //returns a string for this edge in the format: {src -> target, (w:weight)}"
    //the weight is formatted with 2 decimal digits
    //e.g., {V -> W, (w:10.00)}
    string toString() ;

    //------------------------------
    //getter methods

    Vertex *getSrc() const;

    Vertex *getTarget() const ;

    double getWeight() const;

};


#endif //GRAPHS_EDGE_H
