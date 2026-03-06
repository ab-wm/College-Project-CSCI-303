//
// Created by ojcch on 4/19/2020.
//

#ifndef GRAPHS_DIJKSTRAALGORITHM_H
#define GRAPHS_DIJKSTRAALGORITHM_H

#include <iostream>
#include "DijkstraOutput.h"
#include <graph/Graph.h>

using namespace std;

/*
 * Class that implements Dijkstra's algorithm.
 */
class DijkstraAlgorithm {

private:

    //graph that this algorithm will operate on
    Graph *graph;

    //map of shortest distances
    //a map {x, y} is used, where x is a vertex id that maps to y: its shortest path distance from a source vertex
    unordered_map<int, double> *dist;

    //map that stores the shortest path tree for a source vertex.
    //a map {x, y} is used, where x is a vertex id that maps to y: its parent vertex (i.e., the vertex id) in the tree
    unordered_map<int, int> *prev;

    //set of unknown vertices (aka S')
    unordered_set<int> *unknown;

    //performs the initialization step of the algorithm
    void initialize(Vertex *sourceVertex) ;

    //finds the vertex, from the unknown vertices, with the minimum shortest distance (i.e., minimum dist)
    Vertex *findMinDistVertex() ;

    //relaxes the outgoing edges of v
    void relaxOutGoingEdges(Vertex *v) ;

public:

    //destructor
    ~DijkstraAlgorithm() ;

    //constructor that receives a graph
    explicit DijkstraAlgorithm(Graph *pGraph) ;

    //runs the algorithm on the object v
    //requirement: v should be already stored in the graph
    DijkstraOutput *findShortestPaths(Object *v) ;
};


#endif //GRAPHS_DIJKSTRAALGORITHM_H
