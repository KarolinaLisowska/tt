#include "OrderPackage.h"

OrderPackage::OrderPackage( Customer * customer ) {
    this->_customer = customer;
}

OrderPackage::~OrderPackage() {
    vector<Order*>::iterator it;
    for ( it = this->_orders.begin(); it != this->_orders.end(); it++ )
        delete (*it);
}

void OrderPackage::addItemsSet( int orderNbr, ItemsSet* itemsSet ) {
    vector<Order*>::iterator it;
    for ( it = this->_orders.begin(); it != this->_orders.end(); it++ )
        if ( (*it)->isOrderNumberEquals(orderNbr) ) {  /*** ADD ***/
            (*it)->addItemsSet(itemsSet);   /*** ADD ***/
            return;
        }
    /* nie znaleźliśmy tego numeru - dodajemy na koniec */
    Order * order = new Order( this->_customer->getCountry(), orderNbr );
    order->addItemsSet(itemsSet);  /*** ADD ***/
    this->_orders.push_back(order);
}
float OrderPackage::pay() {
    float totalPaid = 0.0;
    float totalNotPaid = 0.0;
    vector<Order*>::iterator it;
    for ( it = this->_orders.begin(); it != this->_orders.end(); it++ ){
        float amount = (*it)->calculateTotalWithTax(); /*** ADD ***/
        if ( (*it)->pay(amount) ) /*** ADD ***/
            totalPaid += amount;
        else
            totalNotPaid += amount;
    }
    return totalPaid;
}
