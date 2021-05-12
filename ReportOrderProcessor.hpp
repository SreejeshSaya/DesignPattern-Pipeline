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
		std::cout << "PIPELINE:" << order.pNum << " --- ACCOUNT DETAILS --- Order { " << order.orderId << " } \n";
		User* user = User::getUser(uid);
		std::cout << "User Details --- ";
		mtx.lock();
		user->displayInfo();
		mtx.unlock();
		std::cout << std::endl;
		return true;
	}
};

#endif