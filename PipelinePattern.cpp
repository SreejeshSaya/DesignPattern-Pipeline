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


void interactiveRun(Pipeline<Order>& p1, Pipeline<Order>& p2, Pipeline<Order>& p3) {
	std::string username;
	float balance;
	// std::cout << "Username: ";
	std::cin >> username;
	// std::cout << "Account balance: ";
	std::cin >> balance;
	User dummy(username, balance);

	int n;
	int id;
	int quantity;

	// std::cout << "The following products are available for you to place an order:" << "\n";
	// Product::listProducts();
	// std::cout << "\nEnter the number of orders you want to place" << "\n";
	std::cin >> n;
	std::vector<Order> orders1;
	std::vector<Order> orders2;
	std::vector<Order> orders3;
	std::cout << "ORDER FORMAT < ProductID Quantity >" << std::endl;
	std::cout << "PIPELINE 1" << std::endl;
	for (int i = 1; i <= n; i++) {
		std::cout << "Order {" << i << "} : ";
		std::cin >> id >> quantity;
		orders1.push_back(Order(dummy.id, id, quantity, 1));
	}
	
	std::cout << "PIPELINE 2" << std::endl;
	for (int i = n+1; i <= 2*n; i++) {
		std::cout << "Order {" << i << "} : ";
		std::cin >> id >> quantity;
		orders2.push_back(Order(dummy.id, id, quantity, 2));
	}

	std::cout << "PIPELINE 3" << std::endl;
	for (int i = 2*n+1; i <= 3*n; i++) {
		std::cout << "Order {" << i << "} : ";
		std::cin >> id >> quantity;
		orders3.push_back(Order(dummy.id, id, quantity, 3));
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i=0; i< n; ++i) {
		p1.invoke(orders1[i]);
		p2.invoke(orders2[i]);
		p3.invoke(orders3[i]);
	}

	std::this_thread::sleep_for(std::chrono::seconds(orders1.size()*3));
	// p1.terminate();
	// p2.terminate();
	// p3.terminate();
}

int main() {
	// Pipeline<Order> pipeline1;
	// CreateOrderProcessor* cop1 = new CreateOrderProcessor();
	// PriceOrderProcessor* prp1 = new PriceOrderProcessor();
	// PaymentOrderProcessor* pap1 = new PaymentOrderProcessor();
	// DeliverOrderProcessor* dop1 = new DeliverOrderProcessor();
	// ReportOrderProcessor* rop1 = new ReportOrderProcessor();

	Pipeline<Order> pipeline1;
	CreateOrderProcessor* cop1 = new CreateOrderProcessor();
	PriceOrderProcessor* prp1 = new PriceOrderProcessor();
	PaymentOrderProcessor* pap1 = new PaymentOrderProcessor();
	DeliverOrderProcessor* dop1 = new DeliverOrderProcessor();
	ReportOrderProcessor* rop1 = new ReportOrderProcessor();
	
	CreateOrderProcessor* cop2 = new CreateOrderProcessor();
	PriceOrderProcessor* prp2 = new PriceOrderProcessor();
	PaymentOrderProcessor* pap2 = new PaymentOrderProcessor();
	DeliverOrderProcessor* dop2 = new DeliverOrderProcessor();
	ReportOrderProcessor* rop2 = new ReportOrderProcessor();

	CreateOrderProcessor* cop3 = new CreateOrderProcessor();
	PriceOrderProcessor* prp3 = new PriceOrderProcessor();
	PaymentOrderProcessor* pap3 = new PaymentOrderProcessor();
	DeliverOrderProcessor* dop3 = new DeliverOrderProcessor();
	ReportOrderProcessor* rop3 = new ReportOrderProcessor();

	pipeline1.registerOperation(cop1);
	pipeline1.registerOperation(prp1);
	pipeline1.registerOperation(pap1);
	pipeline1.registerOperation(dop1);
	pipeline1.registerOperation(rop1);
	pipeline1.registerCB();

	Pipeline<Order> pipeline2;


	pipeline2.registerOperation(cop2);
	pipeline2.registerOperation(prp2);
	pipeline2.registerOperation(pap2);
	pipeline2.registerOperation(dop2);
	pipeline2.registerOperation(rop2);
	pipeline2.registerCB();

	Pipeline<Order> pipeline3;


	pipeline3.registerOperation(cop3);
	pipeline3.registerOperation(prp3);
	pipeline3.registerOperation(pap3);
	pipeline3.registerOperation(dop3);
	pipeline3.registerOperation(rop3);
	pipeline3.registerCB();

	interactiveRun(pipeline1, pipeline2, pipeline3);
	
	return 1;
}