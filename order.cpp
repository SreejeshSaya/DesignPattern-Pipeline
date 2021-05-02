#include <iostream>
#include "order.hpp"
#include "product.hpp"

Order::Order(unsigned int uid, unsigned int pid, unsigned int q):
	orderId(++count_), userId(uid), productId(pid), quantity(q), status(New),
	creationTime(time(0)), productPrice(0.0), totalPrice(0.0), deliveryTime(time(0)) {
}

void Order::displayReport() {
	Product* prod = Product::getProduct(productId);
	char createT[26];
	ctime_s(createT, 26, &creationTime);
	createT[24] = '\0';
	char deliT[26];
	ctime_s(deliT, 26, &deliveryTime);
	deliT[24] = '\0';

	std::cout << "Order ID: " << orderId << std::endl;
	if (status != Delivered)
		std::cout << "Order Status: FAILED" << std::endl;
	else
		std::cout << "Order Status: SUCCESS" << std::endl;
	std::cout << "Product Information: " << std::endl;
	prod->getInfo();
	std::cout << "Quantity: " << quantity << std::endl;
	std::cout << "Total Price: " << totalPrice << std::endl;
	std::cout << "Order Created: " << createT << std::endl;
	if (status == Delivered)
		std::cout << "Order Delivered: " << createT << std::endl;
	return;
}

int Order::count_ = 0;