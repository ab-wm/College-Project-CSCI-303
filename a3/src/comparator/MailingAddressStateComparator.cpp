#include <comparator/MailingAddressStateComparator.h>
#include <entity/MailingAddress.h>

bool MailingAddressStateComparator::lessThan(MailingAddress &ma1, MailingAddress &ma2) {
    // By-state order: first by state, then by street, then by city, and then by zip code.
    // At each step, account for equality
    if (ma1.getState() == ma2.getState()) {
        if (ma1.getStreet() == ma2.getStreet()) {
            if (ma1.getCity()== ma2.getCity()) {
                return ma1.getZipCode() < ma2.getZipCode();
            }
            return ma1.getCity() < ma2.getCity();
        }
        return ma1.getStreet() < ma2.getStreet();
    }
    return ma1.getState() < ma2.getState();
}

bool MailingAddressStateComparator::equals(MailingAddress &ma1, MailingAddress &ma2) {
    if (ma1.getState() != ma2.getState()) return false;
    if (ma1.getStreet() != ma2.getStreet()) return false;
    if (ma1.getCity() != ma2.getCity()) return false;
    return ma1.getZipCode() == ma2.getZipCode();
}