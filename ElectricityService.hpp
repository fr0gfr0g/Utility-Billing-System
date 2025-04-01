#ifndef ELECTRICITYSERVICE_HPP
#define ELECTRICITYSERVICE_HPP

#include "HydroService.hpp"

class ElectricityService : public HydroService {
public:
    ElectricityService(int pID, double base, double meter, double variable)
        : HydroService("Electricity", pID, base, meter, variable) {}

    // Override the bill calculation for Electricity with possible tiered pricing
    double calculateBill(double usage) override {
        return baseRate + (variableRate * usage) + meterRate;  
    }
};

#endif // ELECTRICITYSERVICE_HPP
