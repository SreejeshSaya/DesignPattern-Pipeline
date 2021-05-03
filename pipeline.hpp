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
	void terminate();
};

#endif