#ifndef CUSTOMERCLASS_H
#define CUSTOMERCLASS_H

class CustomerClass {
private:
    static int nextCustomerID;
    int customerID;
    int waitTime;

public:
    CustomerClass();
    int getCustomerID() const;
    void updateWaitTime();
    int getWaitTime() const;
};

#endif