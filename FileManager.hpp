#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <vector>
#include "Customer.hpp"
#include "Transaction.hpp"

class FileManager {
public:
    // Save customer billing history
    static void saveTransaction(const Transaction& transaction) {
        ofstream outFile("transactions.txt", ios::app);
        if (outFile) {
            outFile << transaction.getCustomerName() << "," 
                    << transaction.getAmountDue() << "," 
                    << transaction.getAmountPaid() << "," 
                    << time(0) << endl;
        }
        outFile.close();
    }

    // Load previous transactions
    static void loadTransactions() {
        ifstream inFile("transactions.txt");
        string name;
        double due, paid;
        time_t date;

        while (inFile >> name >> due >> paid >> date) {
            cout << "Customer: " << name << " | Due: $" << due 
                 << " | Paid: $" << paid << " | Date: " << ctime(&date) << endl;
        }
        inFile.close();
    }
};

#endif // FILEMANAGER_HPP
