#include "PaymentCurrencyAmount.h"
#include <sstream>

PaymentCurrencyAmount::PaymentCurrencyAmount(float amount, Currency currency)
        : _currency( currency ) {
    this->_amount = amount;
}
string PaymentCurrencyAmount::toString() {
    ostringstream o;
    o << this->_amount << " " << this->_currency.toString();
    return o.str();
}
bool PaymentCurrencyAmount::operator <= (PaymentCurrencyAmount& ca) {
    // dla uproszczenia nie sprawdzamy zgodności walut
    return this->_amount <= ca._amount;
}
bool PaymentCurrencyAmount::operator >= (PaymentCurrencyAmount& ca) {
    // dla uproszczenia nie sprawdzamy zgodności walut
    return this->_amount >= ca._amount;
}