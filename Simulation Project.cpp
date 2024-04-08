#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "CustomerQueueClass.h"
#include "ServerListClass.h"

using namespace std;

int main() {
    // Declare variables
    int numServers, serverTransactionTime, timeBetweenArrivals, simulationTime;
    int customersArrived = 0;

    // Get user input for simulation parameters
    cout << "Enter the number of time units for the simulation: ";
    cin >> simulationTime;
    cout << "Enter the number of servers: ";
    cin >> numServers;
    cout << "Enter the server transaction time units: ";
    cin >> serverTransactionTime;
    cout << "Enter time units between customer arrivals: ";
    cin >> timeBetweenArrivals;

    // Initialize ServerListClass and CustomerQueueClass objects
    ServerListClass serverList(numServers, serverTransactionTime);
    CustomerQueueClass customerQueue;
    customerQueue.setTimeBetweenArrival(timeBetweenArrivals);

    // Seed the random number generator
    srand(time(NULL));

    cout << "---------------------------------------------------------------" << endl;

    // Simulation loop
    for (int currentTime = 0; currentTime < simulationTime; currentTime++) {
        // Update busy server transaction times
        pair<int, int> serverCustomerPair = serverList.updateBusyServerTransactionTimes();
        if (serverCustomerPair.first != -1) {
            cout << "From server: " << serverCustomerPair.first << " customer " << serverCustomerPair.second << " departed at time unit " << currentTime << endl;
        }

        // Update customer wait times in the queue
        customerQueue.updateCustomerWaitTime();

        // Check if a new customer has arrived
        if (customerQueue.hasCustomerArrived()) {
            CustomerClass newCustomer;
            int newCustomerID = customerQueue.addCustomerToQueue(newCustomer);
            customersArrived++;
            cout << "Customer number: " << newCustomerID << " arrived at time unit: " << currentTime << endl;
        }

        // Find a free server and assign a customer from the queue
        int freeServer = serverList.findFreeServer();
        if (freeServer != -1 && customerQueue.customersQueued() > 0) {
            CustomerClass customer = customerQueue.removeCustomerFromQueue();
            serverList.assignCustomerToFreeServer(customer);
        }
    }

    cout << "---------------------------------------------------------------" << endl;

    // Print simulation statistics
    int customersLeftInQueue = customerQueue.customersQueued() + 1;
    cout << "Number of customers left in queue: " << customersLeftInQueue << endl;
    cout << "Number of customers that arrived: " << customersArrived << endl;
    cout << "Number of customers who completed a transaction: " << serverList.getTotalCustomersServed() << endl;

    double totalWaitTime = serverList.getTotalWaitTime();
    double averageWaitTime = (double)totalWaitTime / serverList.getTotalCustomersServed();
    cout << "Average wait time for customers in the queue: " << averageWaitTime << endl;

    return 0;
}
