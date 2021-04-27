#ifndef ORDER_H
#define ORDER_H

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
	Order(unsigned int uid, unsigned int pid, unsigned int q);
};

#endif