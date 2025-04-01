#ifndef SEWERAGESERVICE_HPP
#define SEWERAGESERVICE_HPP

#include "HydroService.hpp"

class SewerageService : public HydroService {
public:
    SewerageService(int pID, double base)
        : HydroService("Sewerage", pID, base, 0.0, 0.0) {} // No meter/variable rates

    // Sewerage might have a flat fee or depend on water usage
    double calculateBill(double waterUsage) override {
        return baseRate; // Flat rate, or modify based on water usage if needed
    }
};

#endif // SEWERAGESERVICE_HPP
