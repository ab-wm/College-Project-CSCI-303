#include <iostream>
#include <fstream>
#include "graph/Vertex.h"
#include "graph/Graph.h"
#include "entity/City.h"
#include "entity/StringElement.h"
#include "algorithms/DijkstraAlgorithm.h"

void buildGraphOfCities();

void buildGraphOfStringElements();

void buildGraphOfDirectedStringElements();

void runDijkstraAlgorithm(Graph *graph, Object *sourceObj, Object *targetObj);

int main() {
    buildGraphOfStringElements();
    cout << "-------------------------------------" << endl;
    buildGraphOfCities();
    cout << "-------------------------------------" << endl;
    buildGraphOfDirectedStringElements();
    return 0;
}

void buildGraphOfStringElements() {

    //----------------
    //objects to be stored in the graph

    Object *A = new StringElement("A");
    Object *B = new StringElement("B");
    Object *C = new StringElement("C");
    Object *D = new StringElement("D");
    Object *E = new StringElement("E");
    Object *F = new StringElement("F");
    Object *G = new StringElement("G");
    Object *H = new StringElement("H");
    Object *I = new StringElement("I");
    Object *J = new StringElement("J");

    //------------------
    //building the graph

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(A, B, 17);
    undirectedGraph->addEdge(A, C, 10);
    undirectedGraph->addEdge(A, D, 6);
    undirectedGraph->addEdge(B, C, 9);
    undirectedGraph->addEdge(B, E, 12);
    undirectedGraph->addEdge(C, D, 1);
    undirectedGraph->addEdge(C, G, 12);
    undirectedGraph->addEdge(C, E, 4);
    undirectedGraph->addEdge(D, F, 9);
    undirectedGraph->addEdge(E, H, 6);
    undirectedGraph->addEdge(F, G, 5);
    undirectedGraph->addEdge(F, I, 6);
    undirectedGraph->addEdge(G, H, 11);
    undirectedGraph->addEdge(G, I, 4);
    undirectedGraph->addEdge(G, J, 12);
    undirectedGraph->addEdge(H, J, 6);
    undirectedGraph->addEdge(I, J, 21);

    //----------------
    //printing the graph

    cout << endl << "* Graph of strings: " << endl;
    undirectedGraph->print();

    //----------------
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, A, H);

    delete (undirectedGraph);
}

void buildGraphOfCities() {

    //----------------
    //cities to be stored in the graph

    City *seattle = new City("Seattle");
    City *sanFrancisco = new City("San Francisco");
    City *losAngeles = new City("Los Angeles");
    City *riverside = new City("Riverside");
    City *chicago = new City("Chicago");
    City *phoenix = new City("Phoenix");
    City *dallas = new City("Dallas");
    City *houston = new City("Houston");
    City *atlanta = new City("Atlanta");
    City *miami = new City("Miami");
    City *washington = new City("Washington");
    City *detroit = new City("Detroit");
    City *philadelphia = new City("Philadelphia");
    City *newYork = new City("NewYork");
    City *boston = new City("Boston");

    //------------------
    //building the graph

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(seattle, sanFrancisco, 711);
    undirectedGraph->addEdge(seattle, chicago, 1775);
    undirectedGraph->addEdge(sanFrancisco, losAngeles, 380);
    undirectedGraph->addEdge(sanFrancisco, riverside, 432);
    undirectedGraph->addEdge(losAngeles, riverside, 85);
    undirectedGraph->addEdge(losAngeles, phoenix, 367);
    undirectedGraph->addEdge(riverside, phoenix, 323);
    undirectedGraph->addEdge(riverside, chicago, 1712);
    undirectedGraph->addEdge(phoenix, houston, 1030);
    undirectedGraph->addEdge(phoenix, dallas, 920);
    undirectedGraph->addEdge(dallas, chicago, 829);
    undirectedGraph->addEdge(dallas, houston, 239);
    undirectedGraph->addEdge(dallas, atlanta, 764);
    undirectedGraph->addEdge(houston, atlanta, 720);
    undirectedGraph->addEdge(houston, miami, 978);
    undirectedGraph->addEdge(miami, atlanta, 637);
    undirectedGraph->addEdge(miami, washington, 971);
    undirectedGraph->addEdge(atlanta, washington, 559);
    undirectedGraph->addEdge(atlanta, chicago, 600);
    undirectedGraph->addEdge(chicago, detroit, 247);
    undirectedGraph->addEdge(detroit, washington, 411);
    undirectedGraph->addEdge(detroit, newYork, 483);
    undirectedGraph->addEdge(detroit, boston, 650);
    undirectedGraph->addEdge(washington, philadelphia, 139);
    undirectedGraph->addEdge(philadelphia, newYork, 117);
    undirectedGraph->addEdge(newYork, boston, 219);

    //----------------
    //printing the graph

    cout << endl << "* Graph of cities: " << endl;
    undirectedGraph->print();

    //----------------
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, riverside, philadelphia);
    runDijkstraAlgorithm(undirectedGraph, sanFrancisco, atlanta);

    delete (undirectedGraph);
}

// Method to build and print the graph and shortest paths between string elements from the file
void buildGraphOfDirectedStringElements() {
    // Creating the graph
    auto *directedGraph = new Graph(false);

    // Opening file
    fstream fp;
    fp.open("../data/graph.csv", ios::in);
    if (!fp.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    // Reading from the file
    while (!fp.eof()) {
        // Variables for graph creation (static to prevent
        Object *nodeFirst;
        string nodeFirstString;
        Object *nodeSecond;
        string nodeSecondString;
        double edgeWeight;
        string throwAway;

        // Read the data into the variables
        getline(fp, nodeFirstString, ',');
        getline(fp, nodeSecondString, ',');
        fp >> edgeWeight;
        getline(fp,throwAway,'\n');

        // Create the objects to represent the nodes and add it to the graph
        nodeFirst = new StringElement(nodeFirstString);
        nodeSecond = new StringElement(nodeSecondString);
        directedGraph->addEdge(nodeFirst, nodeSecond, edgeWeight);
    }
    fp.close();

    // Print the shortest paths
    Object *node1 = new StringElement("node1");
    Object *node2 = new StringElement("node2");
    Object *node15 = new StringElement("node15");
    Object *node58 = new StringElement("node58");
    Object *node63 = new StringElement("node63");

    cout << endl << "* Shortest path from node1 to node2: ";
    runDijkstraAlgorithm(directedGraph, node1, node2);

    cout << endl << "* Shortest path from node1 to node 63: ";
    runDijkstraAlgorithm(directedGraph, node1, node63);

    cout << endl << "* Shortest path from node15 to node58: ";
    runDijkstraAlgorithm(directedGraph, node15, node58);

    delete (directedGraph);
}


/*
 * Runs Dijkstra's algorithm on the provided graph using source object.
 * It prints the result of the algorithm and also the shortest path from the source object to the target object.
 */
void runDijkstraAlgorithm(Graph *graph, Object *sourceObj, Object *targetObj) {
    auto *algorithm = new DijkstraAlgorithm(graph);
    DijkstraOutput *output = algorithm->findShortestPaths(sourceObj);

    cout << endl << "* Dijkstra's result: " << endl;
    if (output != nullptr) {
        output->print();
        cout << endl;
        output->printShortestPath(targetObj);
    } else {
        cout << "No output" << endl;
    }

    delete (output);
    delete (algorithm);
}
