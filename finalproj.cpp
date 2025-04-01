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
#include "include/WaterService.hpp"
#include "include/ElectricService.hpp"
#include "include/SewerageService.hpp"


using namespace std;

// Main function to interact with the user
int main() {
    // Create providers
    Provider provider1(1, "Green Energies");
    Provider provider2(2, "PowerGas");
    Provider provider3(3, "MobileConnect"); // Added MobileConnect provider
    Provider provider4(4, "GeckoMobile"); // Added GeckoMobile provider
    Provider provider5(5, "CodeG.Co"); // Added CodeG.Co
    Provider provider6(6, "TalkTime"); // Added TalkTime for Home Phone Service
    Provider provider7(7, "DirecX TV"); // Added provider for TV service
    Provider provider8(8, "BigAqua");
    Provider provider9(9, "HamsterElectric");
    Provider provider10(10, "WaterCleaning");

    // Create services with different pricing
    GasService gas1(1, 12.5, 0.04); // Green Energies: lower base and per-unit rate
    GasService gas2(2, 15.0, 0.06); // PowerGas: higher base and per-unit rate
    MobilePhoneService mobile1(3, 25.0, 0.10, 500, 0.05); // Added Mobile Phone Service for MobileConnect
    MobilePhoneService mobile2(4, 30.0, 0.08, 700, 0.04); // Added Mobile Phone Service for GeckoMobile
    InternetService internet1(5, 40.0, 1.5, 200, 3.0); // Added for CodeG.Co
    HomePhoneService homePhone1(6, 20.0, 0.02, true, 0.05); // Added Home Phone Service for TalkTime
    TVService tv1(7, 50.0, 2.0, 100, true); // Added TV Service
    WaterService water1(8, 15.0, 0.03);
    ElectricService electric1(9, 20.0, 0.12);
    SewerageService sewerage1(10, 10.0, 0.02); // Sewerage service

    // Assign services to providers
    provider1.addService(&gas1);
    provider2.addService(&gas2);
    provider3.addService(&mobile1);
    provider4.addService(&mobile2);
    provider5.addService(&internet1);
    provider6.addService(&homePhone1);
    provider7.addService(&tv1); // Assign TV service to provider
    provider8.addService(&water1);       // Adding to a provider (same as other services)
    provider9.addService(&electric1);
    provider10.addService(&sewerage1);

    // Create a map to store customers by ID for lookup
    map<int, Customer*> customerMap;

    //hard coded, but 100 customers via requirements, different id and map. lookup for subscription, bill, etc.
    Customer customer1(101, "Jonathan Sins");
    Customer customer2(102, "Mia Cauliflower");
    Customer customer3(103, "James Black");
    Customer customer4(104, "Samantha Brown");
    Customer customer5(105, "Michael White");
    Customer customer6(106, "Emily Green");
    Customer customer7(107, "Chris Blue");
    Customer customer8(108, "Laura Yellow");
    Customer customer9(109, "David Orange");
    Customer customer10(110, "Sophia Purple");
    Customer customer11(111, "Daniel Gray");
    Customer customer12(112, "Olivia Pink");
    Customer customer13(113, "Matthew Red");
    Customer customer14(114, "Ava Violet");
    Customer customer15(115, "Ethan Indigo");
    Customer customer16(116, "Isabella Lavender");
    Customer customer17(117, "William Mint");
    Customer customer18(118, "Charlotte Peach");
    Customer customer19(119, "Benjamin Magenta");
    Customer customer20(120, "Amelia Rose");
    Customer customer21(121, "Alexander Cherry");
    Customer customer22(122, "Chloe Lemon");
    Customer customer23(123, "Lucas Lime");
    Customer customer24(124, "Lily Plume");
    Customer customer25(125, "Henry Oliver");
    Customer customer26(126, "Mason Peaches");
    Customer customer27(127, "Sophie Cream");
    Customer customer28(128, "Gabriel Sage");
    Customer customer29(129, "Aiden Onyx");
    Customer customer30(130, "Victoria Gold");
    Customer customer31(131, "Jacob Amber");
    Customer customer32(132, "Madison Aqua");
    Customer customer33(133, "Elijah Teal");
    Customer customer34(134, "Harper Scarlet");
    Customer customer35(135, "Sebastian Cobalt");
    Customer customer36(136, "Liam Fuchsia");
    Customer customer37(137, "Grace Ruby");
    Customer customer38(138, "Jayden Silver");
    Customer customer39(139, "Charlotte Topaz");
    Customer customer40(140, "Michael Sapphire");
    Customer customer41(141, "Jack Emerald");
    Customer customer42(142, "Victoria Periwinkle");
    Customer customer43(143, "Isaac Diamond");
    Customer customer44(144, "Madeline Jade");
    Customer customer45(145, "Samuel Crystal");
    Customer customer46(146, "Layla Coral");
    Customer customer47(147, "Maya Garnet");
    Customer customer48(148, "Oliver Copper");
    Customer customer49(149, "Ella Turquoise");
    Customer customer50(150, "Jackie Amethyst");
    Customer customer51(151, "Aaron Brass");
    Customer customer52(152, "Megan Topaz");
    Customer customer53(153, "James Bronze");
    Customer customer54(154, "Paige Pewter");
    Customer customer55(155, "Elena Charcoal");
    Customer customer56(156, "Nathan Silver");
    Customer customer57(157, "Lydia Ruby");
    Customer customer58(158, "Caleb Copper");
    Customer customer59(159, "Eva Emerald");
    Customer customer60(160, "Sophia Pearl");
    Customer customer61(161, "Carter Silver");
    Customer customer62(162, "Zoe Bronze");
    Customer customer63(163, "Wyatt Jade");
    Customer customer64(164, "Eva Copper");
    Customer customer65(165, "Liam Jade");
    Customer customer66(166, "Emma Slate");
    Customer customer67(167, "Emmerett Turquoise");
    Customer customer68(168, "Victoria Amber");
    Customer customer69(169, "Liam Turquoise");
    Customer customer70(170, "Mason Copper");
    Customer customer71(171, "Lily Pearl");
    Customer customer72(172, "William Emerald");
    Customer customer73(173, "Willjamin Amber");
    Customer customer74(174, "Victoria Crystal");
    Customer customer75(175, "Lucas Turquoise");
    Customer customer76(176, "Olivia Ruby");
    Customer customer77(177, "Maya Jade");
    Customer customer78(178, "Khloe Amethyst");
    Customer customer79(179, "Chloe Topaz");
    Customer customer80(180, "Lucas Sapphire");
    Customer customer81(181, "Ethan Garnet");
    Customer customer82(182, "Emily Amethyst");
    Customer customer83(183, "Sophia Emerald");
    Customer customer84(184, "Madison Ruby");
    Customer customer85(185, "Zoey Sapphire");
    Customer customer86(186, "Nathan Onyx");
    Customer customer87(187, "Aiden Crystal");
    Customer customer88(188, "Harper Gold");
    Customer customer89(189, "Aidan Jade");
    Customer customer90(190, "Lillia Emerald");
    Customer customer91(191, "Grace Copper");
    Customer customer92(192, "Wyatt Jade");
    Customer customer93(193, "Elijah Topaz");
    Customer customer94(194, "Victoria Ruby");
    Customer customer95(195, "Jackie Silver");
    Customer customer96(196, "Jacob Garnet");
    Customer customer97(197, "Paige Amethyst");
    Customer customer98(198, "Henry Pearl");
    Customer customer99(199, "Freddie Mars");
    Customer customer100(200, "Lia Venus");

    //customer map for above
    customerMap[101] = &customer1;
    customerMap[102] = &customer2;
    customerMap[103] = &customer3;
    customerMap[104] = &customer4;
    customerMap[105] = &customer5;
    customerMap[106] = &customer6;
    customerMap[107] = &customer7;
    customerMap[108] = &customer8;
    customerMap[109] = &customer9;
    customerMap[110] = &customer10;
    customerMap[111] = &customer11;
    customerMap[112] = &customer12;
    customerMap[113] = &customer13;
    customerMap[114] = &customer14;
    customerMap[115] = &customer15;
    customerMap[116] = &customer16;
    customerMap[117] = &customer17;
    customerMap[118] = &customer18;
    customerMap[119] = &customer19;
    customerMap[120] = &customer20;
    customerMap[121] = &customer21;
    customerMap[122] = &customer22;
    customerMap[123] = &customer23;
    customerMap[124] = &customer24;
    customerMap[125] = &customer25;
    customerMap[126] = &customer26;
    customerMap[127] = &customer27;
    customerMap[128] = &customer28;
    customerMap[129] = &customer29;
    customerMap[130] = &customer30;
    customerMap[131] = &customer31;
    customerMap[132] = &customer32;
    customerMap[133] = &customer33;
    customerMap[134] = &customer34;
    customerMap[135] = &customer35;
    customerMap[136] = &customer36;
    customerMap[137] = &customer37;
    customerMap[138] = &customer38;
    customerMap[139] = &customer39;
    customerMap[140] = &customer40;
    customerMap[141] = &customer41;
    customerMap[142] = &customer42;
    customerMap[143] = &customer43;
    customerMap[144] = &customer44;
    customerMap[145] = &customer45;
    customerMap[146] = &customer46;
    customerMap[147] = &customer47;
    customerMap[148] = &customer48;
    customerMap[149] = &customer49;
    customerMap[150] = &customer50;
    customerMap[151] = &customer51;
    customerMap[152] = &customer52;
    customerMap[153] = &customer53;
    customerMap[154] = &customer54;
    customerMap[155] = &customer55;
    customerMap[156] = &customer56;
    customerMap[157] = &customer57;
    customerMap[158] = &customer58;
    customerMap[159] = &customer59;
    customerMap[160] = &customer60;
    customerMap[161] = &customer61;
    customerMap[162] = &customer62;
    customerMap[163] = &customer63;
    customerMap[164] = &customer64;
    customerMap[165] = &customer65;
    customerMap[166] = &customer66;
    customerMap[167] = &customer67;
    customerMap[168] = &customer68;
    customerMap[169] = &customer69;
    customerMap[170] = &customer70;
    customerMap[171] = &customer71;
    customerMap[172] = &customer72;
    customerMap[173] = &customer73;
    customerMap[174] = &customer74;
    customerMap[175] = &customer75;
    customerMap[176] = &customer76;
    customerMap[177] = &customer77;
    customerMap[178] = &customer78;
    customerMap[179] = &customer79;
    customerMap[180] = &customer80;
    customerMap[181] = &customer81;
    customerMap[182] = &customer82;
    customerMap[183] = &customer83;
    customerMap[184] = &customer84;
    customerMap[185] = &customer85;
    customerMap[186] = &customer86;
    customerMap[187] = &customer87;
    customerMap[188] = &customer88;
    customerMap[189] = &customer89;
    customerMap[190] = &customer90;
    customerMap[191] = &customer91;
    customerMap[192] = &customer92;
    customerMap[193] = &customer93;
    customerMap[194] = &customer94;
    customerMap[195] = &customer95;
    customerMap[196] = &customer96;
    customerMap[197] = &customer97;
    customerMap[198] = &customer98;
    customerMap[199] = &customer99;
    customerMap[200] = &customer100;

    // User interactions loop, subscribe, billing etc.
    string searchTerm;
    string action;
    int customerID;
    double usage;

    while (true) {///ask user for options
        cout << "\nEnter the service you want to subscribe to (e.g., 'Natural Gas', 'Mobile Phone', 'Internet', 'Home Phone', 'TV', 'Water', 'Electricity', 'Sewerage') or'bill' to view customer bills, or 'subscriptions' to view customer subscriptions, 'overdue' to check overdue, or type 'exit' to quit,: ";
        getline(cin, searchTerm);

        if (searchTerm == "exit") {
            break;
        }

        if (searchTerm == "bill") {//view bill for utilities
            cout << "\nEnter Customer ID to view the bill (eg: 101, 102..): ";
            cin >> customerID;
            cin.ignore(); // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                customerMap[customerID]->generateBill();
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }
        else if (searchTerm == "subscriptions") {//list subscriptions based on customer ID
            cout << "\nEnter Customer ID to view subscriptions (eg: 101, 102..): ";
            cin >> customerID;
            cin.ignore();  // To ignore the newline character

            if (customerMap.find(customerID) != customerMap.end()) {
                customerMap[customerID]->displaySubscriptions();
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }
        else if (searchTerm == "overdue") {
            int customerId;
            cout << "Enter customer ID to check if their bill is overdue (eg: 101, 102..): ";
            cin >> customerId;
            cin.ignore();  // To ignore the newline character

            if (customerMap.find(customerId) != customerMap.end()) {
                // Check overdue status
                if (customerMap[customerId]->isPaymentOverdue) {
                    cout << "Customer " << customerMap[customerId]->customerName << " (ID: " << customerId << ") has an overdue payment." << endl;
                }
                else {
                    cout << "Customer " << customerMap[customerId]->customerName << " (ID: " << customerId << ") is up-to-date with payments." << endl;
                }
            }
            else {
                cout << "Customer with ID " << customerId << " not found!" << endl;
            }
        }

        else if (searchTerm == "Home Phone") {//home phone utility subscription
            cout << "\nAvailable Home Phone Provider: TalkTime (Provider 6)" << endl;
            provider6.displayProviderDetails();

            cout << "\nEnter minutes used: ";
            cin >> usage;
            cin.ignore();

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): ";
            cin >> customerID;
            cin.ignore();

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&homePhone1, usage);
                cout << "Subscription added successfully to TalkTime!\n";
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }

        if (searchTerm == "TV") {////tv option///
            cout << "\nAvailable TV Provider: DirecX TV (Provider 7)\n";
            provider7.displayProviderDetails();

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): ";
            cin >> customerID;
            cin.ignore();

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&tv1, 0); // No usage needed for TV subscription
                cout << "Subscription added successfully to StreamPlus TV!\n";
            }
            else {
                cout << "Customer not found!\n";
            }
        }
        else if (searchTerm == "Sewerage") { // Added option for Sewerage
            cout << "\nAvailable Sewerage Provider: CleanWater (Provider 9)" << endl;
            provider9.displayProviderDetails(); // Display WaterCleaning provider's details///

            cout << "\nEnter cubic meters used: "; // Ask user for usage
            cin >> usage;
            cin.ignore();

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): "; // Ask for customer ID
            cin >> customerID;
            cin.ignore();

            // Check if the customer exists in the map
            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&sewerage1, usage); // Add subscription and calculate bill
                cout << "Subscription added successfully to CleanWater Sewerage Service!" << endl;
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }

        else if (searchTerm == "Electricity") {
            cout << "\nAvailable Electric Provider: HamsterElectric (Provider 9)" << endl;
            provider9.displayProviderDetails(); // Display Electric provider details

            cout << "\nEnter kWh used: "; // Ask for electricity usage in kWh
            cin >> usage;
            cin.ignore();

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): "; // Ask for customer ID
            cin >> customerID;
            cin.ignore();

            // Check if customer exists in the map
            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&electric1, usage); // Add electric service subscription
                cout << "Subscription added successfully to PowerElectric Electricity Service!" << endl;
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }

        else if (searchTerm == "Water") {///water hydro option
            cout << "\nAvailable Water Provider: BigAqua (Provider 8)" << endl;
            provider8.displayProviderDetails(); // Display bigaqua provider's details

            cout << "\nEnter cubic meters used: "; // Ask user for usage
            cin >> usage;
            cin.ignore(); // Ignore the newline character

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): "; // Ask for customer ID
            cin >> customerID;
            cin.ignore(); // Ignore the newline character

            // Check if the customer exists in the map
            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&water1, usage); // Add subscription and calculate bill
                cout << "Subscription added successfully to AquaFlow Water Service!" << endl;
            }
            else {
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
            }
            else if (providerChoice == 2) {
                selectedProvider = &provider2;
            }
            else {
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
                }
                else if (providerChoice == 2) {
                    customer->addSubscription(&gas2, usage);
                    cout << "Subscription added successfully to PowerGas!" << endl;
                }
            }
            else {
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

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): ";
            cin >> customerID;
            cin.ignore();

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription((providerChoice == 3) ? &mobile1 : &mobile2, usage);
                cout << "Subscription added successfully!\n";
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }
        else if (searchTerm == "Internet") {
            cout << "\nAvailable Internet Provider: CodeG.Co (Provider 5)" << endl;
            provider5.displayProviderDetails();

            cout << "\nEnter data usage in GB: ";
            cin >> usage;
            cin.ignore();

            cout << "\nEnter Customer ID to subscribe (eg: 101, 102..): ";
            cin >> customerID;
            cin.ignore();

            if (customerMap.find(customerID) != customerMap.end()) {
                Customer* customer = customerMap[customerID];
                customer->addSubscription(&internet1, usage);
                cout << "Subscription added successfully to CodeG.Co!\n";
            }
            else {
                cout << "Customer not found!" << endl;
            }
        }
        else {
            cout << "No matching services found." << endl;
        }
    }
    return 0;
}