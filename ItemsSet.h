#ifndef ITEMSORDERGROUP_H
#define	ITEMSORDERGROUP_H

#include "Item.h"

class ItemsSet {
public:
    ItemsSet(Item item, int quantity, float price);
    Item getItemPattern();
    float calculateSubTotalWithoutTax();
    int getQuantity();
    string toString();
private:
    int _quantity;
    float _price;
    Item _item;
};

#endif	/* ITEMSORDERGROUP_H */

