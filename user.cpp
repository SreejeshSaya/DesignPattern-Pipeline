#include<bits/stdc++.h>
#include "user.hpp"
#include "product.hpp"


std::vector<User> User::users_;
User User::Alice((float)1000.00);
User User::Bob((float)1000.00);
User User::Charlie((float)1000.00);


int main()
{   string username;
    long long float balance;
    cout<<"Enter your username"<<"\n";
    cin>>username;
    cout<<"Enter your account balance"<<"\n";
    cin>>balance;
    User dummy(balance);
    int n;
    cout<<"The following products are available for you to place an order:"<<"\n";
    Product::listProducts();
    cout<<"Enter the number of orders you want to place"<<"\n";
    cin>>n;
    vector<Order> orders;
    for(int i=1;i<=n;i++)
    {
        cout << "Enter order number "<<i<<" in the format  <product_id  quantity>"<<"\n";
        int id;
        int quantity;
        int user_id = User::users_.back();
        cin>>id>>quantity;
        
        orders.push_back(Order(user_id,id,quantity));
        

    }
    for(int i=0;i<orders.size();i++)
    {
        pipeline.invoke(orders[i]);
    }
    
       
    


}