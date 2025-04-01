//Provider.hpp
#ifndef PROVIDER_HPP
#define PROVIDER_HPP

#include "UtilityService.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// The Provider class represents a utility provider (e.g., a company offering gas, electricity, etc.)
class Provider {
private:
    int providerID;          // Unique provider ID
    string providerName;     // Name of the service provider (e.g., XYZ Energy)
    vector<UtilityService*> services; // List of utility services provided by this provider

public:
    // Constructor to initialize the provider with an ID and name
    Provider(int id, string name) : providerID(id), providerName(name) {}

    // Method to add a new service that this provider offers
    void addService(UtilityService* service) {
        services.push_back(service); // Add the service to the provider's list
    }

    // Getters to access provider details
    int getProviderID() const { return providerID; }
    string getProviderName() const { return providerName; }

    // Get a specific service offered by this provider, based on the index
    UtilityService* getService(int index) const {
        if (index >= 0 && index < services.size()) {
            return services[index]; // Return the service if the index is valid
        }
        else {
            cout << "Error: Invalid index for service." << endl; // Handle invalid index
            return nullptr;
        }
    }

    // Method to list all services offered by this provider
    void listServices() const {
        cout << "Services offered by " << providerName << " (ID: " << providerID << "):" << endl;
        for (size_t i = 0; i < services.size(); ++i) {
            cout << i + 1 << ". " << services[i]->getServiceName() << endl; // Display each service
        }
    }
};

#endif // PROVIDER_HPP