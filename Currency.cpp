#include "Currency.h"

Currency::Currency(string name) {
    this->_name = name;
}

string Currency::toString() {
    return this->_name;
}

