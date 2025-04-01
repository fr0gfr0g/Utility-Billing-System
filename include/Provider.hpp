#ifndef PROVIDER_HPP
#define PROVIDER_HPP

#include <iostream>
#include <vector>
#include "UtilityService.hpp"

using namespace std;

class Provider {
public:
    int providerID;
    string providerName;
    vector<UtilityService*> services;

    // Constructor definition
    Provider(int id, string name) : providerID(id), providerName(name) {}

    // Method to add service
    void addService(UtilityService* service) {
        services.push_back(service);
    }

    // Method to display provider details
    void displayProviderDetails() {
        cout << "Provider ID: " << providerID << ", Name: " << providerName << endl;
        for (auto service : services) {
            service->displayServiceDetails();
        }
    }

    //Getter
	vector<UtilityService*> getServices() const { return services; }
};

#endif // PROVIDER_HPP

