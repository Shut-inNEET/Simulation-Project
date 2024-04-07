#include <vector>
#include "ServerClass.h"
#include "CustomerClass.h"

using namespace std;

class ServerListClass
{
private:
	vector<ServerClass> serverList;
	int serverCount;
	int transactionTime;
	int totalServed;
	int totalWaitTime;

public:
	void addServerToList(ServerClass server)
	{
		serverList.push_back(server);
	}

	int findFreeServer() 
	{
		for (int i = 0; i < serverList.size(); i++) 
		{
			if (servers[i].getStatus() == 0) 
			{
				return i;
			}
		}
		return -1;
	}

	void setTransactionTime(int time) 
	{
		transactionTime = time;
	}

	void assignCustomerToServer(CustomerClass* cust) 
	{
		serverList[findFreeServer()].addCustomerToServer(cust);
	}

	int updateBusyServerTransactionTime()
	{
		for (ServerClass& server : serverList) 
		{
			if (server.getServerStatus() == 1 && server.getTransactionTime() == 0) 
			{
				CustomerClass* cust = server.getCustomersID();
				totalServed++;
				totalWaitTime += cust->getWaitTime();

				server.setServerStatus(0);
				int id = server.getServerID(); 
				int custId = cust->getCustomerID(); 
				return id;
			}
			else if (server.getServerStatus() == 1) 
			{
				server.updateServerTransactionTime(); 
			}
		}
	}

	int getTotalCustomersServed() 
	{
		return totalServed;
	}

	int getTotalWaitTimesofCustomerServered()
	{
		return totalWaitTime;
	}
};

