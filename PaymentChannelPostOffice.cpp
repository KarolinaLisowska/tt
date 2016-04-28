#include "PaymentChannelPostOffice.h"

#include <iostream>
using namespace std;

PaymentChannelPostOffice::PaymentChannelPostOffice() {
}
bool PaymentChannelPostOffice::pay( PaymentCurrencyAmount currencyAmount ) {
    cout << "Sending at Post Office amount: " << currencyAmount.toString() << endl;
    return true;
}

