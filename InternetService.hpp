// InternetService.hpp
#include "UtilityService.hpp"
#include <vector>

using namespace std;

class InternetService : public UtilityService {
protected:
	double dataCapGB;				// data cap in GB (0 for unlimited)
	double overageFeePerGB;			// fee for each GB over limit
	vector<string> bundledServices; // names of services bundled with this

public:
	// Constructor allows different pricing per provider
	InternetService(string name, int pID, double base, double variable, double meter, double dataCap, double overageFee)
		: UtilityService("Internet", pID, base, meter), dataCapGB(dataCap), overageFeePerGB(overageFee){}

	// Virtual deconstructor
	virtual ~InternetService() {}

	// Method to calculate bill for Internet Service
	double calculateBill(double dataUsedGB) const override {
		double baseCharge = UtilityService::calculateBill(dataUsedGB);

		if (dataCapGB > 0 && dataUsedGB > dataCapGB) {
			double overage = dataUsedGB - dataCapGB;
			baseCharge += overage * overageFeePerGB;
		}

		return baseCharge;
	}

	// Method to add a bundled service (TV, Home Phone, Mobile Phone)
	void addBundledService(string& serviceName) const {
		bundledServices.push_back(serviceName);
	}

	// Method to check if a bundled service is included
	void hasBundledService(string& serviceName) const {
		for (const auto& service : bundledServices) {
			if (service == bundledServices) return true;
		}
		return false;
	}

	// Getter methods
	double getDataCap() const { return dataCapGB; }
	double getOverageFee() const { return overageFeePerGB; }

};