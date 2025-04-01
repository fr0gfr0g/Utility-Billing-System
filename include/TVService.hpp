#ifndef TV_SERVICE_HPP
#define TV_SERVICE_HPP

#include "InternetService.hpp"

using namespace std;

class TVService : public InternetService {
private:
	int channelCount;
	bool hasPremiumChannel;
	double premiumChannelSurcharge = 5.00;

public:
	TVService(int pID, double base, double meter, double dataCap, double overageFee, int channels, bool premium)
		: InternetService("TV Service", pID, base, meter), channelCount(channels), hasPremiumChannel(premium) {}

	//commented out to test the override method
	/*double calculateBill(double dataUsedGB) override {
		double bill = InternetService::calculatedBill(dataUsedGB);

		if (hasPremiumChannel) {
			bill += premiumChannelSurcharge;
		}

		return bill;
	}*/

	double calculateBill() {
		double bill = baseRate;
		if (hasPremiumChannel) {
			bill += channelCount * premiumChannelSurcharge;
		}
		return bill;
	}

	// Getters
	int getChannelCount() const { return channelCount; }
	bool getHasPremiumChannel() const { return hasPremium; }
};

#endif // TV_SERVICE_HPP