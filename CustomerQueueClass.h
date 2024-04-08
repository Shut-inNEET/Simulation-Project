#ifndef CUSTOMERQUEUECLASS_H
#define CUSTOMERQUEUECLASS_H

#include <queue>
#include "CustomerClass.h"

using namespace std;

class CustomerQueueClass {
private:
    queue<CustomerClass> customerQueue;
    double timeBetweenArrivals;

public:
    int addCustomerToQueue(CustomerClass object);
    CustomerClass removeCustomerFromQueue();
    bool hasCustomerArrived();
    void updateCustomerWaitTime();
    int customersQueued();
    void setTimeBetweenArrival(double time);
    int customerQueueWaitTimeRemaining();
};

#endif