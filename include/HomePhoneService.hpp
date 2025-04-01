#ifndef HOME_PHONE_SERVICE_HPP
#define HOME_PHONE_SERVICE_HPP

#include "InternetService.hpp"

class HomePhoneService : public InternetService {
private:
	bool includesLongDistance;
	double longDistanceRate;

public:
	HomePhoneService(int pID, double base, double meter, bool hasLongDistance, double ldRate)
		: InternetService("Home Phone Service", pID, base, meter), includesLongDistance(hasLongDistance), longDistanceRate(ldRate) {}

	double calculateBill(double usage) override {
		double bill = baseRate + (meterRate * usage);
		return bill;
	}

	// Custom function for long-distance calculation (not an override)
	double calculateBillWithLongDistance(double usage, int longDistanceMinutes = 0) {
		double bill = calculateBill(usage); // Base usage calculation
		if (longDistanceMinutes > 0) {
			bill += longDistanceMinutes * longDistanceRate;
		}
		return bill;
	}

	// Getters
	bool hasLongDistance() const { return includesLongDistance; }
	double getLongDistanceRate() const { return longDistanceRate; }
};

#endif // HOME_PHONE_SERVICE_HPP