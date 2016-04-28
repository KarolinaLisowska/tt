#include "PaymentChannelInternet.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

PaymentChannelInternet::PaymentChannelInternet() {
}
bool PaymentChannelInternet::pay( PaymentCurrencyAmount currencyAmount ) {
    cout << "Sending via internet amount; " << currencyAmount.toString() << endl;
    int err = 1;
    if ( err ) {
        cout << "Connection problem - waiting 5 sec..." << endl;
        cout.flush();
       // sleep(5);
        cout << "Sending via internet amount; " << currencyAmount.toString() << endl;
    }
    return true;
}

