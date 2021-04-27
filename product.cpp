#include "product.h"
#include <iostream>

Product::Product(std::string name, float pr):
pName(name), id(count_++), price(pr) {}

void Product::getInfo() {
	std::cout << "ID: " << id << " Name: " << pName << " Price: " << price << std::endl;
}

int Product::count_ = 0;