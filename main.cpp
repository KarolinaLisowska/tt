#include "Customer.h"
#include "ItemsSet.h"
#include "OrderPackage.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;


int main(int argc, char** argv) {
    map<string, Customer*> customers;
    map<string, Customer*>::iterator itC;

    map<string, OrderPackage*> packages;
    map<string, OrderPackage*>::iterator itP;

    Customer *foundCustomer;
    OrderPackage *foundPackage;

    customers["Tokar"] = new Customer( "Marcin", "Tokar", "PL");
    customers["Omiotek"] = new Customer( "Piotr", "Omiotek", "PL");
    customers["Smith"] = new Customer( "John", "Smith", "EN");

    ifstream orderFile;
    string filename = "orders.txt";
    orderFile.open("orders.txt");
    if(!orderFile.good()){
        cout << "FILE READ ERROR!!! " << endl;
        return 0;
    }

    string fname, lname, product;
    int orderNbr, quantity;
    float price;

    orderFile >> lname;
    while(!orderFile.eof() ) {
        //nazwisko imie #zamówienia ilość product cena_jedn
        orderFile >> fname >> orderNbr >> quantity >> product >> price;
        itC = customers.find( lname );
        if ( itC != customers.end() ){/*found customer*/
            foundCustomer = itC->second;

            itP = packages.find( foundCustomer->toString() );
            if ( itP != packages.end() )/*found customer's package*/
                foundPackage = itP->second;
            else {
                cout << "adding package for " << foundCustomer->toString() << endl;
                foundPackage = new OrderPackage( foundCustomer );
                packages[ foundCustomer->toString() ] = foundPackage;
            }

            foundPackage->addItemsSet( orderNbr, new ItemsSet( Item(product), quantity, price ) );
        }
        else
            cout << lname << " not found" << endl;

        orderFile >> lname;
    }
    orderFile.close();

    for ( itP = packages.begin(); itP != packages.end(); itP++ ){
        float amount = itP->second->pay();
        cout << itP->first << " paid in total: " << amount << endl;
    }

    for ( itP = packages.begin(); itP != packages.end(); itP++ )
        delete itP->second;
    for ( itC = customers.begin(); itC != customers.end(); itC++ )
        delete itC->second;

    return 0;
}

