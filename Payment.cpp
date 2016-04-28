#include "Payment.h"
#include "PaymentChannel.h"
#include "PaymentChannelInternet.h"
#include "PaymentChannelPostOffice.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

Payment::Payment( Country &country ) : _country(country) {
    this->_isPaid = false;
}
bool Payment::isPaymentPossible( float amount ) {
    PaymentCurrencyAmount currencyAmount
                = this->_country.getCountryMoneyRules().transferFromZloty(amount); /*** ADD ***/
    PaymentCurrencyAmount maxCurrencyAmount
                = this->_country.getCountryMoneyRules().getMinPaymentAmount();
    PaymentCurrencyAmount minCurrencyAmount
                = this->_country.getCountryMoneyRules().getMinPaymentAmount();

    return !this->_isPaid &&
           currencyAmount <= maxCurrencyAmount &&
           currencyAmount >= minCurrencyAmount;

}
bool Payment::pay( float amount ) {
    PaymentCurrencyAmount currencyAmount
            = this->_country.getCountryMoneyRules().transferFromZloty(amount);

    if ( this->isPaymentPossible(amount)) { /*** ADD ***/
        srand (time(NULL));

        PaymentChannel * payChannel;
        if ( rand() % 7 == 0 )//sunday
            payChannel = new PaymentChannelPostOffice();
        else
            payChannel = new PaymentChannelInternet();

        payChannel->pay(currencyAmount);        /*** ADD ***/

        this->_isPaid = true;
        return true;
    }
    else {
        cout << "Payment for amount " << currencyAmount.toString() << " not possible" << endl;
    }
    return false;
}
bool Payment::isPaid() {
    return this->_isPaid;
}


