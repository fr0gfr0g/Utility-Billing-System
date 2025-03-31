// Customer.hpp
#include "UtilityService.hpp"
#include <vector>
#include <string>
#include <utility>

class Customer {
private:
	int customerID;
	string customerName;
	vector<pair<UtilityService*, double>> subscribedServices;
	bool isPaymentOverdue = false;

public:
	Customer(int id, string name) : customerID(id), customerName(name) {}

	void addSubscription(UtilityService* service, double usage) {
		subscribedServices.push_back({ service, usage });
	}

	double generateBill() {
		cout << "Bill for " << customerName << " (ID: " << customerID << ")" << endl;
		double totalBill = 0;
		for (auto& entry : subscribedServices) {
			double bill = entry.first->calculateBill(entry.second);
			totalBill += bill;
			cout << entry.first->getServiceName() << ": $" << bill << endl;
		}
		cout << "Total Bill: $" << totalBill << endl;

		return totalBill;
	}

	bool checkOverdue(double overdueLimit = 30) {
		if (isPaymentOverdue) {
			cout << "Customer " << customerName << " (ID: " << customerID << ") has overdue payment!" << endl;
		}
		else {
			cout << "Customer " << customerName << " (ID: " << customerID << ") is up to date with payments." << endl;
		}
		return isPaymentOverdue;
	}

	void markAsOverdue() {
		isPaymentOverdue = true;
	}
};