#include <iostream>
#include <thread>
#include "product.hpp"
#include "order.hpp"
#include "pipeline.hpp"
//#include "user.hpp"
#include "operation.hpp"
#include "CreateOrderProcessor.hpp"
#include "PriceOrderProcessor.hpp"
#include "PaymentOrderProcessor.hpp"
#include "DeliverOrderProcessor.hpp"

int main() {
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
	Pipeline<Order> pipeline;
	CreateOrderProcessor *cop = new CreateOrderProcessor();
	PriceOrderProcessor *prp = new PriceOrderProcessor();
	PaymentOrderProcessor *pap = new PaymentOrderProcessor(User::users_);
	
	DeliverOrderProcessor *dop = new DeliverOrderProcessor();
	//IOperation<Order> *dop = new DeliverOrderProcessor();

	pipeline.registerOperation(cop);
	pipeline.registerOperation(prp);
	pipeline.registerOperation(pap);
	pipeline.registerOperation(dop);

	Pipeline<Order> monitor;
	monitor.registerOperation(&pipeline);
	monitor.registerOperation(new Operation<Order>([](Order &order) {
		string report = order.status == Order::Delivered ? "Success" : "Failed";
		return true;
	}));

	Order o1(1, Product::Pineapple.getID(), 1);
	monitor.invoke(o1);
	return 1;
}