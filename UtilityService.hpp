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
    string getServiceName() const { return serviceName; }
    int getProviderID() const { return providerID; }
    double getBaseRate() const { return baseRate; }
    double getVariableRate() const { return variableRate; }
    double getMeterRate() const { return meterRate; }
};