#ifndef INTERNET_SERVICE_HPP
#define INTERNET_SERVICE_HPP

#include "UtilityService.hpp"
#include <vector>
#include <string>

using namespace std;

class InternetService : public UtilityService {
protected:
    double dataCapGB;  // Data usage cap in GB
    double overageFeePerGB;  // Overcharge fee for exceeding the data cap
    vector<string> bundledServices;  // Services bundled with the Internet

public:
    InternetService(int pID, double base, double meter, double dataCap, double overageFee)
        : UtilityService("Internet", pID, base, meter), dataCapGB(dataCap), overageFeePerGB(overageFee) {}

    InternetService(const char* name, int pID, double base, double meter)
        : UtilityService(name, pID, base, meter), dataCapGB(0.0), overageFeePerGB(0.0) {}

    virtual ~InternetService() {}

    // Override to calculate the bill based on usage
    double calculateBill(double usage) override {
        double baseCharge = baseRate + (meterRate * usage);
        if (dataCapGB > 0 && usage > dataCapGB) {
            baseCharge += (usage - dataCapGB) * overageFeePerGB;
        }
        return baseCharge;
    }

    // Add bundled services (e.g., streaming services)
    void addBundledService(const string& serviceName) {
        bundledServices.push_back(serviceName);
    }

    bool hasBundledService(const string& serviceName) const {
        for (const auto& service : bundledServices) {
            if (service == serviceName) return true;
        }
        return false;
    }

    double getDataCap() const { return dataCapGB; }
    double getOverageFee() const { return overageFeePerGB; }
};

#endif // INTERNET_SERVICE_HPP

