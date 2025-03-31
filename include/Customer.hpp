#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <vector>
#include <map>
#include "UtilityService.hpp"

class Customer {
public:
    int customerID;
    std::string customerName;
    std::vector<std::pair<UtilityService*, double>> subscribedServices;
    bool isPaymentOverdue = false;

    Customer(int id, std::string name) : customerID(id), customerName(name) {}

    void addSubscription(UtilityService* service, double usage) {
        subscribedServices.push_back({service, usage});
        std::cout << "Subscription to " << service->getServiceName() << " added with " << usage << " units." << std::endl;
    }

    void generateBill() {
        std::cout << "\nBill for " << customerName << " (ID: " << customerID << ")" << std::endl;
        double totalBill = 0;
        for (auto& entry : subscribedServices) {
            double bill = entry.first->calculateBill(entry.second);
            totalBill += bill;
            std::cout << entry.first->getServiceName() << " Usage: " << entry.second << " units, Bill: $" << bill << std::endl;
        }
        std::cout << "Total Bill: $" << totalBill << std::endl;
    }

    void checkOverdue(double overdueLimit = 30) {
        if (isPaymentOverdue) {
            std::cout << "Customer " << customerName << " (ID: " << customerID << ") has overdue payment!" << std::endl;
        } else {
            std::cout << "Customer " << customerName << " (ID: " << customerID << ") is up to date with payments." << std::endl;
        }
    }

    void markAsOverdue() {
        isPaymentOverdue = true;
    }

    void displaySubscriptions() {
        std::cout << "Subscribed services for " << customerName << " (ID: " << customerID << "):" << std::endl;
        for (auto& entry : subscribedServices) {
            std::cout << entry.first->getServiceName() << " - " << entry.second << " units" << std::endl;
        }
    }
};

#endif // CUSTOMER_HPP

