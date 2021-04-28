

#ifndef DELIVER_ORDER_H
#define DELIVER_ORDER_H
#include <ctime>
#include<iostream>
#include "Processor.hpp"

class DeliverOrderProcessor : public Processor<Order>
{
    protected:
     bool Process(Order* order)
     {
         order->DeliveryTime = time(0);
         order->status = OrderStatus.Delivered;
         std::cout << "Order {" << order->OrderId << "} Delivered : {" << order->DeliveryTime<<"}"<<std::endl;
         return true;
     }
}

#endif