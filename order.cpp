#include <iostream>
#include "order.hpp"
#include "product.hpp"

Order::Order(unsigned int uid, unsigned int pid, unsigned int q, int p):
	orderId(++count_), userId(uid), productId(pid), quantity(q), status(New), pNum(p),
	creationTime(time(0)), productPrice(0.0), totalPrice(0.0), deliveryTime(time(0)) {
}

void Order::displayReport() {
	Product* prod = Product::getProduct(productId);
	char *createT, *deliT;
	createT = ctime(&creationTime);
	deliT = ctime(&deliveryTime);
	createT[24] = '\0';
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