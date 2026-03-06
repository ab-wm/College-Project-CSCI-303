#include <comparator/IntegerDescendingComparator.h>

bool IntegerDescendingComparator::lessThan(int& a, int& b) {
  return b < a;
}

bool IntegerDescendingComparator::equals(int& a, int& b) {
  return a == b;
}