#include "CountryMoneyRulesPL.h"

PaymentCurrencyAmount CountryMoneyRulesPL::transferFromZloty( float amount ) {
    return PaymentCurrencyAmount( amount, this->getCurrency() );
}
float CountryMoneyRulesPL::calculateTax( float amount ) {
    if (amount > 400)
        return amount * 0.3; //30% podatku
    else
        return amount * 0.2; //20% podatku
}
PaymentCurrencyAmount CountryMoneyRulesPL::getMaxPaymentAmount() {
    return PaymentCurrencyAmount( 6000, this->getCurrency() );;
}
PaymentCurrencyAmount CountryMoneyRulesPL::getMinPaymentAmount() {
    return PaymentCurrencyAmount( 10, this->getCurrency() );;
}
string CountryMoneyRulesPL::getNameShortcut() {
    return "PL";
}
Currency CountryMoneyRulesPL::getCurrency() {
    return Currency( "PLN" );
}
CountryMoneyRules& CountryMoneyRulesPL::getCountryMoneyRules() {
    return *this;
}
