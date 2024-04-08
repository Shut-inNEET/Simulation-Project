#include "CustomerClass.h"

int CustomerClass::nextCustomerID = 0;

CustomerClass::CustomerClass() {
    customerID = nextCustomerID++;
    waitTime = 0;
}

int CustomerClass::getCustomerID() const {
    return customerID;
}

void CustomerClass::updateWaitTime() {
    waitTime++;
}

int CustomerClass::getWaitTime() const {
    return waitTime;
}