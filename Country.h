#ifndef COUNTRY_H
#define	COUNTRY_H

#include <string>
#include "Currency.h"
#include "CountryMoneyRules.h"

using namespace std;

class Country {
public:
    virtual string getNameShortcut() = 0;
    virtual Currency getCurrency() = 0;
    virtual CountryMoneyRules& getCountryMoneyRules() = 0;
    virtual ~Country() {};
private:
};

#endif	/* COUNTRY_H */

