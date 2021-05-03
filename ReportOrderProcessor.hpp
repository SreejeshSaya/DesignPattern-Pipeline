#ifndef REPORT_ORDER_H
#define REPORT_ORDER_H

#include <iostream>
#include "Processor.hpp"
#include "order.hpp"
#include "user.hpp"

class ReportOrderProcessor : public Processor<Order> {
protected:
	bool Process(Order& order) {
		unsigned int uid = order.userId;
		std::cout << "\n--- ORDER { " << order.orderId << " } INVOICE ---" << std::endl;
		User* user = User::getUser(uid);
		std::cout << "User Details --- ";
		user->displayInfo();
		std::cout << "Order Details ---" << std::endl;
		order.displayReport();
		std::cout << std::endl;
		return true;
	}
};

#endif