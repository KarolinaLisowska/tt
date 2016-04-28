#include "OrderSubGroup.h"
#include <iostream>
using namespace std;

OrderSubGroup::OrderSubGroup( Item itemPattern ) : _itemPattern(itemPattern) {
    cout << "Creating subgroup for itempattern " << itemPattern.toString() << endl;
}
OrderSubGroup::~OrderSubGroup(){
    vector<ItemsSet*>::iterator it;
    for ( it = this->_itemSets.begin(); it != this->_itemSets.end(); it++ )
        delete (*it);
}

void OrderSubGroup::addItemsSet( ItemsSet* itemsSet ) {
    if ( this->isForSameItem(itemsSet) )//podgrupa pasuje
        this->_itemSets.push_back(itemsSet); /*** ADD ***/
    else
        cout << "Can't add itemsSet. Item = " << itemsSet->getItemPattern().toString() <<
                " pattern = " << this->_itemPattern.toString();
}
bool OrderSubGroup::isForSameItem( ItemsSet* itemsSet) {
    return this->_itemPattern == itemsSet->getItemPattern();
}
float OrderSubGroup::calculateSubTotalWithoutTax() {
    float total = 0.0;
    int quantity = 0;
    vector<ItemsSet*>::iterator it;
    for ( it = this->_itemSets.begin(); it != this->_itemSets.end(); it++ ) {
        total += (*it)->calculateSubTotalWithoutTax(); /*** ADD ***/
        quantity += (*it)->getQuantity(); /*** ADD ***/
    }
    float discount = this->calculateDiscountForQuantity( quantity, total );

    return total - discount;
}
float OrderSubGroup::calculateDiscountForQuantity( int quantity, float amount ) {
    // jeszcze nie przerobiliśmy strategii
    if (this->_itemPattern == Item("lustro") ){
        if ( quantity > 10 )
            return amount * 0.08; //znizka /*** ADD ***/
        //else  /*** ADD ***/
          //  if ( quantity > 20 )
             //   return ...; //znizka*/
    }

    return 0.0;
}

