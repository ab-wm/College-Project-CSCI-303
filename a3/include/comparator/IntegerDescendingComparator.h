
#ifndef INTEGERDESCENDINGCOMPARATOR_H
#define INTEGERDESCENDINGCOMPARATOR_H

#include <comparator/Comparator.h>

class IntegerDescendingComparator : public Comparator<int> {

    bool lessThan(int& a, int& b) override;

    bool equals(int& a, int& b) override;

};


#endif //INTEGERDESCENDINGCOMPARATOR_H
