#ifndef MAILINGADDRESSSTATECOMPARATOR_H
#define MAILINGADDRESSSTATECOMPARATOR_H

#include <comparator/Comparator.h>
#include <entity/MailingAddress.h>

class MailingAddressStateComparator : public Comparator<MailingAddress> {
  // Returns true if ma1 is less than ma2, comparing first by state
  bool lessThan(MailingAddress &ma1 , MailingAddress& ma2) override;

  // Returns true if ma1 is equal to ma2, comparing first by state
  bool equals(MailingAddress &ma1 , MailingAddress& ma2) override;
};

#endif //MAILINGADDRESSSTATECOMPARATOR_H
