#ifndef PRICE_ORDER_H
#define PRICE_ORDER_H

class PriceOrderProcessor : public Processor<Order>
{   
    protected:
        bool Process(Order* order)
        {
            float price = getPrice(order->productId);

            order->productPrice = price;
            order->totalPrice = price * order->quantity;
            order->status = OrderStatus.Priced;

            cout << "Create Order {" << order->OrderId << "} Total Price {" << order->totalPrice <<"}" endl;

            return true;
        }

    private:

    float getPrice(int product)
    {
        return Product.getPrice(product);
    }
}


#endif