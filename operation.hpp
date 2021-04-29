#ifndef OPERATION_H
#define OPERATION_H

#include "ioperation.hpp"
#include <iostream>

template <typename T> 
class Operation : public IOperation<T> {
private:
	//bool (*action)(T&);
	std::function<bool()> action;
	IOperation<T> *Next;
	IOperation<T> *Terminate;
public:
	Operation(bool (*a)(T&)) {
		action = a;
	}

	void invoke(T& data) {
		IOperation<T> *operation = action(data) ? Next : Terminate;
		if(operation != nullptr) 
			operation->invoke(data);
	}
};

#endif