#include "Item.h"

Item::Item( string name ) {
    this->_name = name;
}
bool Item::operator == ( Item item ) {
    return this->_name == item._name;
}
string Item::toString() {
    return this->_name;
}
