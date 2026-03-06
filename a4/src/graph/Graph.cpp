//
// Created by ojcch on 4/15/2020.
//

#include "graph/Graph.h"
#include <iostream>

using namespace std;

//initializing the counter with zero
int Graph::vertexId = 0;

void Graph::addEdge(Edge *e) const {
    vector<Edge *> *vEdges;

    //find the edges of the e's source vertex
    Vertex *srcVertex = e->getSrc();
    auto iter1 = edges->find(srcVertex->getId());

    if (iter1 == edges->end()) { //if not found
        vEdges = new vector<Edge *>(); //create the edges
        edges->insert({srcVertex->getId(), vEdges}); //insert the edge vector of the source vertex
    } else //if found, just get it
        vEdges = iter1->second;

    vEdges->push_back(e); //add the edge
}

//constructor to instantiate an undirected graph
Graph::Graph() : Graph(true) {
}

Graph::Graph(bool undirected) {

    this->undirected = undirected;

    //create the maps
    vertices = new unordered_map<long, Vertex *>();
    verticesById = new unordered_map<int, Vertex *>();
    edges = new unordered_map<int, vector<Edge *> *>();
}

Graph::~Graph() {
    delete edges;
    delete verticesById;
    delete vertices;
}

unordered_map<int, Vertex *> *Graph::getVertices() {
//returns all vertices (indexed by id)
    return this->verticesById;
}

void Graph::addEdge(Object *v, Object *w, double weight) {

    //get the corresponding vertex of v and w
    Vertex *v1 = getVertex(v, true);
    Vertex *v2 = getVertex(w, true);

    //add the edge
    addEdge(v1, v2, weight);
}

void Graph::addEdge(Vertex *v, Vertex *w, double weight) {
    //add the edge
    addEdge(new Edge(v, w, weight));
    if (undirected) {
        //if the graph is undirected, add the reversed edge
        addEdge(new Edge(w, v, weight));
    }
}

Vertex *Graph::getVertex(int id) const {
    //find the vertex
    auto iter = verticesById->find(id);
    if (iter == verticesById->end()) return nullptr; //not found
    return iter->second; //found
}

Vertex *Graph::getVertex(Object *obj, bool insertVertex) const {
    Vertex *v1 = nullptr;

    //get the hash of the data and find the vertex
    long vHash = obj->hash();
    auto iter1 = vertices->find(vHash);

    if (iter1 == vertices->end()) { //not found
        if (insertVertex) { //wants to insert it? if so, create the vertex and insert it into the graph
            v1 = new Vertex(vertexId++, obj); //increment the vertexId

            //we need to insert it in both maps
            vertices->insert({vHash, v1});
            verticesById->insert({v1->getId(), v1});
        }
    } else //found
        v1 = iter1->second;

    //return the vertex
    return v1;
}

int Graph::getNumEdges() {
    int numOfEdges = 0;
    //iterate over the edges of each vertex
    for (auto &vertexEdges: *edges) {
        numOfEdges += vertexEdges.second->size();
    }
    return numOfEdges;
}

int Graph::getNumVertices() {
    return vertices->size();
}

Edge *Graph::getEdge(Object *v, Object *w) {

    //find the corresponding vertex for v
    Vertex *v1 = getVertex(v, false);
    if (v1 == nullptr) return nullptr; //not found


    //find the corresponding vertex for w
    Vertex *v2 = getVertex(w, false);
    if (v2 == nullptr) return nullptr; //not found

    //return the edge
    return getEdge(v1, v2);
}

//returns the (first) edge connecting v and w (v->w)
Edge *Graph::getEdge(Vertex *source, Vertex *target) {

    //find the edges of source
    auto iter = edges->find(source->getId());
    if (iter != edges->end()) {//found
        auto edgeVector = iter->second;

        //check if the edge exists, if so, return it
        for (Edge *e : *edgeVector) {
            if (e->getTarget()->getId() == target->getId()) return e;
        }
    }

    //not found
    return nullptr;
}

bool Graph::isThereEdge(Object *v, Object *w) {

    //get the vertices
    Vertex *v1 = getVertex(v, false);
    if (v1 == nullptr) return false;
    Vertex *v2 = getVertex(w, false);
    if (v2 == nullptr) return false;

    //iterate over the outgoing edges of v1, trying to find if there is an edge
    auto iter = edges->find(v1->getId());
    if (iter != edges->end()) {
        auto vector = iter->second;
        for (Edge *e : *vector) {
            if (e->getTarget()->getId() == v2->getId()) return true; //found
        }
    }
    return false; //not found
}

vector<Edge *> *Graph::getAllEdges(Object *v) {

    vector<Edge *> *allEdg = nullptr;

    //get the vertex
    Vertex *v1 = getVertex(v, false);
    if (v1 == nullptr) return allEdg;

    allEdg = new vector<Edge *>();
    //iterate over all the edges
    for (pair<int, vector<Edge *> *> edgeEntry : *edges) {
        vector<Edge *> *edgeVector = edgeEntry.second;

        //check if v1 is the source or target of the edges
        for (Edge *edge: *edgeVector) {
            if (edge->getSrc()->getId() == v1->getId() || edge->getTarget()->getId() == v1->getId())
                allEdg->push_back(edge);
        }

    }
    return allEdg;
}

//finds all outgoing edges (x, y) of vertex v, i.e., x = v
vector<Edge *> *Graph::getOutGoingEdges(Vertex *v) {

    //get the edges of v
    auto it = edges->find(v->getId());
    if (it == edges->end()) return nullptr; //not found

    return it->second; //found
}

vector<Edge *> *Graph::getOutGoingEdges(Object *v) {
    vector<Edge *> *allEdg = nullptr;

    //get the vertex
    Vertex *v1 = getVertex(v, false);
    if (v1 == nullptr) return allEdg;

    //get the outgoing edges of v1
    return getOutGoingEdges(v1);
}

unordered_set<Vertex *> *Graph::getAllNeighbors(Object *v) {

    //get all the edges of v
    vector<Edge *> *allEdg = getAllEdges(v);
    if (allEdg == nullptr) return nullptr;

    //iterate over the edges
    auto *neighbors = new unordered_set<Vertex *>();
    for (Edge *edge: *allEdg) {
        if (v->equals(edge->getSrc()->getData())) //v is the source of the edge
            neighbors->insert(edge->getTarget());
        else // v is the target of the edge
            neighbors->insert(edge->getSrc());
    }

    return neighbors;
}

//finds all vertices x that v (vertex data) points to (v->x)
unordered_set<Vertex *> *Graph::getOutgoingNeighbors(Object *v) {

    //get vertex
    Vertex *v1 = getVertex(v, false);
    if (v1 == nullptr) return nullptr;

    //get the edges
    vector<Edge *> *outEdges = edges->at(v1->getId());

    //iterate the edges and get the target vertices, which are the "outgoing" neighbors
    auto *neighbors = new unordered_set<Vertex *>();
    for (Edge *edge: *outEdges) {
        neighbors->insert(edge->getTarget());
    }

    return neighbors;
}

//prints the graph in the terminal
void Graph::print() {

    //for each vertex
    for (std::pair<long, Vertex *> vertex: *vertices) {
        vector<Edge *> *vector = nullptr;

        //get the edges
        auto iter = edges->find(vertex.second->getId());
        if (iter != edges->end()) {
            vector = iter->second;
        }

        //iterate the edges
        string stringVec = "[";
        if (vector != nullptr) {
            for (Edge *edge: *vector) {

                //format the weight with 2 decimals only
                stringstream sstream;
                sstream.setf(std::ios::fixed);
                sstream.precision(2); //the weight is formatted using two decimals
                sstream << edge->getWeight();
                string weightStr = sstream.str();

                //format and append the target vertex and the edge weight
                stringVec.append(edge->getTarget()->toString())
                        .append(" (w:")
                        .append(weightStr)
                        .append(")").append("; ");
            }

            //remove the late semicolon+space
            if (!vector->empty())
                stringVec.erase(stringVec.end() - 2, stringVec.end());
        }

        stringVec.append("]");

        //print the adjacent nodes
        cout << vertex.second->toString() << " -> " << stringVec << endl;;
    }
}

void Graph::printEdges(vector<Edge *> *edges) {
    string stringVec = "[";

    if (edges != nullptr) {
        for (Edge *edge: *edges)
            stringVec.append(edge->toString()).append("; ");
        if (!edges->empty())
            stringVec.erase(stringVec.end() - 2, stringVec.end());
    }

    stringVec.append("]");
    cout << stringVec << endl;;
}

void Graph::printVertices(unordered_set<Vertex*> *vertices) {
    string stringVec = "[";

    if (vertices != nullptr) {
        for (Vertex *vertex: *vertices)
            stringVec.append(vertex->toString()).append("; ");
        if (!vertices->empty())
            stringVec.erase(stringVec.end() - 2, stringVec.end());
    }

    stringVec.append("]");
    cout << stringVec << endl;;
}
