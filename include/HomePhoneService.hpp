#ifndef HOME_PHONE_SERVICE_HPP
#define HOME_PHONE_SERVICE_HPP

#include "InternetService.hpp"

class HomePhoneService : public InternetService {
private:
	bool includesLongDistance;
	double longDistanceRate;

public:
	HomePhoneService(int pID, double base, double meter, double dataCap, double overageFee, bool hasLongDistance, double ldRate)
		: InternetService("Home Phone Service", pID, base, meter), includesLongDistance(hasLongDistance), longDistanceRate(ldRate) {}

	// commented out to test the override method
	/*double calculateBill(double dataUsedGB, int longDistanceMinutes = 0) const {
		double bill = InternetService::calculatedBill(dataUsedGB);

		if (!includesLongDistance && longDistanceMinutes > 0) {
			bill += longDistanceMinutes * longDistanceRate;
		}

		return bill;
	}*/

	double calculateBill(double usage, int longDistanceMinutes = 0) override {
		double bill = baseRate + (meterRate * usage);
		if (longDistanceMinutes > 0) {
			bill += longDistanceMinutes * longDistanceRate;
		}
		return bill;
	}

	// Override base calculateBill
	double calculateBill(double dataUsedGB) override {
		return calculateBill(dataUsedGB, 0);
	}

	// Getters
	bool hasLongDistance() const { return includesLongDistance; }
	double getLongDistanceRate() const { return longDistanceRate; }
};

#endif // HOME_PHONE_SERVICE_HPP