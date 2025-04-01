#ifndef WATER_SERVICE_HPP
#define WATER_SERVICE_HPP

#include "HydroService.hpp"

class WaterService : public HydroService {
public:
    // Constructor that takes the provider ID, base rate, and per cubic meter rate
    WaterService(int pID, double base, double perCubicMeter)
        : HydroService("Water", pID, base, perCubicMeter) {}

    // Implementing the bill calculation similar to GasService
    double calculateBill(double usage) override {
        return baseRate + (usage * meterRate);  // Using meterRate as the rate per cubic meter
    }
};

#endif // WATER_SERVICE_HPP