#ifndef GAS_SERVICE_HPP
#define GAS_SERVICE_HPP

#include "UtilityService.hpp"

using namespace std;

class GasService : public UtilityService {
public:
    // Constructor allows different pricing per provider
    GasService(int pID, double base, double meter)
        : UtilityService("Natural Gas", pID, base, meter) {}

    // Bill calculation formula
    double calculateBill(double usage) override {
        return baseRate + (meterRate * usage);
    }
};

#endif // GAS_SERVICE_HPP