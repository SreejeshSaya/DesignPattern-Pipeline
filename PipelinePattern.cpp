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
#include "ReportOrderProcessor.hpp"

bool reportOrder(Order& order) {
	std::string report = order.status == Order::Delivered ? "Success" : "Failed";
	std::cout << "$[IMPORTANT] Order " << order.orderId << " Finished Processing : " << report << std::endl;
	return true;
}


void interactiveRun(Pipeline<Order>& pipeline) {
	std::string username;
	float balance;
	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Account balance: ";
	std::cin >> balance;
	User dummy(username, balance);

	int n;
	int id;
	int quantity;

	std::cout << "The following products are available for you to place an order:" << "\n";
	Product::listProducts();
	std::cout << "\nEnter the number of orders you want to place" << "\n";
	std::cin >> n;
	std::vector<Order> orders;
	std::cout << "ORDER FORMAT < ProductID Quantity >" << std::endl;
	for (int i = 1; i <= n; i++) {
		std::cout << "Order {" << i << "} : ";
		std::cin >> id >> quantity;
		orders.push_back(Order(dummy.id, id, quantity));
	}
	
	std::cout << std::endl;

	for(Order o : orders) {
		pipeline.invoke(o);
	}

	std::this_thread::sleep_for(std::chrono::seconds(orders.size()*3));
	pipeline.terminate();
}

int main() {   
	Pipeline<Order> pipeline;
	CreateOrderProcessor* cop = new CreateOrderProcessor();
	PriceOrderProcessor* prp = new PriceOrderProcessor();
	PaymentOrderProcessor* pap = new PaymentOrderProcessor();
	DeliverOrderProcessor* dop = new DeliverOrderProcessor();
	ReportOrderProcessor* rop = new ReportOrderProcessor();

	pipeline.registerOperation(cop);
	pipeline.registerOperation(prp);
	pipeline.registerOperation(pap);
	pipeline.registerOperation(dop);
	pipeline.registerOperation(rop);

	interactiveRun(pipeline);
	
	return 1;
}