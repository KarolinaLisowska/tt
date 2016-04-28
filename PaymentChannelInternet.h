#ifndef PAYMENTCHANNELINTERNET_H
#define	PAYMENTCHANNELINTERNET_H

#include "PaymentChannel.h"

class PaymentChannelInternet : public PaymentChannel{
public:
    PaymentChannelInternet();
    bool pay( PaymentCurrencyAmount currencyAmount );
private:

};

#endif	/* PAYMENTCHANNELINTERNET_H */

