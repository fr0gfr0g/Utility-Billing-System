<<<<<<< Updated upstream:GasService.hpp
// GasService.hpp
=======
<<<<<<< Updated upstream:include/GasService.hpp
#ifndef GAS_SERVICE_HPP
#define GAS_SERVICE_HPP

>>>>>>> Stashed changes:include/GasService.hpp
#include "UtilityService.hpp"
=======
#ifndef GASSERVICE_HPP
#define GASSERVICE_HPP
>>>>>>> Stashed changes:GasService.hpp

#include "UtilityService.hpp"

class GasService : public UtilityService {
public:
    // Constructor for GasService class which initializes with provider ID, base rate, and meter rate.
    GasService(int pID, double base, double meter)
        : UtilityService("Natural Gas", pID, base, 0.0, meter) {}  // No variable rate for GasService

    // Method to calculate the bill based on gas usage.
    // It adds the base rate and the meter rate for the given usage.
    double calculateBill(double usage) override {
        return baseRate + (meterRate * usage);  // Total bill = base rate + (usage * meter rate)
    }
<<<<<<< Updated upstream:GasService.hpp
};
=======
};

<<<<<<< Updated upstream:include/GasService.hpp
#endif // GAS_SERVICE_HPP
=======
#endif // GASSERVICE_HPP
>>>>>>> Stashed changes:GasService.hpp
>>>>>>> Stashed changes:include/GasService.hpp
