#ifndef ORDER_H
#define ORDER_H

#include <ctime>

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

	unsigned int orderId;
	int status;
	unsigned int userId;
	unsigned int productId;
	unsigned int quantity;
	float productPrice;
	float totalPrice;
	time_t creationTime;
	time_t deliveryTime;

public:
	Order(unsigned int, unsigned int, unsigned int);
};

#endif