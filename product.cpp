#include "product.hpp"
#include <iostream>

Product::Product(std::string name, float pr):
	pName(name), id(count_++), price(pr) {}

void Product::getInfo() {
	std::cout << "ID: " << id << " Name: " << pName << " Price: " << price << std::endl;
}

int Product::count_ = 0;
Product Product::Apple("Apple", (float)120.00);
Product Product::Banana("Banana", (float)80.00);
Product Product::Orange("Orange", (float)50.00);
Product Product::Pineapple("Pineapple", (float)65.50);