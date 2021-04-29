#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>
#include <vector>
//#include <>
#include "ioperation.hpp"
#include "operation.hpp"
#include "order.hpp"

template <typename T>
class Pipeline : public IOperation<T> {
private:
	IOperation<T> *success;
	IOperation<T> *fail;
	std::vector<T> operations;
	IOperation<T> *Next;
	IOperation<T> *Terminate;
public:
	Pipeline();
	void registerOperation(IOperation<T>*);
	void invoke(T&);
	bool Success(T&);
	bool Fail(T&);
	void Continue(T&);
};


template <typename T>
Pipeline<T>::Pipeline() :
	success(new Operation<Order>(std::bind(&Pipeline::Success, this))),
	fail(new Operation<Order>(&Pipeline::Fail))
{}

template <typename T>
void Pipeline<T>::registerOperation(IOperation<T>* operation) {
	operation.Next = success;
	operation.Terminate = fail;
	if (!operations.empty()) {
		operations.back().Next = operation;
	}
	operations.push_back(operation);
}

template <typename T>
void Pipeline<T>::invoke(T& data) {
	auto operation = !operations.empty() ? operations.front() : fail;
	operation.invoke(data);
}

template <typename T>
bool Pipeline<T>::Success(T& data) {
	Continue(data);
	return true;
}

template <typename T> bool Pipeline<T>::Fail(T& data) {
	Continue(data);
	return false;
}

template <typename T>
void Pipeline<T>::Continue(T& data) {
	if (Next != nullptr) {
		Next.invoke(data);
	}
}

#endif