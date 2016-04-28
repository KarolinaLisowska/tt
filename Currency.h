
#ifndef CURRENCY_H
#define	CURRENCY_H

#include <string>
using namespace std;

class Currency {
public:
    Currency(string name);
    string toString();
private:
    string _name;
};

#endif	/* CURRENCY_H */

