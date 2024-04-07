using namespace std;

class CustomerClass
{
private:
    int customerID = 0;
    int waitTime = 0;

public:
	void setCustomerID()
    {
        customerID++;
    }

	int getCustomerID()
    {
        return customerID;
    }

	void updateWaitTime()
    {
        waitTime++;
    }

    int getWaitTime()
    {
        return waitTime;
    }
};