#ifndef PAYMENTCHANNELPOSTOFFICE_H
#define	PAYMENTCHANNELPOSTOFFICE_H

#include "PaymentChannel.h"

class PaymentChannelPostOffice : public PaymentChannel{
public:
    PaymentChannelPostOffice();
    bool pay( PaymentCurrencyAmount currencyAmount );
private:

};

#endif	/* PAYMENTCHANNELPOSTOFFICE_H */

