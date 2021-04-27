#include <iostream>
#include <ctime>

using namespace std;

class Order {
private:
	// OrderStatus.cs
	enum OrderStatus {
        New,
        Created,
        Priced,
        Paid,
        Delivered,
        Canceled
	};
	static int count_;
	int status;
	unsigned int userId;
	unsigned int productId;
	unsigned int quantity;
	float ProductPrice;
	float TotalPrice;
	// Date DeliveryTime;
	// Date CreationTime;
	time_t creationTime;
	time_t deliveryTime;
	unsigned int orderId;

public:
	Order(unsigned int uid, unsigned int pid, unsigned int q):
	orderId(++count_), userId(uid), productId(pid), quantity(q), status(New), creationTime(time(0)) {
		// ProductPrice, TotalPrice, DeliveryTime, Creation time, orderId
	}
};

int Order::count_ = 0;