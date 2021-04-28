// NOT CLEAR
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {
private:
	static int count_;
	std::string pName;
	int id;
	float price;
	vector<Product> products* = 

public:
	static Product Apple;
	static Product Banana;
	static Product Orange;
	static Product Pineapple;

	Product(std::string, float);
	void getInfo();

	float getPrice() { return price; }
	int getID() { return id; }
};

#endif