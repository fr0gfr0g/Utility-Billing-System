// Provider.hpp
#include "UtilityService.hpp"
#include <vector>
#include <string>

class Provider {
private:
    int providerID;
    string providerName;
    vector<UtilityService*> services;

public:
    Provider(int id, string name) : providerID(id), providerName(name) {}

    void addService(UtilityService* service) {
        services.push_back(service);
    }

	int getProviderID() const { return providerID; }
	string getProviderName() const { return providerName; }
	UtilityService* getService(int index) const { return services[index]; }
};