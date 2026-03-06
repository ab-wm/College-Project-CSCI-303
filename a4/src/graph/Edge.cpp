//
// Created by ojcch on 4/15/2020.
//

#include "graph/Edge.h"

Edge::Edge(Vertex *src, Vertex *target, double weight) {
    this->src = src;
    this->target = target;
    this->weight = weight;
}

Vertex *Edge::getSrc() const {
    return src;
}

Vertex *Edge::getTarget() const {
    return target;
}

double Edge::getWeight() const {
    return weight;
}

string Edge::toString() {
    stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(2); //the weight is printed with 2 decimals
    sstream << weight;

    string weightStr = sstream.str();
    return "{" + src->toString() + " -> " + target->toString() + ", (w:" + weightStr + ")}";
}
