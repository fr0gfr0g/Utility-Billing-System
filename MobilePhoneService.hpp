// MobilePhoneService.hpp
#include "InternetService.hpp"

class MobilePhoneService : public InternetService {
private:
	int minutesIncluded;
	int textsIncluded;
	double minuteOverageFee;
	double textOverageFee;

public:
	MobilePhoneService(int pID, double base, double variable, double meter, double dataCap, double overageFee, int minutes, int texts, double minFee, double textFee)
		: InternetService("Mobile Phone Service", pID, base, variable, meter, dataCap, overageFee), minutesIncluded(minutes), textsIncluded(texts), minuteOverageFee(minFee), textOverageFee(textFee) {}

	double calculateBill(double dataUsedGB, int minutesUsed, int textsUsed) const {
		double bill = InternetService::calculateBill(dataUsedGB);

		if (minutesUsed > minutesIncluded) {
			bill += (minutesUsed - minutesIncluded) * minuteOverageFee;
		}

		if (textsUsed > textsIncluded) {
			bill += (textsUsed - textsIncluded) * textOverageFee;
		}

		return bill;
	}

	// Override base calculateBill to maintin interface
	double calculatebill(double dataUsedGB) const override {
		// Default to no overage for minutes/texts if not specified
		return InternetService::calculateBill(dataUsedGB);
	}

	// Getters
	int getIncludedMinutes() const { return minutesIncluded; }
	int getIncludedTexts() const { return textsIncluded; }
	double getMinuteOverageFee() const { return minuteOverageFee; }
	double getTextOverageFee() const { return textOverageFee; }
};