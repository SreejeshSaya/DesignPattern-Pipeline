// NOT CLEAR

#include <iostream>
using namespace std;

class Product {
private:
	static int count_;
	int id;
	float price;

public:
	Product(float pr) {
		id = count_++;
		price = pr;
	}

	float getPrice() { return price; }
	int getID() { return id; }
};

int Product::count_ = 0;