#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "CustomerQueueClass.h"
#include "ServerListClass.h"

using namespace std;

int main() {
    int numServers, serverTransactionTime, timeBetweenArrivals, simulationTime;
    int customersArrived = 0;

    cout << "Enter the number of time units for the simulation: ";
    cin >> simulationTime;
    cout << "Enter the number of servers: ";
    cin >> numServers;
    cout << "Enter the server transaction time units: ";
    cin >> serverTransactionTime;
    cout << "Enter time units between customer arrivals: ";
    cin >> timeBetweenArrivals;

    ServerListClass serverList(numServers, serverTransactionTime);
    CustomerQueueClass customerQueue;
    customerQueue.setTimeBetweenArrival(timeBetweenArrivals);

    srand(time(NULL));

    cout << "---------------------------------------------------------------" << endl;

    for (int currentTime = 0; currentTime < simulationTime; currentTime++) {
        pair<int, int> serverCustomerPair = serverList.updateBusyServerTransactionTimes();
        if (serverCustomerPair.first != -1) {
            cout << "From server: " << serverCustomerPair.first << " customer " << serverCustomerPair.second << " departed at time unit " << currentTime << endl;
        }

        customerQueue.updateCustomerWaitTime();

        if (customerQueue.hasCustomerArrived()) {
            CustomerClass newCustomer;
            int newCustomerID = customerQueue.addCustomerToQueue(newCustomer);
            customersArrived++;
            cout << "Customer number: " << newCustomerID << " arrived at time unit: " << currentTime << endl;
        }

        int freeServer = serverList.findFreeServer();
        if (freeServer != -1 && customerQueue.customersQueued() > 0) {
            CustomerClass customer = customerQueue.removeCustomerFromQueue();
            serverList.assignCustomerToFreeServer(customer);
        }
    }

    cout << "---------------------------------------------------------------" << endl;

    int customersLeftInQueue = customerQueue.customersQueued() + 1;
    cout << "Number of customers left in queue: " << customersLeftInQueue << endl;
    cout << "Number of customers that arrived: " << customersArrived << endl;
    cout << "Number of customers who completed a transaction: " << serverList.getTotalCustomersServed() << endl;

    double totalWaitTime = serverList.getTotalWaitTime();
    double averageWaitTime = (double)totalWaitTime / serverList.getTotalCustomersServed();
    cout << "Average wait time for customers in the queue: " << averageWaitTime << endl;

    return 0;
}
