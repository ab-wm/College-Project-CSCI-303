//
// Created by ojcch on 4/19/2020.
//

#include "algorithms/DijkstraAlgorithm.h"
#include <climits>
using namespace std;
//constructor
DijkstraAlgorithm::DijkstraAlgorithm(Graph *pGraph) {
    graph = pGraph;
    this->dist = new unordered_map<int, double>();
    this->prev = new unordered_map<int, int>();
    this->unknown = new unordered_set<int>();
}

//destructor
DijkstraAlgorithm::~DijkstraAlgorithm() {
    delete (dist);
    delete (prev);
    delete unknown;
}

//runs the algorithm on source vertex (data) v
// PREREQUISITE: Graph must contain the vertex
DijkstraOutput *DijkstraAlgorithm::findShortestPaths(Object *v) {
    Vertex *source = graph->getVertex(v, true);

    // IMPLEMENT YOUR ALGORITHM HERE
    // while you can implement the algorithm as you desire, we recommend
    // structuring your algorithm into multiple methods that perform
    // a well-defined task. To facilitate this we provide the skeleton
    // three methods: initialize, findMinDistVertex, and relaxOutGoingEdges.
    // These methods should be called from this method (findShortestPaths)
    initialize(source);

    // Ensure to update the new vertex (after source) with the source
    Vertex* nextMinVertex = findMinDistVertex();
    unknown->erase(nextMinVertex->getId());

    // While loop that will run the algorithm until all vertexes are known
    // findMindDistVertex() searches for unknown vertexes, and returns nullptr if none is found
    while (nextMinVertex != nullptr) {
        relaxOutGoingEdges(nextMinVertex); // Relax edges
        nextMinVertex = findMinDistVertex();
        if (nextMinVertex != nullptr) { // Update dist with nextMinVertex
            unknown->erase(nextMinVertex->getId());
        }
    }

    return new DijkstraOutput(graph, new unordered_map<int, double>(*dist), new unordered_map<int, int>(*prev));
}


//performs the initialization step of Dijkstra's algorithm
void DijkstraAlgorithm::initialize(Vertex *sourceVertex) {

    //every time there is an initialization, start over
    delete dist;
    delete prev;
    delete unknown;
    this->dist = new unordered_map<int, double>();
    this->prev = new unordered_map<int, int>();
    this->unknown = new unordered_set<int>();

    // Add all verticies to unknown and remove the source vertex.
    // Appropriately add the source vertex to dist and prev
    for (pair<int, Vertex *> v : *graph->getVertices()) {
        this->unknown->insert(v.first);
    }
    this->unknown->erase(sourceVertex->getId());
    this->prev->insert({sourceVertex->getId(), -1}); //-1 represents the source vertex itself
    this->dist->insert({sourceVertex->getId(), 0});

    // Update the weights of the nearest neighbors
    relaxOutGoingEdges(sourceVertex);
}

//finds the vertex with the minimum dist from the unknown vertices
// PRECONDITION: Must be run after relaxation of Edges
// POSTCONDITION: Vertex pointer or nullptr if none is found
Vertex *DijkstraAlgorithm::findMinDistVertex() {
    double minWeight = LONG_MAX;
    Vertex* minDistVertex = nullptr;
    for (auto unknownVertex : *unknown) {
        if (dist->find(unknownVertex) != dist->end()) // Check if unknownVertex has a recorded distance
            if (dist->at(unknownVertex) < minWeight) { // If the distance of the unknown vertex is the smallest (or still default value)
                minWeight = dist->at(unknownVertex); // Update the lowest weight found
                minDistVertex = graph->getVertex(unknownVertex); // Store the vertex
            }
    }
    // If no vertex is found, return nullptr and handle accordingly
    return minDistVertex;
}

//relaxes the outgoing edges of v
// Updates prev to the newest found parent with the shortest distance
void DijkstraAlgorithm::relaxOutGoingEdges(Vertex *v) {
    for (const auto nVertex : *graph->getOutgoingNeighbors(v->getData())) { // Search through all neighbors
        int vertexID = v->getId();
        int neighborID = nVertex->getId();
        double sourceDistance = dist->at(vertexID);
        double weightOfConnectingEdge = graph->getEdge(v, nVertex)->getWeight();
        double neighborDistanceFromVertex = weightOfConnectingEdge + sourceDistance;
        // If the neighboring vertex is infinity (not in dist), insert its distance from source and set prev
        // Edge between v + the distance of v (distance from source)
        if (dist->find(neighborID) == dist->end()) {
            prev->insert({neighborID, vertexID}); // Set prev
            dist->insert({neighborID, neighborDistanceFromVertex}); // Set distance
        }
        // If stored distance is more than neighborDistanceFromVertex
        else if (neighborDistanceFromVertex < dist->at(neighborID)) {
            prev->erase(neighborID); // Remove previous stored parent
            prev->insert({neighborID, vertexID}); // Set prev
            dist->at(neighborID) = neighborDistanceFromVertex; // Set distance
        }
    }
}