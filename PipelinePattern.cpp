#include <iostream>
#include <thread>
#include "product.hpp"
#include "order.hpp"
#include "pipeline.hpp"
#include "user.hpp"
#include "operation.hpp"
#include "CreateOrderProcessor.hpp"
#include "PriceOrderProcessor.hpp"
#include "PaymentOrderProcessor.hpp"
#include "DeliverOrderProcessor.hpp"

bool reportOrder(Order& order) {
	std::string report = order.status == Order::Delivered ? "Success" : "Failed";
	std::cout << "$[IMPORTANT] Order " << order.orderId << " Finished Processing : " << report << std::endl;
	return true;
}


void interactiveRun(Pipeline<Order>& pipeline) {
	std::string username;
	float balance;
	std::cout << "Enter your username" << "\n";
	std::cin >> username;
	std::cout << "Enter your account balance" << "\n";
	std::cin >> balance;
	User dummy(balance);
	int n;
	std::cout << "The following products are available for you to place an order:" << "\n";
	Product::listProducts();
	std::cout << "Enter the number of orders you want to place" << "\n";
	std::cin >> n;
	std::vector<Order> orders;
	for (int i = 1; i <= n; i++) {
		std::cout << "Enter order number " << i << " in the format  <product_id  quantity>" << "\n";
		int id;
		int quantity;
		int user_id = User::users_.back().id;
		std::cin >> id >> quantity;
		orders.push_back(Order(user_id, id, quantity));
	}

	for (int i = 0; i < orders.size(); i++) {
		pipeline.invoke(orders[i]);
	}

	std::this_thread::sleep_for(std::chrono::seconds(100));
}

int main() {   
	Pipeline<Order> pipeline;
	CreateOrderProcessor* cop = new CreateOrderProcessor();
	PriceOrderProcessor* prp = new PriceOrderProcessor();
	PaymentOrderProcessor* pap = new PaymentOrderProcessor();
	DeliverOrderProcessor* dop = new DeliverOrderProcessor();

	pipeline.registerOperation(cop);
	pipeline.registerOperation(prp);
	pipeline.registerOperation(pap);
	pipeline.registerOperation(dop);

	interactiveRun(pipeline);
	
	return 1;
}