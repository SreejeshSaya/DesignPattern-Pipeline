#ifndef PAYMENT_ORDER_H
#define PAYMENT_ORDER_H
#include<unordered_map>
#include<iostream>
#include "Processor.hpp"
#include "order.hpp"
#include "user.hpp"

using namespace std;

class PaymentOrderProcessor : public Processor<Order>
{
    private:
    unordered_map<int,float> balances;
    float getBalance(int user) {
        if(balances.find(user) == balances.end()) {
            return 0;

        }
        return balances[user];
    }
    void setBalance(int user, float balance) {
        balances[user] = balance;
    }

    protected:

    bool Process(Order& order) {
        float balance = getBalance(order.userId);
        float expected = balance - order.totalPrice;
        if(expected >= 0) {
            cout<<"Payment Order {"<<order.orderId<<"} User {"<<order.userId<<"} : {"<<order.totalPrice<<"} Rs. | Balance {"<<balance<<"} -> {"<<expected<<"}" << std::endl;
            setBalance(order.userId, expected);
            order.status = Order::Paid;
            return true;
        }
        else {
            cout<<"Insufficient Balance : User {"<<order.userId<<"} Balance {"<<balance<<"} USD | Order {"<<order.orderId<<"} : {"<<order.totalPrice<<"} USD" << std::endl;
            order.status = Order::Canceled;
            return false;
        }
    }

    public:
    PaymentOrderProcessor() 
    {
        for (auto user : User::users_) {
            balances[user.id] = user.initial_balance;
        }
    } 
};



#endif