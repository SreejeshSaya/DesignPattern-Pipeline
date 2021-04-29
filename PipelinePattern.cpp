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
//#include <string>

bool reportOrder(Order& order) {
	std::string report = order.status == Order::Delivered ? "Success" : "Failed";
	std::cout << "$[IMPORTANT] Order " << order.orderId << " Finished Processing : " << report << std::endl;
	return true;
}

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

	//CreateOrderProcessor *cop = new CreateOrderProcessor();
	//PriceOrderProcessor *prp = new PriceOrderProcessor();
	//PaymentOrderProcessor *pap = new PaymentOrderProcessor(User::users_);
	//
	//DeliverOrderProcessor *dop = new DeliverOrderProcessor();
	////IOperation<Order> *dop = new DeliverOrderProcessor();

	//pipeline.registerOperation(cop);
	//pipeline.registerOperation(prp);
	//pipeline.registerOperation(pap);
	//pipeline.registerOperation(dop);

	//Pipeline<Order> monitor;
	//monitor.registerOperation(&pipeline);
	//Operation<Order> *report = new Operation<Order>(&reportOrder);
	//monitor.registerOperation(report);

	//Order o1(1, Product::Pineapple.getID(), 1);
	//monitor.invoke(o1);
	return 1;
}

//#include <iostream>
//#include <functional>
//
//using namespace std::placeholders;
//
//class aClass {
//public:
//    void aTest(int a, int b) {
//        printf("%d + %d = %d", a, b, a + b);
//    }
//};
//
//class bClass {
//public:
//    void function1(std::function<void(int, int)> fun) {
//        fun(1, 1);
//    }
//};
//
//int main(int argc, const char* argv[]) {
//    aClass a;
//    bClass b;
//    auto fp = std::bind(&aClass::aTest, a, _1, _2);
//    b.function1(fp);
//
//    return 0;
//}