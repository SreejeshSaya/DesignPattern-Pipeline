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
        std::cout << "[PROCESSED] : Order {" << order.orderId << "} - Total Price { " << order.totalPrice << " }\n" << std::endl;
        return true;
    }

private:
    float getPrice(int product) { return Product::getPrice(product); }
};


#endif