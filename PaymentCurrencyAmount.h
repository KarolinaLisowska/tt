#ifndef CURRENCYAMOUNT_H
#define	CURRENCYAMOUNT_H

#include "Currency.h"
#include <string>
using namespace std;

class PaymentCurrencyAmount {
public:
    PaymentCurrencyAmount( float amount, Currency currency );
    bool operator <= ( PaymentCurrencyAmount& );
    bool operator >= ( PaymentCurrencyAmount& );
    bool operator == (PaymentCurrencyAmount&);
    string toString();
private:
    float _amount;
    Currency _currency;
};

#endif	/* CURRENCYAMOUNT_H */

