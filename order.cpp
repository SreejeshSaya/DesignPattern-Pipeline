#include "order.hpp"
#include <iostream>

Order::Order(unsigned int uid, unsigned int pid, unsigned int q):
	orderId(++count_), userId(uid), productId(pid), quantity(q), status(New),
	creationTime(time(0)), productPrice(0.0), totalPrice(0.0), deliveryTime(time(0)) {
}

int Order::count_ = 0;