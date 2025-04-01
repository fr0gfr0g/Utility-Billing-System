#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "UtilityService.hpp"
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <ctime>

using namespace std;

// The Customer class represents a residential customer who subscribes to utility services
class Customer {
private:
    int customerID;               // Unique customer ID
    string customerName;          // Customer's name
    vector<pair<UtilityService*, double>> subscribedServices; // List of services subscribed by the customer (along with usage)
    bool isPaymentOverdue = false; // Whether the customer's payment is overdue
    time_t billDate;              // The date when the last bill was generated

public:
    // Constructor to initialize the customer with a unique ID and name
    Customer(int id, string name) : customerID(id), customerName(name) {
        billDate = time(0);  // Set the current time as the bill generation date
    }

    // Method to add a new service subscription for the customer
    void addSubscription(UtilityService* service, double usage) {
        subscribedServices.push_back({ service, usage }); // Add the service with usage details
    }

    // Generate the customer's total bill based on the subscribed services and their usage
    double generateBill() {
        cout << "Bill for " << customerName << " (ID: " << customerID << ")" << endl;
        double totalBill = 0;
        for (auto& entry : subscribedServices) {
            double bill = entry.first->calculateBill(entry.second); // Calculate the bill for each service
            totalBill += bill; // Add the bill to the total
            cout << entry.first->getServiceName() << ": $" << bill << endl; // Display service bill
        }
        cout << "Total Bill: $" << totalBill << endl;

        return totalBill; // Return the total amount the customer needs to pay
    }

    // Check if the customer has an overdue payment based on the last bill date
    bool checkOverdue() {
        // Calculate how many days have passed since the bill was generated
        time_t currentTime = time(0);
        double secondsPassed = difftime(currentTime, billDate); // Get the difference in seconds
        double daysPassed = secondsPassed / (60 * 60 * 24); // Convert seconds to days

        if (daysPassed > 30) { // If more than 30 days have passed since the bill
            isPaymentOverdue = true;
            cout << "Customer " << customerName << " (ID: " << customerID << ") has overdue payment of "
                 << daysPassed - 30 << " days!" << endl; // Display overdue message
        }
        else {
            isPaymentOverdue = false;
            cout << "Customer " << customerName << " (ID: " << customerID << ") is up to date with payments." << endl; // No overdue
        }

        return isPaymentOverdue; // Return whether the customer has overdue payment
    }

    // Method to mark the customer as overdue (manual override)
    void markAsOverdue() {
        isPaymentOverdue = true;
    }
};

#endif // CUSTOMER_HPP
