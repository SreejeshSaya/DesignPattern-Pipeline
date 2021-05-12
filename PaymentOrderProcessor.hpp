#ifndef PAYMENT_ORDER_H
#define PAYMENT_ORDER_H
#include<unordered_map>
#include<iostream>
#include <mutex>
#include "Processor.hpp"
#include "order.hpp"
#include "user.hpp"

class PaymentOrderProcessor : public Processor<Order> {
protected:
    bool Process(Order& order) {
        mtx.lock();
        float balance = User::getBalance(order.userId);
        float expected = balance - order.totalPrice;
        if(expected >= 0) {
            std::cout << "PIPELINE:" << order.pNum << " --- [PAYMENT] : Order { " << order.orderId << "} Price: { " << order.totalPrice << " } Paid ---- Balance { " << expected << " }\n" << std::endl;
            User::updateBalance(order.userId, expected);
            mtx.unlock();
            order.status = Order::Paid;
            return true;
        }
        else {
            mtx.unlock();
            std::cout << "PIPELINE:" << order.pNum << " --- [PAYMENT] FAIL! : Order { " << order.orderId << "} Insufficient Balance for User " << order.userId << ": { " << balance << " } ; Need { " << (-1*expected) << " } more\n" << std::endl;
            order.status = Order::Canceled;
            return false;
        }
    }
};

#endif