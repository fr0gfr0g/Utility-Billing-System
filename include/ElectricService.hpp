#ifndef ELECTRIC_SERVICE_HPP
#define ELECTRIC_SERVICE_HPP

#include "HydroService.hpp"

class ElectricService : public HydroService {
public:
    // Constructor that takes the provider ID, base rate, and per kilowatt-hour rate
    ElectricService(int pID, double base, double perKWh)
        : HydroService("Electric", pID, base, perKWh) {}

    // Implementing the bill calculation similar to WaterService
    double calculateBill(double usage) override {
        return baseRate + (usage * meterRate);  // Using meterRate as the rate per kWh (kilowatt-hour)
    }
};

#endif // ELECTRIC_SERVICE_HPP