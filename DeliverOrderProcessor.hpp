

#ifndef DELIVER_ORDER_H
#define DELIVER_ORDER_H

class DeliverOrderProcessor : public Processor<Order>
{
    protected:
     bool Process(Order* order)
     {
         order->DeliveryTime = time(0);
         order->status = OrderStatus.Delivered;
         cout << "Order {" << order->OrderId << "} Delivered : {" << order->DeliveryTime<<"}"<<endl;
         return true;
     }
}


#endif
