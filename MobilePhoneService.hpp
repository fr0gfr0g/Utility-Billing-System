<<<<<<< Updated upstream
// MobilePhoneService.hpp
=======
#ifndef MOBILEPHONESERVICE_HPP
#define MOBILEPHONESERVICE_HPP

>>>>>>> Stashed changes
#include "InternetService.hpp"

class MobilePhoneService : public InternetService {
private:
<<<<<<< Updated upstream
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
=======
    int minutesIncluded;           // Number of minutes included in the plan
    int textsIncluded;             // Number of text messages included in the plan
    double minuteOverageFee;       // Fee per extra minute used
    double textOverageFee;         // Fee per extra text used

public:
    // Constructor to initialize MobilePhoneService with specific parameters, including minutes and texts
    MobilePhoneService(int pID, double base, double variable, double meter, double dataCap, double overageFee, 
                       int minutes, int texts, double minFee, double textFee)
        : InternetService("Mobile Phone Service", pID, base, variable, meter, dataCap, overageFee), 
          minutesIncluded(minutes), textsIncluded(texts), minuteOverageFee(minFee), textOverageFee(textFee) {}

    // Method to calculate the bill, including data, minute, and text overages
    double calculateBill(double dataUsedGB, int minutesUsed, int textsUsed) const {
        double bill = InternetService::calculateBill(dataUsedGB); // Start with the internet charge

        // Calculate overage charges for minutes
        if (minutesUsed > minutesIncluded) {
            bill += (minutesUsed - minutesIncluded) * minuteOverageFee;
        }

        // Calculate overage charges for texts
        if (textsUsed > textsIncluded) {
            bill += (textsUsed - textsIncluded) * textOverageFee;
        }

        return bill; // Return the total bill including overages
    }

    // Override base calculateBill for compatibility, but no overage charges are added
    double calculateBill(double dataUsedGB) const override {
        // Return bill calculated from InternetService (no overages for minutes/texts)
        return InternetService::calculateBill(dataUsedGB);
    }

    // Getters for included minutes, texts, and overage fees
    int getIncludedMinutes() const { return minutesIncluded; }
    int getIncludedTexts() const { return textsIncluded; }
    double getMinuteOverageFee() const { return minuteOverageFee; }
    double getTextOverageFee() const { return textOverageFee; }
};

#endif // MOBILEPHONESERVICE_HPP
>>>>>>> Stashed changes
