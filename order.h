#include <iostream>
#include <ctime>

using namespace std;

class Order {
	// OrderStatus.cs
	enum OrderStatus {
        New,
        Created,
        Priced,
        Paid,
        Delivered,
        Canceled
	};
	static int count;
	int status;
	int userId;
	int productId;
	int quantity;
	float ProcuctPrice;
	float TotalPrice;
	// Date DeliveryTime;
	// Date CreationTime;
	time_t creationTime;
	time_t deliveryTime;
	// unsigned long long int orderId;
	
public:
	Order(int uid, int pid, int q):
	orderId(++count), userId(uid), productId(pid), quantity(q), status(New), creationTime(time(0)) {
		// ProductPrice, TotalPrice, DeliveryTime, Creation time, orderId
	}
};

int Order::count = 0;