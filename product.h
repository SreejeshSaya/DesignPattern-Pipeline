// NOT CLEAR
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product {
private:
	static int count_;
	string pName;
	int id;
	float price;

public:
	Product(string name, float pr);
	void getInfo();

	float getPrice() { return price; }
	int getID() { return id; }
};

#endif