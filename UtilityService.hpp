<<<<<<< Updated upstream
// UtilityService.hpp

#include <string>
#include <ctime>

using namespace std;

class UtilityService {
protected:
    string serviceName; // variable initializations
    int providerID;     // ID, fixed charge, and per unit charge
    double baseRate;    // fixed monthly rate
    double meterRate;   // fixed meter charge
    double variableRate // rate per unit consumed

public:
    // Constructor with parameters for service name, provider ID, base rate, and meter rate
    UtilityService(string name, int pID, double base, double variable, double meter)
        : serviceName(name), providerID(pID), baseRate(base), variableRate(variable), meterRate(meter) {}

    // Polymorphic deconstructor
    virtual ~UtilityService() {}

    // Virtual function for calculating bill for a given consumption (to be overwritten by derived classes)
    virtual double calculateBill(double unitsConsumed) {
        return baseRate + (variableRate * unitsConsumed) + meterRate;
    }

    // Getter methods for each variable
=======
#ifndef UTILTIYSERVICE_HPP
#define UTILTIYSERVICE_HPP

#include <string>
#include <iostream>

using namespace std;

// The UtilityService class represents a general utility service (such as gas, internet, or hydro)
class UtilityService {
protected:
    string serviceName;  // The name of the service (e.g., Natural Gas, Internet, etc.)
    int providerID;      // The unique ID of the service provider
    double baseRate;     // A fixed monthly fee for the service
    double meterRate;    // A fixed rate for the meter (if applicable)
    double variableRate; // A rate that varies based on usage (e.g., per kWh for electricity)

public:
    // Constructor to initialize the service details
    UtilityService(string name, int pID, double base, double variable, double meter)
        : serviceName(name), providerID(pID), baseRate(base), variableRate(variable), meterRate(meter) {}

    // Virtual destructor to allow derived classes to clean up resources
    virtual ~UtilityService() {}

    // The default bill calculation, which can be customized by derived classes
    virtual double calculateBill(double unitsConsumed) {
        // Basic formula: Fixed rate + Variable rate based on consumption + Meter charge
        return baseRate + (variableRate * unitsConsumed) + meterRate;
    }

    // Display basic details of the service (this can be overridden by derived classes)
    virtual void displayServiceDetails() const {
        cout << serviceName << " Service - Provider " << providerID
             << ": Base Rate = $" << baseRate << ", Meter Rate = $" << meterRate << ", Variable Rate = $" << variableRate << endl;
    }

    // Getter methods for retrieving service details
>>>>>>> Stashed changes
    string getServiceName() const { return serviceName; }
    int getProviderID() const { return providerID; }
    double getBaseRate() const { return baseRate; }
    double getVariableRate() const { return variableRate; }
    double getMeterRate() const { return meterRate; }
<<<<<<< Updated upstream
};
=======
};

#endif // UTILTIYSERVICE_HPP
>>>>>>> Stashed changes
