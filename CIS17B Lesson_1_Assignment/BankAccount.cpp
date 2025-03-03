/* 
 * File:   BankAccount.cpp
 * Purpose: Class that holds the user's information
 * Created on March 2, 2025, 4:18 AM
 */

#include "BankAccount.h"
#include <cstdlib> // for rand()
#include <ctime>   // for time()

BankAccount::BankAccount(){ // default constructor
    accountHolderName = "N/A";
    balance = 0;
}
BankAccount::BankAccount(string userN, double total) { // initializing account
    accountHolderName = userN;
    balance = total;
    accountNumber = rand() % 900 + 100;
}


// Method to display account details
void BankAccount::displayInfo(){
    cout << "\nAccount First Name: " << accountHolderName << endl;
    cout << "Account Number (Viewing Last Three Digits) : ..." << accountNumber << endl;
}

int BankAccount::generateNum(){ // last three digit generator for account number
    accountNumber = rand() % 1000;
    return accountNumber;
}

void BankAccount::deposit(double amount){ // deposit money into the account
    balance += amount;
    
}

void BankAccount::withdraw(double amount){ // withdraw money into the account
    balance -= amount;
}

int BankAccount::getBalance(){ // get money total from the account
    return balance;
}



