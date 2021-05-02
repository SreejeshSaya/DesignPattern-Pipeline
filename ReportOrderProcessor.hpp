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
		std::cout << "--- ORDER INVOICE ---" << std::endl;
		User* user = User::getUser(uid);
		std::cout << "User Details ---" << std::endl;
		user->displayInfo();
		std::cout << "Order Details ---" << std::endl;
		order.displayReport();
		return true;
	}
};

#endif