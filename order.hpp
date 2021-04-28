#ifndef ORDER_H
#define ORDER_H

#include <ctime>

class Order {
private:
	static int count_;

public:
	// OrderStatus.cs
	static enum OrderStatus {
		New,
		Created,
		Priced,
		Paid,
		Delivered,
		Canceled
	};
	unsigned int orderId;
	int status;
	unsigned int userId;
	unsigned int productId;
	unsigned int quantity;
	float productPrice;
	float totalPrice;
	time_t creationTime;
	time_t deliveryTime;

	Order(unsigned int, unsigned int, unsigned int);
};

#endif