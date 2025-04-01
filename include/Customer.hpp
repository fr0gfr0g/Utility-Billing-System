#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <vector>
#include <map>
#include "UtilityService.hpp"

using namespace std;

class Customer {
private:
    int customerID;
    string customerName;
    vector<pair<UtilityService*, double>> subscribedServices;
    bool isPaymentOverdue = false;

public:
    Customer(int id, string name) : customerID(id), customerName(name) {}

    void addSubscription(UtilityService* service, double usage) {
        subscribedServices.push_back({service, usage});
        cout << "Subscription to " << service->getServiceName() << " added with " << usage << " units." << endl;
    }

    void generateBill() {
        cout << "\nBill for " << customerName << " (ID: " << customerID << ")" << endl;
        double totalBill = 0;
        for (auto& entry : subscribedServices) {
            double bill = entry.first->calculateBill(entry.second);
            totalBill += bill;
            cout << entry.first->getServiceName() << " Usage: " << entry.second << " units, Bill: $" << bill << endl;
        }
        cout << "Total Bill: $" << totalBill << endl;
    }

    void checkOverdue(double overdueLimit = 30) {
        if (isPaymentOverdue) {
            cout << "Customer " << customerName << " (ID: " << customerID << ") has overdue payment!" << endl;
        } else {
            cout << "Customer " << customerName << " (ID: " << customerID << ") is up to date with payments." << endl;
        }
    }

    void markAsOverdue() {
        isPaymentOverdue = true;
    }

    void displaySubscriptions() {
        cout << "Subscribed services for " << customerName << " (ID: " << customerID << "):" << endl;
        for (auto& entry : subscribedServices) {
            cout << entry.first->getServiceName() << " - " << entry.second << " units" << endl;
        }
    }
};

#endif // CUSTOMER_HPP

