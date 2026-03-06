//
// Created by ojcch on 4/15/2020.
//

#include "graph/Vertex.h"

Vertex::Vertex(const int id, Object *data) {
    this->id = id;
    this->data = data;
}

int Vertex::getId() const {
    return id;
}

Object *Vertex::getData() const {
    return data;
}

std::string Vertex::toString() {
    return std::to_string(id) + "-" + data->toString();
}

Vertex::~Vertex() {
    delete data;
}
