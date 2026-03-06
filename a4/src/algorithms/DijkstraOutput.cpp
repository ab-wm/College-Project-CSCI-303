//
// Created by ojcch on 4/24/2020.
//

#include "algorithms/DijkstraOutput.h"

//constructor
DijkstraOutput::DijkstraOutput(Graph *graph, unordered_map<int, double> *dist, unordered_map<int, int> *prev) {
    this->graph = graph;
    this->dist = dist;
    this->prev = prev;
}

//prints this output
void DijkstraOutput::print() {
    // Vector for outputs
    string distOutputString = "dist[]: ";
    string prevOutputString = "prev[]: ";

    // Creating dist[] string
    for (const auto graphVertex : *graph->getVertices()) {
        // Vertex string representation
        string vertexString = graphVertex.second->toString();
        // Formating for two decimals
        stringstream sstream;
        sstream.setf(std::ios::fixed);
        sstream.precision(2);
        sstream << dist->at(graphVertex.first); // Get the distance through vertex ID
        string weightStr = sstream.str();
        // Storing the vector
        distOutputString.append("{")
                        .append(vertexString)
                        .append(" -> ")
                        .append(weightStr)
                        .append("}, ");
    }
    // Creating prev[] string
    for (const auto graphVertex : *graph->getVertices()) {
        // Find vertex ID and vertex string representation
        // Catch the root having a -1 previous
        string sourceString = graphVertex.second->toString();
        string parentString;
        if (prev->at(graphVertex.first) == -1) // Root has no parent
            parentString = "None";
        else
            parentString = graph->getVertex(prev->at(graphVertex.first))->toString();
        // Storing the vector
        prevOutputString.append("{")
                        .append(sourceString)
                        .append(" -> ")
                        .append(parentString)
                        .append("}, ");
    }

    // Removing the extra space and comma at the end of the strings
    distOutputString.erase(distOutputString.end() - 2, distOutputString.end());
    prevOutputString.erase(prevOutputString.end() - 2, prevOutputString.end());
    cout << distOutputString << endl;
    cout << prevOutputString << endl;
}

//prints the shortest path from the source vertex to targetObj
void DijkstraOutput::printShortestPath(Object *targetObj) {
    /// String representation of shortest path
    // Insert the first element
    string shortestString = graph->getVertex(targetObj, false)->toString();
    // Get vertex IDs for the previous vertex
    int targetID = prev->at(graph->getVertex(targetObj, false)->getId());
    // Prepend string vertexes to shortestString to create the desired output
    // Do not attempt the print additional nodes if the target is the source
    while (targetID != -1) {
        // Prepend string of present target
        shortestString.insert(0, graph->getVertex(targetID)->toString() + " -> ");
        // Update vertex IDs for the previous to be the new target
        targetID = prev->at(targetID);
    }

    /// Decimal representation of shortest path
    // Formating for two decimals
    stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(2);
    sstream << dist->at(graph->getVertex(targetObj,false)->getId()); // Get the distance through vertex ID
    // Combine with string representation
    shortestString.append(", Total cost: " + sstream.str());

    cout << shortestString << endl;
}

//destructor
DijkstraOutput::~DijkstraOutput() {
    delete (dist);
    delete (prev);
}
