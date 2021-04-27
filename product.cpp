#include "product.h"

Product::Product(string name, float pr):
	pName(name), id(count_++), price(pr) {
}

void Product::getInfo() {
	cout << "ID: " << id << " Name: " << pName << " Price: " << price << endl;
}

int Product::count_ = 0;