#ifndef HYDROSERVICE_HPP
#define HYDROSERVICE_HPP

#include "UtilityService.hpp"  // Including the base class for utility services

// HydroService represents a specific type of utility service, such as Electricity, Water, or Sewerage
class HydroService : public UtilityService {
public:
    // Constructor to initialize the specific hydro service details
    HydroService(string type, int pID, double base, double meter, double variable = 0.0) 
        : UtilityService(type, pID, base, variable, meter) {}

    // Calculate the bill for hydro services, using the basic rates (meter + variable)
    double calculateBill(double usage) override {
        // The bill calculation could vary depending on the service type. 
        // For Hydro services, it's a combination of meter rate and usage.
        return baseRate + (variableRate * usage) + (meterRate * usage);
    }

    // Display details about the specific hydro service (e.g., Electricity, Water, Sewerage)
    void displayServiceDetails() const override {
        cout << getServiceName() << " Service - Provider " << providerID
             << ": Base Rate = $" << baseRate << ", Per Unit = $" << meterRate << ", Variable Rate = $" << variableRate << endl;
    }
};

#endif // HYDROSERVICE_HPP
