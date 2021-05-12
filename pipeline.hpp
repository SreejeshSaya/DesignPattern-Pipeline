#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>
#include <vector>
#include "ioperation.hpp"
#include "order.hpp"

template <typename T>
class Pipeline {
private:
	IOperation<T>* head;
	IOperation<T>* tail;

public:
	Pipeline();
	void registerOperation(IOperation<T>*);
	void invoke(T&);
	void registerCB();
	void terminate();
};

template <typename T>
Pipeline<T>::Pipeline():
	head(nullptr), tail(nullptr)
{}

template <typename T>
void Pipeline<T>::registerOperation(IOperation<T>* operation) {
	if (head == nullptr) {
		head = operation;
		tail = operation;
	}
	else {
		tail->Next = operation;
		tail = operation;
	}
}

template <typename T>
void Pipeline<T>::invoke(T& data) {
	IOperation<Order>* op = (head != nullptr) ? head : nullptr;
	if (op == nullptr) {
		std::cout << "PIPELINE EMPTY!" << std::endl;
		return;
	}

	op->invoke(data);
}

template <typename T>
void Pipeline<T>::registerCB() {
	IOperation<T> *p = head;
	while(p != nullptr) {
		p->Terminate = tail;
		p = p->Next;
	}
}

template <typename T>
void Pipeline<T>::terminate() {
	IOperation<T> *p = head;
	IOperation<T> *t = head;

	while(p != nullptr) {
		t = p->Next;
		p->terminate();
		p = t;
	}
}

#endif