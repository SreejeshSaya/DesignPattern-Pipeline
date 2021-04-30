#ifndef OPERATION_H
#define OPERATION_H

#include "ioperation.hpp"
#include <iostream>
#include <functional>

template <typename T> 
class Operation : public IOperation<T> {
private:
	bool (*action)(T&);
	//std::function<bool()> action;
	//bool (IOperation::*)(T&) action;
	IOperation<T> *Next;
	IOperation<T> *Terminate;
public:
	Operation(std::function<bool(T&)> a) {
		action = a;
	}

	void invoke(T& data) {
		IOperation<T> *operation = action(data) ? Next : Terminate;
		if(operation != nullptr) 
			operation->invoke(data);
	}
};

#endif