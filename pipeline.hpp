#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>
#include <vector>
#include "ioperation.hpp"
#include "operation.hpp"
#include "order.hpp"

template <typename T>
class Pipeline : public IOperation<T> {
private:
	std::vector<IOperation<T>*> operations;

public:
	Pipeline();
	void registerOperation(IOperation<T>*);
	void invoke(T&);
	void registerCB();
	void terminate();
};

template <typename T>
Pipeline<T>::Pipeline() {}

template <typename T>
void Pipeline<T>::registerOperation(IOperation<T>* operation) {
	if (!operations.empty()) {
		operations.back()->Next = operation;
	}
	operations.push_back(operation);
}

template <typename T>
void Pipeline<T>::invoke(T& data) {
	for (auto operation : operations) {
		operation->Terminate = operations.back();
	}
	operations.back()->Terminate = nullptr;
	IOperation<Order>* op = (!operations.empty()) ? operations.front() : nullptr;
	if (op == nullptr)
		std::cout << "PIPELINE EMPTY!" << std::endl;
	op->invoke(data);
}

template <typename T>
void Pipeline<T>::registerCB() {
	for (auto operation : operations)
		operation->Terminate = operations.back();
	operations.back()->Terminate = nullptr;
}

template <typename T>
void Pipeline<T>::terminate() {
	for (IOperation<T>* operation : operations) {
		operation->terminate();
	}
}

#endif