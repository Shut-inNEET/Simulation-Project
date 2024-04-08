#ifndef SERVERCLASS_H
#define SERVERCLASS_H

#include "CustomerClass.h"

class ServerClass {
private:
    static int nextServerID;
    int serverID;
    int serverStatus;  // 0 - free, 1 - busy
    int transactionTime;
    CustomerClass customer;

public:
    ServerClass();
    int getServerID() const;
    void setServerStatus(int status);
    int getServerStatus() const;
    void setTransactionTime(int time);
    int getTransactionTime() const;
    void updateTransactionTime();
    int getCustomerWaitTime() const;
    int getCustomerID() const;
    void addCustomerToServer(CustomerClass cust);
};

#endif
