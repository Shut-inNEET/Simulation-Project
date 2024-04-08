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
    // Constructs a new ServerListClass object.
    // Preconditions : numServers and initTransactionTime are positive integers
    // Postconditions : Constructs a new ServerListClass object with the specified number of servers and initial transaction time.
    ServerListClass(int numServers, int initTransactionTime);
    
    // Adds a server to the server list.
    // Preconditions: server is a valid ServerClass object
    // Postconditions : Adds the provided server object to the server list.
    void addServerToList(ServerClass server);
    
    // Finds an available (free) server.
    // Preconditions: None
    // Postconditions : Returns the index of an available(free) server in the server list, or -1 if no server is available.
    int findFreeServer();

    // Sets the transaction time for all servers.
    // Preconditions: time is a non - negative integer
    // Postconditions : Sets the transaction time for all servers in the server list to the provided time value.
    void setTransactionTime(int time);

    // Assigns a customer to an available server.
    // Preconditions: customer is a valid CustomerClass object, and there is at least one available server
    // Postconditions : Assigns the provided customer to an available server in the server list.
    void assignCustomerToFreeServer(CustomerClass customer);

    // Updates the transaction times of busy servers.
    // Preconditions: None
    // Postconditions : Updates the transaction times of all busy servers in the server list. Returns a pair containing the server index and customer ID of any customer whose transaction has completed during this update.
    pair<int, int> updateBusyServerTransactionTimes();

    // Returns the total number of customers served.
    // Preconditions: None
    // Postconditions : Returns the total number of customers who have completed their transactions across all servers in the server list.
    int getTotalCustomersServed() const;

    // Returns the total wait time of customers served.
    // Preconditions: None
    // Postconditions : Returns the total wait time of all customers who have completed their transactions across all servers in the server list.
    int getTotalWaitTime() const;
};

#endif