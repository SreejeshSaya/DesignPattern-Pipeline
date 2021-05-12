#ifndef CREATE_ORDER_H
#define CREATE_ORDER_H

#include <ctime>
#include "Processor.hpp"
#include "order.hpp"
#include <vector>

class CreateOrderProcessor : public Processor<Order> {
protected:
    bool Process(Order& order) {
        order.creationTime = std::time(0);
        order.status = Order::Created;
        char *createT;
        createT = ctime(&order.creationTime);
        createT[24] = '\0';
        std::cout << "[CREATED] : Order {" << order.orderId << "} Time: " << createT << "\n" << std::endl;
        return true;
    }
};

#endif