// NOT CLEAR
#ifndef PRODUCT_H
#define PRODUCT_H
#include<vector>

class Product 
{
private:
	static int count_;
	std::string pName;
	int id;
	float price;
	static std::vector<Product> *products = new std::vector<Product>;
	

public:
	static Product Apple;
	static Product Banana;
	static Product Orange;
	static Product Pineapple;

	Product(std::string, float);
	void getInfo();

	static float getPrice() { return price; }
	int getID() { return id; }
};

#endif