#ifndef OPERATION_H
#define OPERATION_H

#include "ioperation.hpp"

template <typename T> 
class Operation : public IOperation<T> {
private:
	bool* action(T);
	IOperation<T> Next;
	IOperation<T> Terminate;
public:
	void invoke(T data) {
		auto operation = *(action)(data) ? Next : Terminate;
		if(operation != nullptr) 
			operation.invoke(data);
	}
};

#endif