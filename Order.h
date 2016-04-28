#ifndef ORDER_H
#define	ORDER_H

#include "Country.h"
#include "OrderSubGroup.h"
#include "Payment.h"

#include <string>
#include <vector>
using namespace std;

class Order {
public:
    Order( Country &country, int orderNumber );
    ~Order();
    bool isOrderNumberEquals( int orderNumber );
    void addItemsSet( ItemsSet* itemsSet );
    float calculateTotalWithTax();
    bool pay( float amount );
    bool isPaid();
private:
    vector<OrderSubGroup*> _subGroups;
    Country &_country;
    int _orderNumber;
    Payment _payment;
};

#endif	/* ORDER_H */

