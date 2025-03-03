/* 
 * File:   BankAccount.h
 * Created on March 2, 2025, 4:18 AM
 */

// defining the class
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class BankAccount {
    
    public: // all the functions that will be used within the main program
        BankAccount(); // default constructor
        BankAccount(string,double); // constructor
        int generateNum(); // generates unique account number
        void deposit(double amount); // deposits money within the account
        void withdraw(double amount); // withdraws from the account
        int getBalance(); // retrieves the private variable balance and returns it
        void displayInfo(); // displays all the info about that account
        
    private: // all private variables that can be accessed by class member functions
        string accountHolderName;
        int accountNumber;
        double balance;
        

};

#endif /* BANKACCOUNT_H */

