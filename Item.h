#ifndef ITEM_H
#define	ITEM_H

#include <string>
using namespace std;

class Item {
public:
    Item( string name );
    bool operator == ( Item item );
    string toString();
private:
    string _name;
};

#endif	/* ITEM_H */

