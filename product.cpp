#include "product.hpp"
#include <iostream>

Product::Product(std::string name, float pr):
	pName(name), id(count_++), price(pr) 
{
     products_.push_back(*this);
}

void Product::getInfo() {
	std::cout << "ID: " << id << " Name: " << pName << " Price: " << price << std::endl;
}

void Product::listProducts() {
	for (auto p : products_)
		p.getInfo();
}

Product* Product::getProduct(unsigned int pid) {
	if (pid >= products_.size())
		return nullptr;
	return &products_[pid];
}

int Product::count_ = 0;
std::vector<Product> Product::products_;

Product Product::Apple("Apple", (float)120.00);
Product Product::Banana("Banana", (float)80.00);
Product Product::Orange("Orange", (float)50.00);
Product Product::Pineapple("Pineapple", (float)65.50);
