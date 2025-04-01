<<<<<<< Updated upstream
// TVService.hpp
#include "InternetService.hpp"

using namespace std;

class TVService : public InternetService {
private:
	int channelCount;
	bool hasPremiumChannel;
	double premiumChannelSurcharge = 15.00

public:
	TVService(int pID, double base, double variable, double meter, double dataCap, double overageFee, int channels, bool premium)
		: InternetService("TV Service", pID, base, variable, meter, dataCap, overageFee), channelCount(channels), hasPremiumChannel(premium) {}

	double calculateBill(double dataUsedGB) const override {
		double bill = InternetService::calculatedBill(dataUsedGB);

		if (hasPremiumChannel) {
			bill += premiumChannelSurcharge;
		}

		return bill;
	}

	// Getters
	int getChannelCount() const { return channelCount; }
	bool hasPremium() const { return hasPremium; }
};
=======
#ifndef TVSERVICE_HPP
#define TVSERVICE_HPP

#include "InternetService.hpp"

class TVService : public InternetService {
private:
    int channelCount;                     // Number of channels available in the TV service
    bool hasPremiumChannel;               // Flag for premium channel availability
    double premiumChannelSurcharge = 15.00; // Surcharge for premium channels

public:
    // Constructor to initialize TV service with provider details and channel info
    TVService(int pID, double base, double variable, double meter, double dataCap, double overageFee, int channels, bool premium)
        : InternetService("TV Service", pID, base, variable, meter, dataCap, overageFee), channelCount(channels), hasPremiumChannel(premium) {}

    // Bill calculation considering data usage and premium channel surcharge
    double calculateBill(double dataUsedGB) const override {
        double bill = InternetService::calculateBill(dataUsedGB);  // Base bill calculation from InternetService

        // Add surcharge if the customer has premium channels
        if (hasPremiumChannel) {
            bill += premiumChannelSurcharge;
        }

        return bill;
    }

    // Getter methods
    int getChannelCount() const { return channelCount; }
    bool hasPremium() const { return hasPremiumChannel; }
};

#endif // TVSERVICE_HPP
>>>>>>> Stashed changes
