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
//#include <string>

bool reportOrder(Order& order) {
	std::string report = order.status == Order::Delivered ? "Success" : "Failed";
	std::cout << "$[IMPORTANT] Order " << order.orderId << " Finished Processing : " << report << std::endl;
	return true;
}


void interactiveRun(Pipeline<Order> &pipeline) {
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
	

	
	for (int i = 0; i<orders.size(); i++) {
		pipeline.invoke(orders[i]);
	}
	std::this_thread::sleep_for(std::chrono::seconds(100));
}

int main() 
{   
	Pipeline<Order> pipeline;
	CreateOrderProcessor* cop = new CreateOrderProcessor();
	PriceOrderProcessor* prp = new PriceOrderProcessor();
	PaymentOrderProcessor* pap = new PaymentOrderProcessor();
	DeliverOrderProcessor* dop = new DeliverOrderProcessor();
	//IOperation<Order> *dop = new DeliverOrderProcessor();

	pipeline.registerOperation(cop);
	pipeline.registerOperation(prp);
	pipeline.registerOperation(pap);
	pipeline.registerOperation(dop);
	interactiveRun(pipeline);
	//std::cout << "Hello World\n";
	///*Product::Apple.getInfo();
	//Product::Banana.getInfo();
	//Product::Orange.getInfo();
	//Product::Pineapple.getInfo */

	//Product::listProducts();
	//Order o1(1, 1, 2);
	//std::cout << o1.orderId << " " << o1.userId << " " << o1.status << " " << o1.creationTime << std::endl;
	//

	// Test.cs
	//Pipeline<Order> pipeline;

	//CreateOrderProcessor* cop = new CreateOrderProcessor();
	//PriceOrderProcessor* prp = new PriceOrderProcessor();
	//PaymentOrderProcessor* pap = new PaymentOrderProcessor(User::users_);
	//

	//DeliverOrderProcessor* dop = new DeliverOrderProcessor();
	////IOperation<Order> *dop = new DeliverOrderProcessor();

	//pipeline.registerOperation(cop);
	//pipeline.registerOperation(prp);
	//pipeline.registerOperation(pap);
	//pipeline.registerOperation(dop);''

	//Pipeline<Order> monitor;
	//monitor.registerOperation(&pipeline);
	//Operation<Order> *report = new Operation<Order>(&reportOrder);
	//monitor.registerOperation(report);

	//Order o1(1, Product::Pineapple.getID(), 1);
	//Order o2(2, Product::Apple.getID(), 1);
	//Order o3(1, Product::Pineapple.getID(), 1);
	//Order o4(2, Product::Orange.getID(), 1);
	//Order o5(1, Product::Pineapple.getID(), 1);

	//pipeline.invoke(o1);
	//pipeline.invoke(o2);
	//pipeline.invoke(o3);
	//pipeline.invoke(o4);
	//pipeline.invoke(o5);
	////monitor.invoke(o1);
	//std::this_thread::sleep_for(std::chrono::seconds(100));

	
	return 1;
}