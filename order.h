#include <iostream>
using namespace std;

class Order {
	// OrderStatus.cs
	enum OrderStatus {
        New,
        Created,
        Priced,
        Paid,
        Delivered,
        Canceled
	};

	int status;
	int userId;
	int productId;
	int quantity;
	float ProcuctPrice;
	float TotalPrice;
	// Date DeliveryTime;
	// Date CreationTime;
	// unsigned long long int orderstatus;
	
public:
	Order(int uid, pid, q):
	userId(uid), productId(pid), quantity(q), status(New) {
		// ProductPrice, TotalPrice, DeliveryTime, Creation time, orderId
	}
};
