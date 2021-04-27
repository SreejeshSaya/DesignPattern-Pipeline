#ifndef CREATE_ORDER_H
#define CREATE_ORDER_H
#include <ctime>
#include "Processor.hpp"

class CreateOrderProcessor : public Processor<Order>
{
    private:
        std::vector<Order> *v = new std::vector<Order>;

    protected:
        bool Process(Order* order)
        {
            order->OrderId = orders.Count;
            order->CreationTime = DateTime.UtcNow;
            order->Status = OrderStatus.Created;
            orders->Add(order); //what is this?
            cout<<"Create Order {"<<order.OrderId<<"}"<<endl;
            return true;
        }
            

}

#endif