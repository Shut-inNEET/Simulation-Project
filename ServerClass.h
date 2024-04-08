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
    // Constructs a new ServerClass object.
    // Preconditions : None
    // Postconditions : Constructs a new ServerClass object with a unique serverID, serverStatus set to 0 (free), and transactionTime set to 0.
    ServerClass();

    // Returns the server ID.
    // Preconditions: None
    // Postconditions : Returns the serverID of the current server object.
    int getServerID() const;

    // Sets the server status.
    // Preconditions: status is either 0 (free) or 1 (busy)
    // Postconditions : Sets the serverStatus of the current server object to the provided status value.
    void setServerStatus(int status);

    // Returns the server status.
    // Preconditions: None
    // Postconditions : Returns the serverStatus of the current server object.
    int getServerStatus() const;

    // Sets the transaction time.
    // Preconditions: time is a non - negative integer
    // Postconditions : Sets the transactionTime of the current server object to the provided time value.
    void setTransactionTime(int time);
    
    // Returns the transaction time.
    // Preconditions: None
    // Postconditions : Returns the transactionTime of the current server object.
    int getTransactionTime() const;

    // Updates the transaction time.
    // Preconditions: None
    // Postconditions : Decrements the transactionTime of the current server object by 1 if it is greater than 0.
    void updateTransactionTime();
    
    // Returns the customer's wait time.
    // Preconditions: A customer is assigned to the server
    // Postconditions : Returns the wait time of the customer assigned to the current server object.
    int getCustomerWaitTime() const;

    // Returns the customer's ID.
    // Preconditions: A customer is assigned to the server
    // Postconditions : Returns the customer ID of the customer assigned to the current server object.
    int getCustomerID() const;
    
    // Assigns a customer to the server.
    // Preconditions: cust is a valid CustomerClass object
    // Postconditions : Assigns the provided customer(cust) to the current server object and sets the serverStatus to 1 (busy).
    void addCustomerToServer(CustomerClass cust);
};

#endif