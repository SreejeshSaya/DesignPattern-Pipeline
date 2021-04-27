#ifndef OPERATION_H
#define OPERATION_H

#include "ioperation.h"

template <typename T> 
class Operation : public IOperation {
private:
	bool *action(T)

public:
	Operation(bool* (act)()):
		action(act) {}

	void invoke(T data) {
		auto operation = *(action)(data) ? next : terminate;
		if(operation != nullptr) 
			operation.invoke(data);
	}
};

#endif