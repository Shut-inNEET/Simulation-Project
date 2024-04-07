#include <iostream>
#include <queue>

#include "ServerClass.h"
#include "CustomerClass.h"
#include "ServerListClass.h"
#include "CustomerQueueClass.h"

using namespace std;

int main() 
{
  // Get inputs
  int numServers;
  int transactionTime;
  int arrivalInterval;
  int simTime;
  
  cin >> numServers >> transactionTime >> arrivalInterval >> simTime;

  // Initialize server list
  ServerListClass serverList;

  // Set transaction parameters
  serverList.setTransactionTime(transactionTime);

  // Allocate server list
  for(int i=0; i<numServers; i++) 
  {
    ServerClass server;
    serverList.addServerToList(server);
  }

  // Initialize customer queue 
  CustomerQueueClass custQueue;

  // Set arrival time parameters 
  custQueue.setTimeBetweenArrival(arrivalInterval);

  // Run simulation
  int totalArrived = 0;
  for(int i=0; i<simTime; i++) 
  {
    // Update server transactions
    auto ids = serverList.updateBusyServerTransactionTime(); 

    // Update customer wait times
    custQueue.updateCustomerWaitTime(); 

    // Check for new customer arrival
    if(custQueue.hasCustomerArrived(i)) 
    {
      CustomerClass cust;
      custQueue.addCustomerToQueue(cust);
      totalArrived++;
    }

    // Assign customer if possible
    int freeServer = serverList.findFreeServer();
    if(freeServer != -1 && custQueue.customersQueued() != 0)
    {
      CustomerClass cust;
      custQueue.removeCustomerFromQueue(); 
      serverList.assignCustomerToServer(&cust);
    }
  }

  // Get total customers served
  int totalServed = serverList.getTotalCustomersServed();

  // Calculate results
  int remaining = custQueue.customersQueued();
  int totalWait = custQueue.customerQueueWaitTimeRemaining(); 
  double avgWait = (double)totalWait / (double)totalServed;

  // Display results
  cout << "Customers Remaining: " << remaining << "\n";
  cout << "Total Customers: " << totalArrived << "\n";
  cout << "Total Served: " << totalServed << "\n";
  cout << "Average Wait: " << avgWait << "\n";

  return 0;
}