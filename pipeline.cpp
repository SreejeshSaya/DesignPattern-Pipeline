#include "pipeline.hpp"
#include "ioperation.hpp"

template <typename T> Pipeline<T>::Pipeline():
	success(new Operation(Success)), fail(new Operation(Fail))
	{}

template <typename T> void Pipeline<T>::RegisterOperation(IOperation<T> operation) {
	operation.Next = success;
	operation.Terminate = fail;
	if (!operations.empty()) {
		operations.back().Next = operation;
	}
	operations.push_back(operation);
}

template <typename T> void Pipeline<T>::invoke(T data) {
	auto operation = !operations.empty() ? operations.front() : fail;
	operation.invoke(data);
}

template <typename T> bool Pipeline<T>::Success(T data) {
	Continue(data);
	return true;
}

template <typename T> bool Pipeline<T>::Fail(T data) {
	Continue(data);
	return false;
}

template <typename T> void Pipeline<T>::Continue(T data) {
	if (Next != nullptr) {
		Next.invoke(data);
	}
}