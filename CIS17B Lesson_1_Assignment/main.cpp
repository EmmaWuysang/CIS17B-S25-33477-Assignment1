/* 
 * File:   main.cpp
 * Author: Emma Wuysang
 * Creator Notes: Works as required and implemented rand acc generator.
 *                  Handling was just a bit repetitive, maybe in V2. would make those functions instead.
 * Created on March 2, 2025 3:54 AM
 * Purpose: Develop a Simple Banking System
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <limits>  // For numeric_limits
#include <string> // to utilize the strings
#include <vector> // to utilize vectors
#include "BankAccount.h" // to access the other class BankAccount
using namespace std;

//Program Execution Begins Here
int main() {
    srand(time(0)); // for random num generator
    
    // Variables
    int slctn; // selection tool for menu
    double initialD; // initial deposit
    double amount; // amount to deposit
    string userN; // entered name for account
    
    // Objects and All Relevant to Vector
    vector<BankAccount> allAccounts; // sets up vector for multiple accounts
    int accountIndex = -1; // Vector index for allAccounts
    
    // Beginning & Menu
    cout<<"Welcome to Simple Bank System\n";
    while(slctn!=6){
        // menu for banking program
        cout << "1. Create Account\n"
        << "2. Deposit Money\n"
        << "3. Withdraw Money\n"
        << "4. Check Balance\n"
        << "5. View/Select Account\n"
        << "6. Exit\n\n"
        << "Enter your choice: ";
        cin>>slctn; // selection
        
        if (cin.fail()){ // USER INPUT HANDLING.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was not a number. OPTIONS (1-6) \n";
        }
        
        switch (slctn){
            case 1: // CREATE ACCOUNT
                cout<<"Enter account holder name: ";
                cin.ignore();
                getline(cin, userN);
                cout<<"Enter initial deposit: ";
                while(!(cin>> initialD) || initialD < 0){ // If deposit is not a valid number
                    cout << "Unsuccessful Deposit. Try again! Your initial deposit must be a numerical value greater than zero. \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the input from cin & clears/moves forward 
                }
                allAccounts.push_back(BankAccount(userN,initialD)); // puts the object into the vector
                accountIndex += 1; // manually selects the most recent account.
               
                cout<<"\nAccount created successfully!\n\n";
                break; // end of case 1
     
                
            case 2: // DEPOSIT
                if(allAccounts.empty()){ // if user hasn't created at least one account
                    cout<<"You have to create an account first.\n";
                }
                cout << "Enter amount to deposit: ";
                try { // try and catch for false user input
                    cin>>amount; //deposit amount
                    
                    
                    if (cin.fail()){ // USER INPUT HANDLING.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Unsuccessful Deposit. That was not a number.\n";
                    }
                    else if (amount<=0){
                            throw (amount);
                        }
                    else{
                        
                        // if no issues exist
                        allAccounts[accountIndex].deposit(amount);
                        cout<<"Deposit successful! New balance: $" << allAccounts[accountIndex].getBalance() << endl << endl; // reaches with the current index to the vector and retrieves the fixed balance
                    }
                }
                catch (double depA){
                    cout<< "Error. Number cannot be negative! Attempt was unsuccessful. \n\n";
                }
                break; // end of case 2
                
                
            case 3: // WITHDRAW
                if(allAccounts.empty()){
                    cout<<"You have to create an account first.\n";
                }
                else{
                    cout << "Enter amount to withdraw: ";
                    try {
                        cin>>amount; //deposit amount
                        

                        if (cin.fail()){ // USER INPUT TYPE-HANDLING.
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Unsuccessful Deposit. That was not a number.\n";
                        }
                        else if (amount>allAccounts[accountIndex].getBalance()){
                                throw (amount);
                            }
                        else{
                            // if no issues exist, will call to member function and change the amount
                            allAccounts[accountIndex].withdraw(amount);
                            cout<<"Withdraw successful! New balance: $" << allAccounts[accountIndex].getBalance() << endl << endl;
                        }
                    }
                    catch (double depA){ // user requested more or chose a negative for their values
                        cout<< "Insufficient Funds! \n\n";
                    }
                }
                break; // end of case 3
                
                
            case 4: // CHECK BALANCES
                if(allAccounts.empty()==false){
                cout<<"Current balance: $"<<allAccounts[accountIndex].getBalance()<<"\n\n"; // previews the balance by calling to member function
                }
                 
                break; // end of case 4
                
                
            case 5: // VIEW AND SELECT AN ACCOUNT
                cout << "This is where you can preview and select all your account(s).\n";
                cout<<"_______________________________________________________________________\n";
                if (allAccounts.empty()){
                    cout<<"You have not made any accounts, there is nothing to view.\n";
                }
                else{
                    int i = 1;
                    // THIS IS TO CHECK THE ACCOUNTS MADE
                    for (auto& account : allAccounts) { // basically loops through the vector to display all their info through calling the member function displayInfo
                        cout<<"OPTION "<<i<<" :";
                        account.displayInfo();
                        i +=1;
                        cout<<endl;
                    }

                    cout<<"Which account would you like to select? Enter the correlating option number. \n";
                    cin>>accountIndex; // corrects the index to properly adjust the specific account
                   
                    if (accountIndex <= allAccounts.size()){
                        cout<<"Successfully selected Option: " << accountIndex <<endl;
                        accountIndex = accountIndex-1; // indexes the correct choice for user
                    }
                    else{
                        cout<<"The account you chose was not possible, staying with the most recently made account.\n";
                        accountIndex = allAccounts.size()-1;  // if the user selects an invalid option, it automatically goes to the account most recently made
                    }
                }
                cout<<"_______________________________________________________________________\n";

                break; // end of case 5
                
            case 6: cout<<"Thank you for using Simple Bank System!\n"; break; // exiting the menu
        
            default: cout << "Oh no! You choose an invalid choice, please try again. \n\n"; // if the user enters a non-numerical value.
        }
    }
    
    //Exit the program
    return 0;
}