
#ifndef COUNTRYMONEYRULESPL_H
#define	COUNTRYMONEYRULESPL_H

#include "Country.h"
#include "CountryMoneyRules.h"

class CountryMoneyRulesPL : public CountryMoneyRules, public Country {
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

#endif	/* COUNTRYMONEYRULESPL_H */

