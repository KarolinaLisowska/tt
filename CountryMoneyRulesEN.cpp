#include "CountryMoneyRulesEN.h"

PaymentCurrencyAmount CountryMoneyRulesEN::transferFromZloty( float amount ) {
    float rate = (1.0 / 6.0) * 0.95; //obniżamy o 5%
    return PaymentCurrencyAmount( amount * rate, this->getCurrency() );
}
float CountryMoneyRulesEN::calculateTax( float amount ) {
    return amount * 0.4; //40% podatku
}
PaymentCurrencyAmount CountryMoneyRulesEN::getMaxPaymentAmount() {
    return PaymentCurrencyAmount( 1200, this->getCurrency() );;
}
PaymentCurrencyAmount CountryMoneyRulesEN::getMinPaymentAmount() {
    return PaymentCurrencyAmount( 10, this->getCurrency() );;
}
string CountryMoneyRulesEN::getNameShortcut() {
    return "EN";
}
Currency CountryMoneyRulesEN::getCurrency() {
    return Currency( "GBP" );
}
CountryMoneyRules& CountryMoneyRulesEN::getCountryMoneyRules() {
    return *this;
}
