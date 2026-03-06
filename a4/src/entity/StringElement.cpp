
//
// Created by ojcch on 4/19/2020.
//

#include <utility>
#include <graph/HashFunctions.h>
#include "entity/StringElement.h"

StringElement::StringElement(string elem) {
    this->data = std::move(elem);
}

string StringElement::toString() {
    return "[" + data + "]";
}

bool StringElement::equals(Object *obj) {
    if (!instanceOf<StringElement>(obj)) return false; //is obj StringElement*?
    auto *objCity = dynamic_cast<StringElement *>(obj);
    return this->data == objCity->data; //are the strings equal?
}

long StringElement::hash() {
    return HashFunctions::hashString(data);
}
