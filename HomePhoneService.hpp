// HomePhoneService.hpp
#include "InternetService.hpp"

class HomePhoneService : public InternetService {
private:
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