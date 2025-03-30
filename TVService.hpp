// TVService.hpp
#include "InternetService.hpp"

using namespace std;

class TVService : public InternetService {
private:
	int channelCount;
	bool hasPremiumChannel;
	double premiumChannelSurcharge = 15.00

public:
	TVService(double base, double variable, double meter, double dataCap, double overageFee, int channels, bool premium)
		: InternetService("TV Service", base, variable, meter, dataCap, overageFee), channelCount(channels), hasPremiumChannel(premium) {}

	double calculateBill(double dataUsedGB) const override {
		double charge = InternetService::calculatedBill(dataUsedGB);

		if (hasPremiumChannel) {
			charge += premiumChannelSurcharge;
		}
	}
};