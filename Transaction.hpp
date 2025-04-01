#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Represents a billing transaction for a customer
class Transaction {
private:
    string customerName;
    double amountDue;
    double amountPaid;
    time_t transactionDate;  // Stores the date of the transaction

public:
    // Constructor
    Transaction(string name, double due, double paid) 
        : customerName(name), amountDue(due), amountPaid(paid) {
        transactionDate = time(0);  // Set transaction date to current time
    }

    // Display transaction details
    void displayTransaction() const {
        cout << "Transaction for: " << customerName << endl;
        cout << "Amount Due: $" << amountDue << " | Amount Paid: $" << amountPaid << endl;
        cout << "Transaction Date: " << ctime(&transactionDate) << endl;
    }
};

#endif // TRANSACTION_HPP
