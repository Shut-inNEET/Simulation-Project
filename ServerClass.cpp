#include "ServerClass.h"

int ServerClass::nextServerID = 1;

ServerClass::ServerClass() {
    serverID = nextServerID++;
    serverStatus = 0;  // Initially free
    transactionTime = 0;
}

int ServerClass::getServerID() const {
    return serverID;
}

void ServerClass::setServerStatus(int status) {
    serverStatus = status;
}

int ServerClass::getServerStatus() const {
    return serverStatus;
}

void ServerClass::setTransactionTime(int time) {
    transactionTime = time;
}

int ServerClass::getTransactionTime() const {
    return transactionTime;
}

void ServerClass::updateTransactionTime() {
    if (transactionTime > 0) {
        transactionTime--;
    }
}

int ServerClass::getCustomerWaitTime() const {
    return customer.getWaitTime();
}

int ServerClass::getCustomerID() const {
    return customer.getCustomerID();
}

void ServerClass::addCustomerToServer(CustomerClass cust) {
    customer = cust;
    serverStatus = 1;  // Set server status to busy
}