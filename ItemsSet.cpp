#include "ItemsSet.h"
#include <sstream>
using namespace std;

ItemsSet::ItemsSet(Item item, int quantity, float price) : _item(item) {
    this->_quantity = quantity;
    this->_price = price;
}
Item ItemsSet::getItemPattern() {
    return this->_item;
}
float ItemsSet::calculateSubTotalWithoutTax() {
    return this->_price * this->_quantity;
}
int ItemsSet::getQuantity() {
    return this->_quantity;
}
string ItemsSet::toString() {
    ostringstream o;
    o << this->_item.toString() << " q:" << this->_quantity << " p:" << this->_price;
    return o.str();
}
