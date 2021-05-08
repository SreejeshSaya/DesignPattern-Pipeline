#ifndef PAYMENT_ORDER_H
#define PAYMENT_ORDER_H
#include<unordered_map>
#include<iostream>
#include "Processor.hpp"
#include "order.hpp"
#include "user.hpp"

class PaymentOrderProcessor : public Processor<Order> {
protected:
    bool Process(Order& order) {
        float balance = User::getBalance(order.userId);
        float expected = balance - order.totalPrice;
        if(expected >= 0) {
            //std::cout << "Payment Order {" << order.orderId << "} User {" << order.userId << "} : {" << order.totalPrice << "} Rs. | Balance {" << balance << "} -> {" << expected << "}\n" << std::endl;
            std::cout << "[PAYMENT] : Order {" << order.orderId << "} Paid\n" << std::endl;

            User::updateBalance(order.userId, expected);
            order.status = Order::Paid;
            return true;
        }
        else {
            std::cout << "[PAYMENT] FAIL! : Order {" << order.orderId << "} Insufficient Balance for User " << order.userId << ": { " << balance << " } ; Need { " << (-1*expected) << " } more\n" << std::endl;
            //std::cout<<"Insufficient Balance : User {"<<order.userId<<"} Balance {"<<balance<<"} USD | Order {"<<order.orderId<<"} : {"<<order.totalPrice<<"} USD\n" << std::endl;
            order.status = Order::Canceled;
            return false;
        }
    }
};

#endif