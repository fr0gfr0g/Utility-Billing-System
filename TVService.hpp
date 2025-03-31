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
			charge += premiumChannelSurcharge;
		}
	}

	// Getters
	int getChannelCount() const { return channelCount; }
	bool hasPremium() const { return hasPremium; }
};