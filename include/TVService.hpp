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
	TVService(int pID, double base, double meter, int channels, bool premium)
		: InternetService("TV Service", pID, base, meter), channelCount(channels), hasPremiumChannel(premium) {}

	double calculateBill() {
		double bill = baseRate + (meterRate * channelCount);
		if (hasPremiumChannel) {
			bill += premiumChannelSurcharge;
		}
		return bill;
	}

	// Getters
	int getChannelCount() const { return channelCount; }
	bool getHasPremiumChannel() const { return hasPremiumChannel; }
};

#endif // TV_SERVICE_HPP