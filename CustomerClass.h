#ifndef CUSTOMERCLASS_H
#define CUSTOMERCLASS_H

class CustomerClass {
private:
    static int nextCustomerID;
    int customerID;
    int waitTime;

public:
    // Constructs a new CustomerClass object.
    // Preconditions : None
    // Postconditions : Constructs a new CustomerClass object with default values for waitTime.
    CustomerClass();
    
    // Returns the customer ID.
    // Preconditions : None
    // Postconditions : Returns the customer ID of the current customer object.
    int getCustomerID() const;

    // Increments the wait time.
    // Preconditions: None
    // Postconditions : Increments the wait time of the current customer object by 1 time unit.
    void updateWaitTime();

    // Returns the wait time.
    // Preconditions: None
    // Postconditions : Returns the wait time of the current customer object.
    int getWaitTime() const;
};

#endif