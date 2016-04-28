#ifndef COUNTRYMONEYRULES_H
#define	COUNTRYMONEYRULES_H

#include "Currency.h"
#include "PaymentCurrencyAmount.h"

class CountryMoneyRules {
public:
    virtual PaymentCurrencyAmount transferFromZloty( float amount ) = 0;
    virtual float calculateTax( float amount ) = 0;
    virtual PaymentCurrencyAmount getMaxPaymentAmount() = 0;
    virtual PaymentCurrencyAmount getMinPaymentAmount() = 0;
    virtual ~CountryMoneyRules() {}
private:

};

#endif	/* COUNTRYMONEYRULES_H */

