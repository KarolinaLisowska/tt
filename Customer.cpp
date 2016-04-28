#include "Customer.h"
#include "CountryMoneyRulesPL.h"
#include "CountryMoneyRulesEN.h"
#include <iostream>
using namespace std;

Customer::Customer(string firstName, string secondName, string countryShortcut) {
    this->_firstName = firstName;
    this->_secondName = secondName;
    /* nie korzystamy jeszcze z fabryk*/
    if (countryShortcut == "PL")
        this->_country = new CountryMoneyRulesPL();    
    else
        this->_country = new CountryMoneyRulesEN();
}
Customer::~Customer() {
    delete this->_country;
}
Country& Customer::getCountry() {
    return *this->_country;
}
string Customer::toString() {
    return this->_secondName + "_" + this->_firstName;
}
