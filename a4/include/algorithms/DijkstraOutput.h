//
// Created by ojcch on 4/24/2020.
//

#ifndef GRAPHS_DIJKSTRAOUTPUT_H
#define GRAPHS_DIJKSTRAOUTPUT_H

#include <limits>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <iostream>
#include "graph/Graph.h"

/*
 * Class that represents the output of Dijkstra's algorithm, composed of:
 * 1. the distance map
 * 2. the map that stores the shortest path tree
 */
class DijkstraOutput {
private:

    //graph that this output applies to
    Graph *graph;

    //map of shortest distances
    //a map {x, y} is used, where x is a vertex id that maps to y: its shortest path distance from a source vertex
    unordered_map<int, double> *dist;

    //map that stores the shortest path tree for a source vertex.
    //a map {x, y} is used, where x is a vertex id that maps to y: its parent vertex (i.e., the vertex id) in the tree
    unordered_map<int, int> *prev;
public:

    //constructor that receives the data produced by Dijkstra's algorithm
    DijkstraOutput(Graph *graph, unordered_map<int, double> *dist, unordered_map<int, int> *prev) ;

    //prints this output
    void print();

    //prints the shortest path from the source vertex to targetObj
    void printShortestPath(Object *targetObj) ;

    //destructor
    ~DijkstraOutput() ;
};


#endif //GRAPHS_DIJKSTRAOUTPUT_H
