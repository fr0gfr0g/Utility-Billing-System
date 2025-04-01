#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Customer.hpp"
#include "Provider.hpp"
#include <map>

class Database {
private:
    map<int, Customer*> customers;  // Customer ID -> Customer object
    map<int, Provider*> providers;  // Provider ID -> Provider object

public:
    // Add a new customer
    void addCustomer(Customer* customer) {
        customers[customer->getCustomerID()] = customer;
    }

    // Retrieve a customer by ID
    Customer* getCustomer(int customerID) {
        if (customers.find(customerID) != customers.end()) {
            return customers[customerID];
        }
        return nullptr;
    }

    // Add a provider
    void addProvider(Provider* provider) {
        providers[provider->getProviderID()] = provider;
    }

    // Retrieve a provider by ID
    Provider* getProvider(int providerID) {
        if (providers.find(providerID) != providers.end()) {
            return providers[providerID];
        }
        return nullptr;
    }

    // Display all customers
    void displayCustomers() {
        for (auto& entry : customers) {
            cout << "Customer ID: " << entry.first << " - Name: " << entry.second->getCustomerName() << endl;
        }
    }
};

#endif // DATABASE_HPP
