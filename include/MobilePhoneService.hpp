#ifndef MOBILE_PHONE_SERVICE_HPP
#define MOBILE_PHONE_SERVICE_HPP

#include "UtilityService.hpp"

class MobilePhoneService : public UtilityService {
protected:
    double callMinutesCap;
    double overageChargePerMinute;

public:
    MobilePhoneService(int pID, double base, double meter, double cap, double overage)
        : UtilityService("Mobile Phone", pID, base, meter), callMinutesCap(cap), overageChargePerMinute(overage) {}

    double calculateBill(double usage) override {
        double baseCharge = baseRate + (meterRate * usage);
        if (usage > callMinutesCap) {
            baseCharge += (usage - callMinutesCap) * overageChargePerMinute;
        }
        return baseCharge;
    }
};

#endif // MOBILE_PHONE_SERVICE_HPP

