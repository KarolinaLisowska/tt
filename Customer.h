#ifndef CUSTOMER_H
#define	CUSTOMER_H

#include "Country.h"
#include <string>
using namespace std;

class Customer {
public:
    Customer( string firstName, string secondName, string countryShortcut );
    Country &getCountry();
    string toString();
    virtual ~Customer();
private:
    string _firstName;
    string _secondName;
    Country * _country;
};

#endif	/* CUSTOMER_H */

