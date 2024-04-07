#include <queue>
#include <random>
#include "math.h"
#include "CustomerClass.h"

using namespace std;

class CustomerQueueClass
{
private:
	queue<CustomerClass> customerQueue;
	double timeBetweenArrivals;

public:
	int addCustomerToQueue(CustomerClass object)
	{
		customerQueue.push(object);
		return object.getCustomerID();
	}

	CustomerClass removeCustomerFromQueue()
	{
		CustomerClass object = customerQueue.front();
		customerQueue.pop(); 
		return object;
	}

	bool hasCustomerArrived()
	{
		mt19937 rng(random_device{}());
		uniform_int_distribution<double> distribution(0, 1);
		int randomNumber = distribution(rng);

		if (randomNumber > exp(-1 / timeBetweenArrivals))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void updateCustomerWaitTime()
	{
		queue<CustomerClass> tempQueue;

		while (!customerQueue.empty()) 
		{
			CustomerClass object = customerQueue.front();
			customerQueue.pop();

			object.updateWaitTime();

			tempQueue.push(object);
		}
		customerQueue = tempQueue;
	}

	int customersQueued()
	{
		return customerQueue.size();
	}

	void setTimeBetweenArrival(int time)
	{
		timeBetweenArrivals = time;
	}

	int customerQueueWaitTimeRemaining()
	{
		queue<CustomerClass> tempQueue;
		int total = 0;

		while (!customerQueue.empty()) 
		{
			CustomerClass object = customerQueue.front();
			customerQueue.pop();

			tempQueue.push(object);

			total += object.getWaitTime();
		}
		customerQueue = tempQueue;

		return total;
	}
};

