#include <iostream>
#include <vector>
#include <string>
#include <map>
<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
#include "include/GasService.hpp"
#include "include/InternetService.hpp"
#include "include/MobilePhoneService.hpp"
#include "include/Provider.hpp"
#include "include/Customer.hpp"
>>>>>>> Stashed changes

using namespace std;

// BASE CLASS for UtilityService///
class UtilityService {
protected:
    string serviceName; // variable initializations
    int providerID;     // ID, fixed charge, and per unit charge
    double baseRate;
    double meterRate;

public:
    // Constructor with parameters for service name, provider ID, base rate, and meter rate
    UtilityService(string name, int pID, double base, double meter)
        : serviceName(name), providerID(pID), baseRate(base), meterRate(meter) {}

    // Pure virtual function for billing (must be implemented by derived classes)
    virtual double calculateBill(double usage) = 0;

    // Getter function for returning service name
    string getServiceName() const {
        return serviceName;
    }

    // Display service details
    virtual void displayServiceDetails() {
        cout << "Service: " << serviceName << ", Provider: " << providerID
             << ", Base Rate: $" << baseRate << ", Meter Rate: $" << meterRate << endl;
    }
};

// DERIVED CLASS: GasService
class GasService : public UtilityService {
public:
    // Constructor allows different pricing per provider
    GasService(int pID, double base, double meter)
        : UtilityService("Natural Gas", pID, base, meter) {}

    // Bill calculation formula
    double calculateBill(double usage) override {
        return baseRate + (meterRate * usage);
    }
};

// PROVIDER class
class Provider {
public:
    int providerID;
    string providerName;
    vector<UtilityService*> services;

    Provider(int id, string name) : providerID(id), providerName(name) {}

    void addService(UtilityService* service) {
        services.push_back(service);
    }

    void displayProviderDetails() {
        cout << "Provider ID: " << providerID << ", Name: " << providerName << endl;
        for (auto service : services) {
            service->displayServiceDetails();
        }
    }
};

// CUSTOMER class
class Customer {
public:
    int customerID;
    string customerName;
    vector<pair<UtilityService*, double>> subscribedServices;
    bool isPaymentOverdue = false;

    Customer(int id, string name) : customerID(id), customerName(name) {}

    void addSubscription(UtilityService* service, double usage) {
        subscribedServices.push_back({service, usage});
    }

    void generateBill() {//bill generation//
        cout << "Bill for " << customerName << " (ID: " << customerID << ")" << endl;
        double totalBill = 0;
        for (auto& entry : subscribedServices) {
            double bill = entry.first->calculateBill(entry.second);
            totalBill += bill;
            cout << entry.first->getServiceName() << ": $" << bill << endl;
        }
        cout << "Total Bill: $" << totalBill << endl;
    }

    void checkOverdue(double overdueLimit = 30) {
        if (isPaymentOverdue) {//overdue output//
            cout << "Customer " << customerName << " (ID: " << customerID << ") has overdue payment!" << endl;
        } else {
            cout << "Customer " << customerName << " (ID: " << customerID << ") is up to date with payments." << endl;
        }
    }

    void markAsOverdue() {
        isPaymentOverdue = true;
    }
};

// Main function to interact with the user
int main() {
    //create providers
    Provider provider1(1, "Green Energies");
    Provider provider2(2, "PowerGas");

    //create services with different pricing
    GasService gas1(1, 12.5, 0.04); // Green Energies: lower base and per-unit rate
    GasService gas2(2, 15.0, 0.06); // PowerGas: higher base and per-unit rate

    //assign services to providers//
    provider1.addService(&gas1);
    provider2.addService(&gas2);

    // create a map to store customers by ID for lookup//
    map<int, Customer*> customerMap;

<<<<<<< Updated upstream
    // Adding some customers (should be 100)///
=======
    // Adding some customers (should be 100)
=======
#include "GasService.hpp"
#include "InternetService.hpp"
#include "MobilePhoneService.hpp"
#include "TVService.hpp"
#include "HomePhoneService.hpp"
#include "HydroService.hpp"

using namespace std;

// BASE CLASS for UtilityService
class UtilityService {
protected:
    string serviceName; // Service name
    int providerID;     // Provider ID
    double baseRate;
    double meterRate;

public:
    UtilityService(string name, int pID, double base, double meter)
        : serviceName(name), providerID(pID), baseRate(base), meterRate(meter) {}

    virtual double calculateBill(double usage) = 0;

    string getServiceName() const {
        return serviceName;
    }

    virtual void displayServiceDetails() {
        cout << "Service: " << serviceName << ", Provider: " << providerID
             << ", Base Rate: $" << baseRate << ", Meter Rate: $" << meterRate << endl;
    }
};

// Derived class for GasService
class GasService : public UtilityService {
public:
    GasService(int pID, double base, double meter)
        : UtilityService("Natural Gas", pID, base, meter) {}

    double calculateBill(double usage) override {
        return baseRate + (meterRate * usage);
    }
};

// Derived class for HydroService (Electricity, Water, Sewerage)
class HydroService : public UtilityService {
public:
    HydroService(string name, int pID, double base, double meter)
        : UtilityService(name, pID, base, meter) {}

    double calculateBill(double usage) override {
        return baseRate + (meterRate * usage);
    }

    void displayServiceDetails() override {
        cout << "Hydro Service: " << serviceName << ", Provider ID: " << providerID
             << ", Base Rate: $" << baseRate << ", Meter Rate: $" << meterRate << endl;
    }
};

// Derived class for InternetService
class InternetService : public UtilityService {
protected:
    double dataCap;  // Data usage limit
    double overageFee; // Fee for exceeding data cap

public:
    InternetService(string name, int pID, double base, double meter, double cap, double overage)
        : UtilityService(name, pID, base, meter), dataCap(cap), overageFee(overage) {}

    virtual double calculateBill(double usage) override {
        double bill = baseRate + (meterRate * usage);
        if (usage > dataCap) {
            bill += (usage - dataCap) * overageFee;
        }
        return bill;
    }
};

// Derived class for MobilePhoneService
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
};

// Derived class for TVService
class TVService : public InternetService {
private:
    int channelCount;
    bool hasPremiumChannel;
    double premiumChannelSurcharge = 15.00;

public:
    TVService(int pID, double base, double variable, double meter, double dataCap, double overageFee, int channels, bool premium)
        : InternetService("TV Service", pID, base, variable, meter, dataCap, overageFee), channelCount(channels), hasPremiumChannel(premium) {}

    double calculateBill(double dataUsedGB) const override {
        double bill = InternetService::calculateBill(dataUsedGB);

        if (hasPremiumChannel) {
            bill += premiumChannelSurcharge;
        }

        return bill;
    }
};

// Derived class for HomePhoneService
class HomePhoneService : public InternetService {
private:
    bool includesLongDistance;
    double longDistanceRate;

public:
    HomePhoneService(int pID, double base, double variable, double meter, double dataCap, double overageFee, bool hasLongDistance, double ldRate)
        : InternetService("Home Phone Service", pID, base, variable, meter, dataCap, overageFee), includesLongDistance(hasLongDistance), longDistanceRate(ldRate) {}

    double calculateBill(double dataUsedGB, int longDistanceMinutes = 0) const {
        double bill = InternetService::calculateBill(dataUsedGB);

        if (!includesLongDistance && longDistanceMinutes > 0) {
            bill += longDistanceMinutes * longDistanceRate;
        }

        return bill;
    }
};

// Customer class
class Customer {
public:
    int customerID;
    string customerName;
    vector<pair<UtilityService*, double>> subscribedServices;
    bool isPaymentOverdue = false;

    Customer(int id, string name) : customerID(id), customerName(name) {}

    void addSubscription(UtilityService* service, double usage) {
        subscribedServices.push_back({service, usage});
    }

    void generateBill() {
        cout << "Bill for " << customerName << " (ID: " << customerID << ")" << endl;
        double totalBill = 0;
        for (auto& entry : subscribedServices) {
            double bill = entry.first->calculateBill(entry.second);
            totalBill += bill;
            cout << entry.first->getServiceName() << ": $" << bill << endl;
        }
        cout << "Total Bill: $" << totalBill << endl;
    }

    void checkOverdue() {
        if (isPaymentOverdue) {
            cout << customerName << " (ID: " << customerID << ") has overdue payment!" << endl;
        } else {
            cout << customerName << " (ID: " << customerID << ") is up to date with payments." << endl;
        }
    }

    void markAsOverdue() {
        isPaymentOverdue = true;
    }
};

// Main Function
int main() {
    // Create Providers and Services
    Provider hydroProvider1(3, "Blue Hydro");
    Provider hydroProvider2(4, "AquaPure");

    HydroService electricity1("Electricity", 3, 25.0, 0.13);
    HydroService water1("Water", 3, 10.0, 2.50);
    HydroService sewerage1("Sewerage", 3, 15.0, 0.0);

    HydroService electricity2("Electricity", 4, 30.0, 0.15);
    HydroService water2("Water", 4, 12.0, 2.80);
    HydroService sewerage2("Sewerage", 4, 18.0, 0.0);

    hydroProvider1.addService(&electricity1);
    hydroProvider1.addService(&water1);
    hydroProvider1.addService(&sewerage1);

    hydroProvider2.addService(&electricity2);
    hydroProvider2.addService(&water2);
    hydroProvider2.addService(&sewerage2);

    map<int, Customer*> customerMap;
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    Customer customer1(101, "Jonathan Sins");
    Customer customer2(102, "Mia Cauliflower");

    customerMap[101] = &customer1;
    customerMap[102] = &customer2;

<<<<<<< Updated upstream
    // user interactions loop, subscribe etc/
=======
<<<<<<< Updated upstream
    // User interactions loop, subscribe etc.
=======
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    string searchTerm;
    string action;
    int customerID;
    double usage;

    while (true) {
        cout << "\nEnter the service you want to subscribe to (e.g., 'Natural Gas') or type 'exit' to quit: ";
        getline(cin, searchTerm);

        if (searchTerm == "exit") {
            break;
        }

<<<<<<< Updated upstream
        if (searchTerm == "Natural Gas") {
        //output options for providers
=======
<<<<<<< Updated upstream
        if (searchTerm == "bill") {
            cout << "\nEnter Customer ID to view the bill: ";
            cin >> customerID;
            cin.ignore(); // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                customerMap[customerID]->generateBill();
            } else {
                cout << "Customer not found!" << endl;
            }
        }
        else if (searchTerm == "subscriptions") {
            cout << "\nEnter Customer ID to view subscriptions: ";
            cin >> customerID;
            cin.ignore();  // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                customerMap[customerID]->displaySubscriptions();
            } else {
                cout << "Customer not found!" << endl;
            }
        }
        else if (searchTerm == "Natural Gas") {
            // Output options for providers
>>>>>>> Stashed changes
            cout << "\nMatching Service: Natural Gas" << endl;
            cout << "\nAvailable Providers:" << endl;
            cout << "1. Green Energies (Provider 1)" << endl;
            cout << "2. PowerGas (Provider 2)" << endl;

            // Ask for provider choice between natural gas options
=======
        if (searchTerm == "Natural Gas" || searchTerm == "Electricity" || searchTerm == "Water" || searchTerm == "Sewerage") {
            cout << "\nAvailable Providers:\n";
            cout << "1. Blue Hydro (Provider 3)\n";
            cout << "2. AquaPure (Provider 4)\n";
        
>>>>>>> Stashed changes
            cout << "\nEnter the number corresponding to the provider: ";
            int providerChoice;
            cin >> providerChoice;
            cin.ignore();
        
            Provider* selectedProvider = nullptr;
        
            if (providerChoice == 3) {
                selectedProvider = &hydroProvider1;
            } else if (providerChoice == 4) {
                selectedProvider = &hydroProvider2;
            } else {
                cout << "Invalid provider selection!" << endl;
                continue;
            }
        
            cout << "You selected: " << selectedProvider->providerName << endl;
            for (auto service : selectedProvider->services) {
                service->displayServiceDetails();
            }
        
            cout << "\nEnter usage in units: ";
            cin >> usage;
            cin.ignore();
        
            cout << "\nEnter Customer ID to subscribe to a service: ";
            cin >> customerID;
            cin.ignore();
        
            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
        
                for (auto service : selectedProvider->services) {
                    if (service->getServiceName() == searchTerm) {
                        customer->addSubscription(service, usage);
                        cout << "Subscription added successfully to " << selectedProvider->providerName << "!" << endl;
                    }
                }
            } else {
                cout << "Customer not found!" << endl;
            }
<<<<<<< Updated upstream
        } else {
            cout << "No matching services found." << endl;
        }

        // Bill generation
        cout << "\nWould you like to generate a bill for a customer? (yes/no): ";
        getline(cin, action);

        if (action == "yes") {
            cout << "\nEnter Customer ID to generate bill: (e.g., 101, 102): ";
            cin >> customerID;
            cin.ignore(); // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->generateBill();
            } else {
                cout << "Customer not found!" << endl;
            }
        }

        // Overdue check
=======
<<<<<<< Updated upstream
        }
        else if (searchTerm == "Mobile Phone") {
            cout << "\nAvailable Mobile Phone Providers (Choose 1 or 2):" << endl;
            cout << "1. MobileConnect (Provider 3)" << endl;
            cout << "2. GeckoMobile (Provider 4)" << endl;
            cout << "\nEnter the number corresponding to the provider: ";
            int providerChoice;
            cin >> providerChoice;
            cin.ignore();

            Provider* selectedProvider = (providerChoice == 1) ? &provider3 : (providerChoice == 2) ? &provider4 : nullptr;
            if (!selectedProvider) {
                cout << "Invalid provider selection!" << endl;
                continue;
            }
            selectedProvider->displayProviderDetails();

            cout << "\nEnter minutes used: ";
            cin >> usage;
            cin.ignore();

            cout << "\nEnter Customer ID to subscribe: ";
            cin >> customerID;
            cin.ignore();

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription((providerChoice == 3) ? &mobile1 : &mobile2, usage);
                cout << "Subscription added successfully!\n";
            } else {
                cout << "Customer not found!" << endl;
            }
        }
        else if (searchTerm == "Internet") {
            cout << "\nAvailable Internet Provider: CodeG.Co (Provider 5)" << endl;
            provider5.displayProviderDetails();

            cout << "\nEnter data usage in GB: ";
            cin >> usage;
            cin.ignore();

            cout << "\nEnter Customer ID to subscribe: ";
            cin >> customerID;
            cin.ignore();

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&internet1, usage);
                cout << "Subscription added successfully to CodeG.Co!\n";
            } else {
                cout << "Customer not found!" << endl;
            }
        }
        else {
            cout << "No matching services found." << endl;
        }
=======
        }

>>>>>>> Stashed changes
        cout << "\nWould you like to check overdue payment for a customer? (yes/no): ";
        getline(cin, action);

        if (action == "yes") {
            cout << "\nEnter Customer ID to check overdue status: ";
            cin >> customerID;
<<<<<<< Updated upstream
            cin.ignore(); // To ignore the newline character
=======
            cin.ignore();
>>>>>>> Stashed changes

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->checkOverdue();
            } else {
                cout << "Customer not found!" << endl;
            }
        }
<<<<<<< Updated upstream
=======
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    }

    return 0;
}
