#ifndef SERVERLISTCLASS_H
#define SERVERLISTCLASS_H

#include <vector>
#include "ServerClass.h"
#include "CustomerClass.h"

using namespace std;

class ServerListClass {
private:
    vector<ServerClass> serverList;
    int serverCount;
    int transactionTime;
    int totalCustomersServed;
    int totalWaitTime;

public:
    ServerListClass(int numServers, int initTransactionTime);
    void addServerToList(ServerClass server);
    int findFreeServer();
    void setTransactionTime(int time);
    void assignCustomerToFreeServer(CustomerClass customer);
    pair<int, int> updateBusyServerTransactionTimes();
    int getTotalCustomersServed() const;
    int getTotalWaitTime() const;
};

#endif