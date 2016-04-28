#ifndef ORDERITEMSGROUP_H
#define	ORDERITEMSGROUP_H

#include "Item.h"
#include "ItemsSet.h"

#include <string>
#include <vector>
using namespace std;

class OrderSubGroup {
public:
    OrderSubGroup( Item itemPattern );
    ~OrderSubGroup();
    bool isForSameItem( ItemsSet* itemsSet );
    void addItemsSet( ItemsSet* itemsSet );
    float calculateSubTotalWithoutTax();
private:
    float calculateDiscountForQuantity( int quantity, float amount );

    vector<ItemsSet*> _itemSets;
    Item _itemPattern;
};

#endif	/* ORDERITEMSGROUP_H */

