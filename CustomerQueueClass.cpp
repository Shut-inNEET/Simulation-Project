#include "CustomerQueueClass.h"
#include <random>
#include <cmath>
#include <iostream>

using namespace std;

int CustomerQueueClass::addCustomerToQueue(CustomerClass object) {
    customerQueue.push(object);
    return object.getCustomerID();
}

CustomerClass CustomerQueueClass::removeCustomerFromQueue() {
    CustomerClass object = customerQueue.front();
    customerQueue.pop();
    return object;
}

bool CustomerQueueClass::hasCustomerArrived() {
    mt19937 rng(random_device{}());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    double randomNumber = distribution(rng);

    if (randomNumber > exp(-1.0 / timeBetweenArrivals)) {
        return true;
    }
    else {
        return false;
    }
}

void CustomerQueueClass::updateCustomerWaitTime() {
    queue<CustomerClass> tempQueue;

    while (!customerQueue.empty()) {
        CustomerClass object = customerQueue.front();
        customerQueue.pop();

        object.updateWaitTime();

        tempQueue.push(object);
    }
    customerQueue = tempQueue;
}

int CustomerQueueClass::customersQueued() {
    return customerQueue.size();
}

void CustomerQueueClass::setTimeBetweenArrival(double time) {
    timeBetweenArrivals = time;
}

int CustomerQueueClass::customerQueueWaitTimeRemaining() {
    queue<CustomerClass> tempQueue;
    int total = 0;

    while (!customerQueue.empty()) {
        CustomerClass object = customerQueue.front();
        customerQueue.pop();

        tempQueue.push(object);

        total += object.getWaitTime();
    }
    customerQueue = tempQueue;

    return total;
}