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
    // Adds a new customer to the queue.
    // Preconditions: newCustomer is a valid CustomerClass object
    // Postconditions : Adds the newCustomer to the queue and returns the customer ID of the added customer.
    int addCustomerToQueue(CustomerClass object);

    // Removes a customer from the front of the queue.
    // Preconditions: The queue is not empty
    // Postconditions : Removes and returns the customer at the front of the queue.
    CustomerClass removeCustomerFromQueue();

    // Checks if a new customer has arrived.
    // Preconditions: None
    // Postconditions : Returns true if a new customer has arrived, and false otherwise.
    bool hasCustomerArrived();

    // Updates the wait time of all customers in the queue.
    // Preconditions: None
    // Postconditions : Updates the wait time of all customers in the queue by incrementing their wait time by 1 time unit.
    void updateCustomerWaitTime();

    // Returns the number of customers currently in the queue.
    // Preconditions: None
    // Postconditions : Returns the number of customers currently in the queue.
    int customersQueued();

    // Sets the time between customer arrivals.
    // Preconditions: time is a positive integer
    // Postconditions : Sets the timeBetweenArrivals for the CustomerQueueClass object.
    void setTimeBetweenArrival(double time);

    // Returns the total remaining wait time for customers in the queue.
    // Preconditions: None
    // Postconditions : Returns the total remaining wait time for all customers currently in the queue.
    int customerQueueWaitTimeRemaining();
};

#endif