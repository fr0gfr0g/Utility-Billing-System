#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "include/GasService.hpp"
#include "include/InternetService.hpp"
#include "include/MobilePhoneService.hpp"
#include "include/Provider.hpp"
#include "include/Customer.hpp"
#include "include/HomePhoneService.hpp"
#include "include/TVService.hpp"

using namespace std;

// Main function to interact with the user
int main() {
    // Create providers
    Provider provider1(1, "Green Energies");
    Provider provider2(2, "PowerGas");
    Provider provider3(3, "MobileConnect"); // Added MobileConnect provider
    Provider provider4(4, "GeckoMobile"); // Added GeckoMobile provider
    Provider provider5(5, "CodeG.Co"); // Added CodeG.Co

    // Create services with different pricing
    GasService gas1(1, 12.5, 0.04); // Green Energies: lower base and per-unit rate
    GasService gas2(2, 15.0, 0.06); // PowerGas: higher base and per-unit rate
    MobilePhoneService mobile1(3, 25.0, 0.10, 500, 0.05); // Added Mobile Phone Service for MobileConnect
    MobilePhoneService mobile2(4, 30.0, 0.08, 700, 0.04); // Added Mobile Phone Service for GeckoMobile
    InternetService internet1(5, 40.0, 1.5, 200, 3.0); // Added for CodeG.Co
    HomePhoneService home1(5, 20.0, 0.02, true, 0.05); // Added for CodeG.Co
    TVService tv1(5, 30.0, 0.03, 100, true); // Added for CodeG.Co

    // Assign services to providers
    provider1.addService(&gas1);
    provider2.addService(&gas2);
    provider3.addService(&mobile1);
    provider4.addService(&mobile2);
    provider5.addService(&internet1);
    provider5.addService(&home1);
    provider5.addService(&tv1);

    // Create a map to store customers by ID for lookup
    map<int, Customer*> customerMap;

    // Adding some customers (should be 100)
    Customer customer1(101, "Jonathan Sins");
    Customer customer2(102, "Mia Cauliflower");

    customerMap[101] = &customer1;
    customerMap[102] = &customer2;

    // User interactions loop, subscribe etc.
    string searchTerm;
    string action;
    int customerID;
    double usage;

    while (true) {
        cout << "\nEnter the service you want to subscribe to (e.g., 'Natural Gas', 'Mobile Phone', 'Internet') or type 'exit' to quit, 'bill' to view bills, or 'subscriptions' to view subscriptions: ";
        getline(cin, searchTerm);

        if (searchTerm == "exit") {
            break;
        }

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
    }
    return 0;
}

