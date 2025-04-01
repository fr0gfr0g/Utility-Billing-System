<<<<<<< Updated upstream
// InternetService.hpp
#include "UtilityService.hpp"
#include <vector>

using namespace std;

class InternetService : public UtilityService {
protected:
	double dataCapGB;				// data cap in GB (0 for unlimited)
	double overageFeePerGB;			// fee for each GB over limit
	vector<string> bundledServices; // names of services bundled with this

public:
	// Constructor allows different pricing per provider
	InternetService(string name, int pID, double base, double variable, double meter, double dataCap, double overageFee)
		: UtilityService("Internet", pID, base, meter), dataCapGB(dataCap), overageFeePerGB(overageFee){}

	// Virtual deconstructor
	virtual ~InternetService() {}

	// Method to calculate bill for Internet Service
	double calculateBill(double dataUsedGB) const override {
		double baseCharge = UtilityService::calculateBill(dataUsedGB);

		if (dataCapGB > 0 && dataUsedGB > dataCapGB) {
			double overage = dataUsedGB - dataCapGB;
			baseCharge += overage * overageFeePerGB;
		}

		return baseCharge;
	}

	// Method to add a bundled service (TV, Home Phone, Mobile Phone)
	void addBundledService(string& serviceName) const {
		bundledServices.push_back(serviceName);
	}

	// Method to check if a bundled service is included
	void hasBundledService(string& serviceName) const {
		for (const auto& service : bundledServices) {
			if (service == bundledServices) return true;
		}
		return false;
	}

	// Getter methods
	double getDataCap() const { return dataCapGB; }
	double getOverageFee() const { return overageFeePerGB; }
};
=======
#ifndef INTERNETSERVICE_HPP
#define INTERNETSERVICE_HPP

#include "UtilityService.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// The InternetService class represents a specific utility service for internet with features like data cap and overage fees
class InternetService : public UtilityService {
protected:
    double dataCapGB;              // Data cap in GB (0 means unlimited)
    double overageFeePerGB;        // Overage fee for each GB used over the cap
    vector<string> bundledServices; // List of bundled services (e.g., TV, Home Phone, Mobile Phone)

public:
    // Constructor to initialize the InternetService with pricing and service details
    InternetService(string name, int pID, double base, double variable, double meter, double dataCap, double overageFee)
        : UtilityService(name, pID, base, variable, meter), dataCapGB(dataCap), overageFeePerGB(overageFee) {}

    // Virtual destructor (for proper cleanup of derived class objects)
    virtual ~InternetService() {}

    // Method to calculate the bill for Internet Service
    double calculateBill(double dataUsedGB) const override {
        // Calculate the basic bill first using inherited method
        double baseCharge = UtilityService::calculateBill(dataUsedGB);

        // Check if the customer exceeded their data cap
        if (dataCapGB > 0 && dataUsedGB > dataCapGB) {
            // Add overage charges for the data used beyond the cap
            double overage = dataUsedGB - dataCapGB;
            baseCharge += overage * overageFeePerGB;
        }

        return baseCharge; // Return the final bill after considering overage charges
    }

    // Method to add a bundled service (e.g., TV, Home Phone, Mobile Phone) to the Internet service
    void addBundledService(const string& serviceName) {
        bundledServices.push_back(serviceName); // Add the service to the list of bundled services
    }

    // Method to check if a specific service is included in the bundled services
    bool hasBundledService(const string& serviceName) const {
        for (const auto& service : bundledServices) {
            if (service == serviceName) {
                return true; // Return true if the service is found in the bundle
            }
        }
        return false; // Return false if the service is not in the bundle
    }

    // Getter methods to access the data cap and overage fee
    double getDataCap() const { return dataCapGB; }
    double getOverageFee() const { return overageFeePerGB; }
};

#endif // INTERNETSERVICE_HPP
>>>>>>> Stashed changes
