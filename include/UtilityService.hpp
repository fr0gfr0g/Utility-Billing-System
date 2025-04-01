#ifndef UTILITY_SERVICE_HPP
#define UTILITY_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// BASE CLASS for UtilityService///
class UtilityService {
protected:
    string serviceName; // service name
    int providerID;     // provider ID
    double baseRate;    // fixed rate
    double meterRate;   // rate per unit consumed

public:
    // Constructor with parameters for service name, provider ID, base rate, and meter rate
    UtilityService(string name, int pID, double base, double meter)
        : serviceName(name), providerID(pID), baseRate(base), meterRate(meter) {}

	//Destructor
	virtual ~UtilityService() {}

    // Pure virtual function for billing (must be implemented by derived classes)
    virtual double calculateBill(double usage) = 0;

    // Getter function for returning service name
    string getServiceName() const {
        return serviceName;
    }

    // Display service details
    virtual void displayServiceDetails() {
        cout << "Service: " << serviceName << ", Provider: " << providerID
             << ", Base Rate: $" << baseRate << ", Meter Rate: $" << meterRate << endl;
    }
};

#endif // UTILITY_SERVICE_HPP

