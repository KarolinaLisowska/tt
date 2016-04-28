#ifndef PAYMENTCHANNEL_H
#define	PAYMENTCHANNEL_H

#include "PaymentCurrencyAmount.h"

class PaymentChannel {
public:
    virtual bool pay( PaymentCurrencyAmount currencyAmount ) = 0;
};


#endif	/* PAYMENTCHANNEL_H */

