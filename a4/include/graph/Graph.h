//
// Created by ojcch on 4/15/2020.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

/*
 * Class that represents a weighted graph.
 * It implements an adjacency map of vertices.
 * It supports directed and undirected graphs.
 * The data elements stored in the vertices must inherit from the class Object.
 */
class Graph {
private:
    //static counter used for giving a unique ID to each new vertex added to the graph;
    //it starts at zero
    static int vertexId;

    //vertices indexed by a vertex id.
    //a map {x, y} is used, where x is the vertex id, and y is the vertex itself
    unordered_map<int, Vertex *> *verticesById;

    //edges (v->w) for each vertex
    //a map {x, y} is used, where x is the id of v, and y is a vectors of the outgoing edges of v: (v->w)
    unordered_map<int, vector<Edge *> *> *edges;

    //vertices indexed by the hash of the data stored in the vertex.
    //a map {x, y} is used, where x is the hash of the vertex data, and y is the vertex itself.
    //this map is useful for not repeating the data (i.e., vertices with the same data) in the graph
    unordered_map<long, Vertex *> *vertices;

    //if true, the graph is undirected, otherwise it is directed
    bool undirected = true;

    //adds the edge e=(v->w) to the list of edges for vertex v
    void addEdge(Edge *e) const;

public:

    //constructor to instantiate an undirected graph
    explicit Graph() ;

    //constructor to create directed or undirected graphs
    explicit Graph(bool undirected) ;

    //destructor
    ~Graph();

    //returns all vertices (indexed by id)
    unordered_map<int, Vertex *> *getVertices();

    //adds an edge connecting v and w: (v->w) or (v <-> w), if the graph id directed or undirected, respectively.
    //if the graph is undirected, it creates two edges
    //here, v and w represent the data objects to be stored in the graph
    void addEdge(Object *v, Object *w, double weight) ;

    //adds an edge connecting v and w: (v->w) or (v <-> w), if the graph id directed or undirected, respectively.
    //if the graph is undirected, it creates two edges
    //here, v and w represent existing vertices in the graph
    void addEdge(Vertex *v, Vertex *w, double weight);

    //gets the vertex by id
    //if the vertex does not exist in the graph, it returns nullptr
    Vertex *getVertex(int id) const ;

    //gets the vertex corresponding to obj (i.e., the data);
    //it inserts a new vertex with obj in the graph only if insertVertex = true and obj is not found in the graph
    Vertex *getVertex(Object *obj, bool insertVertex) const;

    //returns the number of edges
    int getNumEdges() ;

    //returns the number of vertices
    int getNumVertices() ;

    //returns the ("first") edge connecting v and w (v->w)
    Edge *getEdge(Object *v, Object *w);

    //returns the ("first") edge connecting v and w (v->w)
    Edge *getEdge(Vertex *source, Vertex *target) ;

    //checks if there is an edge connecting v and w (v->w)
    bool isThereEdge(Object *v, Object *w) ;

    //returns all the incident edges (x, y) of vertex v, i.e., x = v or y = v
    vector<Edge*> *getAllEdges(Object *v) ;

    //returns all the outgoing edges (x, y) of vertex v, i.e., x = v
    vector<Edge*> *getOutGoingEdges(Vertex *v);

    //returns all the outgoing edges (x, y) of v (the vertex data), i.e., x = v
    vector<Edge*> *getOutGoingEdges(Object *v) ;

    //returns all the vertices that are neighbors of object v (i.e. all vertices pointing from/to v)
    unordered_set<Vertex *> *getAllNeighbors(Object *v);

    //returns all the vertices x that v (vertex data) points to (v->x)
    unordered_set<Vertex *> *getOutgoingNeighbors(Object *v) ;

    //prints the graph in the terminal
    void print() ;

    //utility method that prints the vector of edges in the terminal
    static void printEdges(vector<Edge *> *edges);

    //utility method that prints the set of vertices in the terminal
    static void printVertices(unordered_set<Vertex *> *vertices);
};


#endif //GRAPHS_GRAPH_H
