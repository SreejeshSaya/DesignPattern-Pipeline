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
	IOperation<T> *success;
	IOperation<T> *fail;
	std::vector<IOperation<T>*> operations;
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

#endif