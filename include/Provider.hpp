#ifndef PROVIDER_HPP
#define PROVIDER_HPP

#include <iostream>
#include <vector>
#include "UtilityService.hpp"

class Provider {
public:
    int providerID;
    std::string providerName;
    std::vector<UtilityService*> services;

    // Constructor definition
    Provider(int id, std::string name) : providerID(id), providerName(name) {}

    // Method to add service
    void addService(UtilityService* service) {
        services.push_back(service);
    }

    // Method to display provider details
    void displayProviderDetails() {
        std::cout << "Provider ID: " << providerID << ", Name: " << providerName << std::endl;
        for (auto service : services) {
            service->displayServiceDetails();
        }
    }
};

#endif // PROVIDER_HPP

