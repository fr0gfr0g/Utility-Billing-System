#ifndef SEWERAGE_SERVICE_HPP
#define SEWERAGE_SERVICE_HPP

#include "HydroService.hpp"

class SewerageService : public HydroService {
public:
    // Constructor that takes the provider ID, base rate, and per cubic meter rate for sewerage
    SewerageService(int pID, double base, double perCubicMeter)
        : HydroService("Sewerage", pID, base, perCubicMeter) {}

    // Implementing the bill calculation for sewerage, similar other utilities//
    double calculateBill(double usage) override {
        return baseRate + (usage * meterRate);  // Using meterRate as the rate per cubic meter//
    }
};

#endif // SEWERAGE_SERVICE_HPP