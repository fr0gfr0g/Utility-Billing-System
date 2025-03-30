#include <iostream>
#include <vector>
#include <string>
#include <map>

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

    // Adding some customers (should be 100)///
    Customer customer1(101, "Jonathan Sins");
    Customer customer2(102, "Mia Cauliflower");

    customerMap[101] = &customer1;
    customerMap[102] = &customer2;

    // user interactions loop, subscribe etc/
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

        if (searchTerm == "Natural Gas") {
        //output options for providers
            cout << "\nMatching Service: Natural Gas" << endl;
            cout << "\nAvailable Providers:" << endl;
            cout << "1. Green Energies (Provider 1)" << endl;
            cout << "2. PowerGas (Provider 2)" << endl;

            // Ask for provider choice between natural gas options
            cout << "\nEnter the number corresponding to the provider: ";
            int providerChoice;
            cin >> providerChoice;
            cin.ignore();  // To ignore the newline character left in the buffer

            Provider* selectedProvider = nullptr;
            if (providerChoice == 1) {
                selectedProvider = &provider1;
            } else if (providerChoice == 2) {
                selectedProvider = &provider2;
            } else {
                cout << "Invalid provider selection!" << endl;
                continue;
            }

            // Display selected provider's service details
            cout << "You selected: " << selectedProvider->providerName << endl;
            for (auto service : selectedProvider->services) {
                service->displayServiceDetails();
            }

            // Now ask for subscription details
            cout << "\nEnter usage in units: ";
            cin >> usage;
            cin.ignore(); // To ignore the newline character

            // Get customer ID for subscription
            cout << "\nEnter Customer ID to subscribe to a service (e.g., 101, 102): ";
            cin >> customerID;
            cin.ignore(); // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];

                if (providerChoice == 1) {
                    customer->addSubscription(&gas1, usage);
                    cout << "Subscription added successfully to Green Energies!" << endl;
                } else if (providerChoice == 2) {
                    customer->addSubscription(&gas2, usage);
                    cout << "Subscription added successfully to PowerGas!" << endl;
                }
            } else {
                cout << "Customer not found!" << endl;
            }
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
        cout << "\nWould you like to check overdue payment for a customer? (yes/no): ";
        getline(cin, action);

        if (action == "yes") {
            cout << "\nEnter Customer ID to check overdue status: ";
            cin >> customerID;
            cin.ignore(); // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->checkOverdue();
            } else {
                cout << "Customer not found!" << endl;
            }
        }
    }

    return 0;
}

