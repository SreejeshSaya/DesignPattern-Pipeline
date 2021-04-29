

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
        order.deliveryTime = time(0);
        order.status = Order::Delivered;
        std::cout << "Order {" << order.orderId << "} Delivered : {" << order.deliveryTime << "}" << std::endl;
        return true;
    }
};

#endif