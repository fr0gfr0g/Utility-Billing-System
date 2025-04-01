#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include "Customer.hpp"
#include "Provider.hpp"
#include "Transaction.hpp"
#include <vector>

class UIManager {
public:
    static void mainMenu(vector<Customer>& customers, vector<Provider>& providers) {
        int choice;
        do {
            cout << "\n----- Utility Billing System -----" << endl;
            cout << "1. Add Customer\n2. Add Provider\n3. Generate Bill\n4. Process Payment\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addCustomer(customers); break;
                case 2: addProvider(providers); break;
                case 3: generateCustomerBill(customers); break;
                case 4: processPayment(customers); break;
                case 5: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    }

private:
    static void addCustomer(vector<Customer>& customers) {
        int id;
        string name;
        cout << "Enter customer ID: ";
        cin >> id;
        cout << "Enter customer name: ";
        cin >> name;
        customers.push_back(Customer(id, name));
    }

    static void addProvider(vector<Provider>& providers) {
        int id;
        string name;
        cout << "Enter provider ID: ";
        cin >> id;
        cout << "Enter provider name: ";
        cin >> name;
        providers.push_back(Provider(id, name));
    }

    static void generateCustomerBill(vector<Customer>& customers) {
        int id;
        cout << "Enter customer ID: ";
        cin >> id;
        for (Customer& c : customers) {
            if (c.getCustomerID() == id) {
                c.generateBill();
                return;
            }
        }
        cout << "Customer not found!\n";
    }

    static void processPayment(vector<Customer>& customers) {
        int id;
        double amount;
        cout << "Enter customer ID: ";
        cin >> id;
        for (Customer& c : customers) {
            if (c.getCustomerID() == id) {
                cout << "Enter payment amount: ";
                cin >> amount;
                double totalBill = c.generateBill();
                Transaction t(c.getCustomerName(), totalBill, amount);
                FileManager::saveTransaction(t);
                cout << "Payment processed!\n";
                return;
            }
        }
        cout << "Customer not found!\n";
    }
};

#endif // UIMANAGER_HPP
