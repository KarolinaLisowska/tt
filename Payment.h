#ifndef PAYMENT_H
#define	PAYMENT_H

#include "Country.h"

class Payment {
public:
    Payment( Country &country );
    bool isPaymentPossible( float amount );
    bool pay( float amount );
    bool isPaid();
private:
    float _amount;
    float _currencyAmount;
    bool _isPaid;
    Country &_country;
};

#endif	/* PAYMENT_H */

