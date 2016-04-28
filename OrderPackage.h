#ifndef ORDERPACKAGE_H
#define	ORDERPACKAGE_H

#include "Order.h"
#include "Customer.h"
#include <vector>
using namespace std;

class OrderPackage {
public:
    OrderPackage( Customer * customer );
    virtual ~OrderPackage();
    void addItemsSet( int orderNbr, ItemsSet* itemsSet );
    float pay();
private:
    Customer *_customer;
    vector<Order*> _orders;
};

#endif	/* ORDERPACKAGE_H */

