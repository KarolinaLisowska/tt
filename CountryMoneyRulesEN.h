#ifndef COUNTRYMONEYRULESEN_H
#define	COUNTRYMONEYRULESEN_H

#include "Country.h"
#include "CountryMoneyRules.h"

class CountryMoneyRulesEN : public CountryMoneyRules, public Country {
public:
    PaymentCurrencyAmount transferFromZloty( float amount );
    float calculateTax( float amount );
    PaymentCurrencyAmount getMinPaymentAmount();
    PaymentCurrencyAmount getMaxPaymentAmount();

    string getNameShortcut();
    Currency getCurrency();
    CountryMoneyRules& getCountryMoneyRules();
private:

};

#endif	/* COUNTRYMONEYRULESEN_H */

