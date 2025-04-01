<<<<<<< Updated upstream
// HomePhoneService.hpp
=======
#ifndef HOMEPHONESERVICE_HPP
#define HOMEPHONESERVICE_HPP

>>>>>>> Stashed changes
#include "InternetService.hpp"

class HomePhoneService : public InternetService {
private:
<<<<<<< Updated upstream
	bool includesLongDistance;
	double longDistanceRate;

public:
	HomePhoneService(int pID, double base, double variable, double meter, double dataCap, double overageFee, bool hasLongDistance, double ldRate)
		: InternetService("Home Phone Service", pID, base, variable, meter, dataCap, overageFee), includesLongDistance(hasLongDistance), longDistanceRate(ldRate) {}

	double calculateBill(double dataUsedGB, int longDistanceMinutes = 0) const {
		double bill = InternetService::calculatedBill(dataUsedGB);

		if (!includesLongDistance && longDistanceMinutes > 0) {
			bill += longDistanceMinutes * longDistanceRate;
		}

		return bill;
	}

	// Override base calculateBill
	double calculateBill(double dataUsedGB) const override {
		return calculateBill(dataUsedGB, 0);
	}

	// Getters
	bool hasLongDistance() const { return includesLongDistance; }
	double getLongDistanceRate() const { return longDistanceRate; }
};
=======
    bool includesLongDistance;   // Indicates if long distance is included in the plan
    double longDistanceRate;     // The rate for long distance calls if not included

public:
    // Constructor to initialize HomePhoneService with specific parameters, including long distance options
    HomePhoneService(int pID, double base, double variable, double meter, double dataCap, double overageFee, 
                     bool hasLongDistance, double ldRate)
        : InternetService("Home Phone Service", pID, base, variable, meter, dataCap, overageFee),
          includesLongDistance(hasLongDistance), longDistanceRate(ldRate) {}

    // Method to calculate bill, including long distance charges if applicable
    double calculateBill(double dataUsedGB, int longDistanceMinutes = 0) const {
        double bill = InternetService::calculateBill(dataUsedGB); // Start with the internet bill

        // If long distance is not included and there are long distance minutes, charge for them
        if (!includesLongDistance && longDistanceMinutes > 0) {
            bill += longDistanceMinutes * longDistanceRate;
        }

        return bill; // Return the total bill
    }

    // Override base calculateBill (no long distance charges in this version)
    double calculateBill(double dataUsedGB) const override {
        return calculateBill(dataUsedGB, 0); // Default to no long distance charges
    }

    // Getters for long distance options
    bool hasLongDistance() const { return includesLongDistance; }
    double getLongDistanceRate() const { return longDistanceRate; }
};

#endif // HOMEPHONESERVICE_HPP
>>>>>>> Stashed changes
