#ifndef CREATE_ORDER_H
#define CREATE_ORDER_H
#include <ctime>
#include "Processor.hpp"

class CreateOrderProcessor : public Processor<Order>
{
    private:
        std::vector<Order> *orders = new std::vector<Order>;

    protected:
        bool Process(Order* order)
        {
            order->OrderId = orders.size();
            order->CreationTime = time(0);
            order->Status = OrderStatus.Created;
            orders.push_back(order); //what is this?
            cout<<"Create Order {"<<order.OrderId<<"}"<<endl;
            return true;
        }
            

}

#endif
