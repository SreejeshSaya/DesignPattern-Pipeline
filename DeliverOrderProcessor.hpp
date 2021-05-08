

#ifndef DELIVER_ORDER_H
#define DELIVER_ORDER_H

#include <iostream>
#include <ctime>
#include<iostream>
#include "Processor.hpp"
#include "order.hpp"

class DeliverOrderProcessor : public Processor<Order> {
protected:
    bool Process(Order& order) {
        order.deliveryTime = std::time(0);
        order.status = Order::Delivered;
        // char deliTime[26];
        // ctime_s(deliTime, 26, &order.deliveryTime);
        char *deliTime;
        deliTime = ctime(&order.deliveryTime);
        deliTime[24] = '\0';
        std::cout << "[DELIVERED] : Order {" << order.orderId << "} Time: " << deliTime << "\n" << std::endl;
        return true;
    }
};

#endif