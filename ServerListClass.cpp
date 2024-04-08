#include "ServerListClass.h"

ServerListClass::ServerListClass(int numServers, int initTransactionTime) {
    serverCount = numServers;
    setTransactionTime(initTransactionTime);
    totalCustomersServed = 0;
    totalWaitTime = 0;

    for (int i = 0; i < numServers; i++) {
        serverList.push_back(ServerClass());
    }
}

void ServerListClass::addServerToList(ServerClass server) {
    serverList.push_back(server);
    serverCount++;
}

int ServerListClass::findFreeServer() {
    for (int i = 0; i < serverCount; i++) {
        if (serverList[i].getServerStatus() == 0) {
            return i;
        }
    }
    return -1;
}

void ServerListClass::setTransactionTime(int time) {
    transactionTime = time;
}

void ServerListClass::assignCustomerToFreeServer(CustomerClass customer) {
    int freeServerIndex = findFreeServer();
    if (freeServerIndex != -1) {
        serverList[freeServerIndex].addCustomerToServer(customer);
        serverList[freeServerIndex].setTransactionTime(transactionTime);
    }
}

pair<int, int> ServerListClass::updateBusyServerTransactionTimes() {
    for (int i = 0; i < serverCount; i++) {
        if (serverList[i].getServerStatus() == 1) {
            serverList[i].updateTransactionTime();
            if (serverList[i].getTransactionTime() == 0) {
                totalCustomersServed++;
                totalWaitTime += serverList[i].getCustomerWaitTime();
                serverList[i].setServerStatus(0);
                return make_pair(serverList[i].getServerID(), serverList[i].getCustomerID());
            }
        }
    }
    return make_pair(-1, -1);
}

int ServerListClass::getTotalCustomersServed() const {
    return totalCustomersServed;
}

int ServerListClass::getTotalWaitTime() const {
    return totalWaitTime;
}