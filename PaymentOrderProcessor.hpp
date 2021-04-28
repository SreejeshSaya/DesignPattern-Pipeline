#ifndef PAYMENT_ORDER_H
#define PEYMENT_ORDER_H
#include<unordered_map>
#include<iostream>
using namespace std;

class PaymentOrderProcessor : Processor<Order>
{
    private:
    unordered_map<int,float> balances;
    float getBalance(int user)
    {
        if(balances.find(user) == balances.end())
        {
            return 0;

        }
        return balances[user];
    }
    void setBalance(int user, float balance)
    {
        balances[user] = balance;
    }

    protected:

    bool Process(Order& order)
    {
        float balance = getBalance(order.userId);
        float expected = balance - order.totalPrice;
        if(expected >= 0)
        {
            cout<<"Payment Order {"<<order.OrderId<<"} User {"<<order.UserId<<"} : {"<<order.TotalPrice<<"} Rs. | Balance {"<<balance<<"} -> {"<<expected<<"}";
            setBalance(order.userId, expected);
            order.status = OrderStatus.Payed;
            return true;
        }
        else
        {
            cout<<"Insufficient Balance : User {"<<order.userId<<"} Balance {"<<balance<<"} USD | Order {"<<order.orderId<<"} : {"<<order.totalPrice<<"} USD";
            order.status = OrderStatus.Canceled;
            return false;
        }
    }



    public:
    PaymentOrderProcessor(unordered_map<int,float> balances)
    {
           this->balances = balances
    }
    

}






#endif