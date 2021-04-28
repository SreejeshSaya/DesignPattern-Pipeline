#ifndef CREATE_ORDER_H
#define CREATE_ORDER_H

#include <ctime>
#include "Processor.hpp"
#include "order.hpp"
#include <vector>

class CreateOrderProcessor : public Processor<Order>  {
private:
    std::vector<Order>orders;

protected:
    bool Process(Order& order) {
        order.status = Order::Created;
        orders.push_back(order);
        std::cout << "Create Order {" << order.orderId << "}" << std::endl;
        return true;
    }
}

#endif