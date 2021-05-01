#ifndef PRICE_ORDER_H
#define PRICE_ORDER_H

#include <iostream>
#include "Processor.hpp"
#include "order.hpp"
#include "product.hpp"

class PriceOrderProcessor : public Processor<Order> {
protected:
    bool Process(Order& order) {
        float price = getPrice(order.productId);
        order.productPrice = price;
        order.totalPrice = price * order.quantity;
        order.status = Order::Priced;

        std::cout << "Order {" << order.orderId << "} PROCESSED: total Price -> {" << order.totalPrice << "}" << std::endl;
        return true;
    }

private:
    float getPrice(int product) { return Product::getPrice(product); }
};


#endif