#include "CustomerClass.h"

using namespace std;

class ServerClass
{
private:
	int serverID = 0;
	int serverStatus; // 0 - free, 1 - busy
	int serverTransactionTime;
	CustomerClass* customer;

public:
	void setServerID()
	{
		serverID++;
	}

	int getServerID()
	{
		return serverID;
	}

	void setServerStatus(int newStatus)
	{
		serverStatus = newStatus;
	}

	int getServerStatus()
	{
		return serverStatus;
	}

	void setTransactionTime(int time)
	{
		serverTransactionTime = time;
	}

	int getTransactionTime()
	{
		return serverTransactionTime;
	}

	void updateServerTransactionTime()
	{
		serverTransactionTime--; 
	}

	int getCustomersWaitTime()
	{
		if (customer != nullptr) 
		{
			return customer->getWaitTime();
		}
		else 
		{
			return 0;
		}
	}

	int getCustomersID()
	{
		if (customer != nullptr) 
		{
			return customer->getCustomerID();
		}
		else 
		{
			return 0; // no customer
		}
	}

	void addCustomerToServer(CustomerClass* cust)
	{
		customer = cust;
		serverStatus = 1;
	}

};

