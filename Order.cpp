#include "Order.h"
#include <iostream>
using namespace std;

Order::Order( Country &country, int orderNumber ) : _payment(country), _country(country) {
    this->_orderNumber = orderNumber;
    cout << "Creating order # " << this->_orderNumber << endl;
}
Order::~Order() {
   vector<OrderSubGroup*>::iterator it;
   for ( it = this->_subGroups.begin(); it != this->_subGroups.end(); it++ )
       delete (*it);
}
bool Order::isOrderNumberEquals( int orderNumber ) {
    return this->_orderNumber == orderNumber;
}
void Order::addItemsSet( ItemsSet* itemsSet ) { /*** !!! ***/
    vector<OrderSubGroup*>::iterator it;
    for ( it = this->_subGroups.begin(); it != this->_subGroups.end(); it++ )
        if ( (*it)->isForSameItem(itemsSet) ) { /*** ADD ***/
            (*it)->addItemsSet(itemsSet);  /*** ADD ***/
            cout << "Added itemSet " << itemsSet->toString() << endl;
            return;
        }
    /* nie znaleźliśmy tego typu - dodajemy na koniec */
    OrderSubGroup * orderSubGroup = new OrderSubGroup( itemsSet->getItemPattern() );
    orderSubGroup->addItemsSet(itemsSet); /*** ADD ***/
    cout << "Added itemSet " << itemsSet->toString() << endl;
    this->_subGroups.push_back(orderSubGroup); /*** ADD ***/
}
float Order::calculateTotalWithTax() {
    // wyliczamy sumy poszczególnych grup
    float total = 0.0;
    vector<OrderSubGroup*>::iterator it;
    for ( it = this->_subGroups.begin(); it != this->_subGroups.end(); it++ )
        total += (*it)->calculateSubTotalWithoutTax(); /*** ADD ***/

    float tax = this->_country.getCountryMoneyRules().calculateTax(total);
    /*** ADD ***/

    return total + tax;
}
bool Order::pay( float amount ) {
    if ( this->isPaid()) { /*** ADD ***/
        cout << "Order # " << this->_orderNumber << " already paid" << endl;
        return false;
    }
    cout << "About to pay for order # " << this->_orderNumber << endl;
    return this->_payment.pay(amount);    /*** ADD ***/
}
bool Order::isPaid() {
    return this->_payment.isPaid();
}
